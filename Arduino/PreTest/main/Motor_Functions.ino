//DC MOTORS
/* Here we list all functions to be implemented in our code,
   with docstrings to explain what it does, what parameters it has and what it returns
*/
#include <AFMotor.h>

void dc_move(AF_DCMotor motor1, AF_DCMotor motor2, char dir, int runtime) {
  /*Moves two specific motors in the same direction
     Parameters:
        motor1, motor2 : dc motor objects on opposite sides of the vehicle
        dir (char): direction FORWARD or BACKWARD
        runtime (ms)
  */
  motor1.setSpeed(motorSpeed);
  motor2.setSpeed(motorSpeed);
  motor1.run(dir);
  motor2.run(dir);
  delay(runtime);       
  motor1.run(RELEASE);  
  motor2.run(RELEASE); 
  delay(500);
}

void dc_go(AF_DCMotor A, AF_DCMotor B, char dir) {
  A.setSpeed(motorSpeed);
  B.setSpeed(motorSpeed);
  A.run(dir);
  B.run(dir);
}


void dc_stop(AF_DCMotor A, AF_DCMotor B) {
  A.run(RELEASE);
  B.run(RELEASE);
}

void dc_spin(AF_DCMotor motor1, AF_DCMotor motor2) {
  /*Rotates 90 degrees. Changing order of motors in args changes rotation direction
     Parameters:
        motor1, motor2 : pair of opposite motors
  */
  motor1.setSpeed(motorSpeed);
  motor2.setSpeed(motorSpeed);
  
  motor1.run(FORWARD);
  motor2.run(BACKWARD);
  delay(spinTime);
  motor1.run(RELEASE);
  motor2.run(RELEASE);
}
