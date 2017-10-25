#include <StepperAK.h>
#include <AFMotor.h>
#include <Wire.h> //I2C Arduino Library

#define address 0x1E //0011110b, I2C 7bit address of HMC5883

AF_DCMotor motor1(2);//forward/backward
AF_DCMotor motor2(1);//sideways
AF_DCMotor motor3(4);//forward/backward
AF_DCMotor motor4(3);//sideways

//stepper pins
#define pin1  9  //blue     these are the Arduino pins that we use to activate coils 1-4 of the stepper motor
#define pin2  10 //green
#define pin3  13 //yellow
#define pin4  2  //brown

#define delaytime 20   // (ms) controls the stepper motor delaytime.


//global constants
const int trigPin = A2; 
const int echoPin = A1;

const int sidewaysTime = 6000; // (ms) time takes to travel a bit over 1.2m
const int nextLineTime = 2000; //ms
const int lineWidth = 15; //cm, the distance we hope to cover in nextLineTime
const int spinTime = 920; // (ms) time it takes to do a right angle spin

const int ultraSonicDelay = 100; // (ms) interval between ultrasonic measurements
const int doorSteps = 100; // number of steps to open door using stepper

//global variables
int linesDone = 0;
bool  tagetCollected = false; //ellen, you had this as int, why?

//idk if this is a constant or a variable?? 
int motorSpeed = 100; //between 0 and 255

void setup() {
  //ultrasonic setup
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);

  // initialize the stepper pins as an output:
  pinMode(pin1, OUTPUT);
  pinMode(pin2, OUTPUT); 
  pinMode(pin3, OUTPUT); 
  pinMode(pin4, OUTPUT);
 
  //SDA: A4, SCL:A5

  //Initialize Serial and I2C communications for magno
  Wire.begin();

  //Put the HMC5883 IC into the correct operating mode
  Wire.beginTransmission(address); //open communication with HMC5883
  Wire.write(0x02); //select mode register
  Wire.write(0x00); //continuous measurement mode
  Wire.endTransmission();

  //delay before starting pretest;
  delay(900);

  //Pre-test --- hold up a piece of paper to block the ultrasonic sensor, then press reset button


  delay(500);
  if (get_distance() < 5) {
    pretest();

  }
  //delay before starting main loop
  delay(5000); 
}

void loop() {
   linesDone+=1;
   strip(FORWARD);//left first, then right
  strip(BACKWARD); //make sure that we end up on the right hand edge, so that we don't get stuck around the corner.
  if (targetCollected = true){
      dc_move(motor1, motor3, BACKWARD, linesDone*nextLineTime);
      dump(); //dump should include spinning, opening door, reversing, closing door, then spinning again
      dc_move(motor1, motor3, FORWARD, linesDone*nextLineTime);
   }
   else if (get_distance() > lineWidth){
      dc_move(motor1, motor3, FORWARD, nextLineTime);
   }
  else{
      dc_move(motor1, motor3, BACKWARD, nextLineTime*2);
   }


}