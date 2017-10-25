#include "Arduino.h"
//these functions set the pin settings for each of the four steps per rotation of the motor (keepp in mind that the motor in the kit is geared down,
//i.e. there are many steps necessary per rotation

void Step_A(){
  digitalWrite(pin1, HIGH);//turn on coil 1 
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, LOW); 
}
void Step_B(){
  digitalWrite(pin1, LOW); 
  digitalWrite(pin2, HIGH);//turn on coil 2
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, LOW); 
}
void Step_C(){
  digitalWrite(pin1, LOW); 
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, HIGH); //turn on coil 3
  digitalWrite(pin4, LOW); 
}
void Step_D(){
  digitalWrite(pin1, LOW); 
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, HIGH); //turn on coil 4
}
void step_OFF()
{
  digitalWrite(pin1, LOW); //power all coils down
  digitalWrite(pin2, LOW); 
  digitalWrite(pin3, LOW); 
  digitalWrite(pin4, LOW); 
}

//these functions run the above configurations in forward and reverse order
//the direction of a stepper motor depends on the order in which the coils are turned on.
void forward(){//one tooth forward
  Step_A();
  delay(delaytime);
  Step_B();
  delay(delaytime);
  Step_C();
  delay(delaytime);
  Step_D();
  delay(delaytime);
}

void backward(){//one tooth backward
  Step_D();
  delay(delaytime);
  Step_C();
  delay(delaytime);
  Step_B();
  delay(delaytime);
  Step_A();
  delay(delaytime);
}


void step_open() {
  /* Opens the door. We need to experimentally calculate how many steps it takes to open/close the door
     Once we have that, numberOfSteps could probably be stated in the function below, since it's always the same.
  */
  int numberOfSteps = doorSteps;
  step_OFF();         //turning all coils off
  while (numberOfSteps > 0) {
    forward();        //going forward
    numberOfSteps -- ;
  }
}

void step_close() {

  /* Closes the door
     Same as step_open(), but with backward, instead of forward. Could probably make this one function to be more efficient
  */
  int numberOfSteps = doorSteps;
  step_OFF();         //turning all coils off
  while (numberOfSteps > 0) {
    backward();        //going forward
    numberOfSteps -- ;
  }
}

