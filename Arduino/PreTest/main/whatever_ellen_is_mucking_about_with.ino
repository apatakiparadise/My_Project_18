#include <AFMotor.h>

void dc_move2(char dir, int runtime) {
  /*Moves two specific motors in the same direction
     Parameters:
        motor1, motor2 : dc motor objects on opposite sides of the vehicle
        dir (char): direction FORWARD or BACKWARD
        runtime (ms)
  */
  motor1.setSpeed(255);
  motor3.setSpeed(200);
  motor1.run(dir);
  motor3.run(dir);
  delay(runtime);       
  motor1.run(RELEASE);  
  motor3.run(RELEASE); 
  delay(500);
}
