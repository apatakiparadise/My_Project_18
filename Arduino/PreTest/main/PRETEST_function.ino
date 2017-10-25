
void pretest(){

  //move forwards
  dc_move(motor1, motor3, FORWARD, 3000);
  
  //move backwards
  dc_move(motor1, motor3, BACKWARD, 3000);
  
  //turn left
  dc_spin(motor2, motor4);
  dc_spin(motor2, motor4);
  
  //turn right
  dc_spin(motor4, motor2 ); //reversing the two motors should reverse directions
  dc_spin(motor4, motor2 );
  
  //stop
  dc_stop(motor1, motor3);
  dc_stop(motor2, motor4);
  delay(10000);
  
  //detect magnetic target
  if( is_mag() == true){
    step_open();
    step_close();
  }
  else{
    dc_move(motor1, motor3, BACKWARD, 1000);
  }

  delay(5000);
  
  //retrieve target
  collect();
  
  //dump target
  dump();
  
}


