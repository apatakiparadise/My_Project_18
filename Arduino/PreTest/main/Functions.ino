/* Here we list all functions to be implemented in our code, 
 * with docstrings to explain what it does, what parameters it has and what it returns 
 */
void import_statements_etc(){
  //this goes in the top of the main function, before setup()
  #include <StepperAK.h>
  #include <AFMotor.h>

  AF_DCMotor motor1(1);
  AF_DCMotor motor2(2);
  AF_DCMotor motor3(3);
  AF_DCMotor motor4(4);
  
  #define pin1  9//these are the Arduino pins that we use to activate coils 1-4 of the stepper motor
  #define pin2  10
  #define pin3  13
  #define pin4  2
  
  #define delaytime 10   //delay time in ms to control the stepper motor delaytime.
                        //Our tests showed that 8 is about the fastest that can yield reliable operation w/o missing steps


}

//DC MOTORS
/* Here we list all functions to be implemented in our code, 
 * with docstrings to explain what it does, what parameters it has and what it returns 
 */

#include <StepperAK.h>
#include <AFMotor.h>

//DC MOTORS
void dc_move(AF_DCMotor motor1,AF_DCMotor motor2, char dir, int runtime){
  /*Moves two specific motors in the same direction
   * Parameters:
   *    motor1, motor2 : dc motor objects on opposite sides of the vehicle
   *    dir (char): direction FORWARD or BACKWARD
   *    runtime (ms)
   */ 
  motor1.setSpeed(motor_speed);//speed
  motor2.setSpeed(motor_speedl);
  motor1.run(dir);
  motor2.run(dir);
  delay(runtime);       // Yo whats this delay(runtime) doing? why we wanna do this?
  motor1.setSpeed(0);  //Q: Do we want the motor to run continuously until we tell it to stop,
  motor2.setSpeed(0);  //    or do we want it to go a certain distance then stop?
  delay(500); 
}

/* ELLEN: "Josh, ive written these functions for us to test tomorrow (friday 13th)
 *  hopefully that'll answer your q abt wheter the run func should specify distance or not
 */
 
void dc_go(AF_DCMotor A, AF_DCMotor B, char dir){
  A.setSpeed(255);
  B.setSpeed(255);
  A.run(dir);
  B.run(dir);
}

void dc_stop(AF_DCMotor A, AF_DCMotor B){
  A.setSpeed(0);
  B.setSpeed(0);
}

void spin(AF_DCMotor motor1, AF_DCMotor motor2, int angle){
  /*Powers two opposite motors in opposite directions
   * Parameters:
   *    motor1, motor2 : AF_DCMotor objects
   *    angle: angle at which we want to turn
   *  MAKE SURE YOU CHOOSE motor1 AND motor2 SUCH THAT SPIN WILL OCCUR IN THE DESIRED DIRECTION
   *  (are there ways to incorporate that^ in the parameters?
   */
}

//STEPPER
void step_open(){
  /* Opens the door. We need to experimentally calculate how many steps it takes to open/close the door
   * Once we have that, numberOfSteps could probably be stated in the function below, since it's always the same.
   */
  int numberOfSteps = numberofstepstoopendoor;
  step_OFF();         //turning all coils off
  while(numberOfSteps>0){
    forward();        //going forward
    numberOfSteps -- ;
  }
}

void step_close(){

  /* Closes the door
   * Same as step_open(), but with backward, instead of forward. Could probably make this one function to be more efficient
   */
   int numberOfSteps = numberofstepstoopendoor;
  step_OFF();         //turning all coils off
  while(numberOfSteps>0){
    forward();        //going forward
    numberOfSteps -- ;
  }
}

//ULTRASONIC
int get_distance(){
  /* Calculates the distance to nearest object based on ultrasonic readings
   *  Returns an integer
   */
  int readings[5];
  sum=0
  for (int reading = 0; reading < 5; reading +=1){
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);  
    duration = pulseIn(echoPin, HIGH);
    distance = duration/58.2;
    readings[reading] = distance
    sum += distance
  }
  for (int reading = 0; reading<5; reading+=1){
    if (reading - (sum/size(readings)) > 20){
      {
			for(int j=reading; j<(4); j++)
			{
				readings[j]=readings[j+1];
			}
			break;
       
    }
  }
}



bool is_mag (){
  /* Returns true if nearest object is magnetic, false otherwise.
   *  Depending on how the magnetometer works for us, we may change what this function does.
   *  Could end up being some sort of get_mag_distance()  Annie?   */
}

bool are_we_home(){
  //true if we're at base, false if not
}



