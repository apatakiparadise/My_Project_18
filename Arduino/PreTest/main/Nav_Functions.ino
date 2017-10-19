//This is where we put our overall navigational functions

void strip(char dir){
  dc_go(motor2, motor4, dir);
  howfarwevecome = 0;
  while(howfarwevecome<sidewaystime){
   if (get_distance() < linewidth){
    dc_stop(motor2, motor4);
    if(is_mag()=true){
      collect();  
    }
    delay(pausetime);
  }
  howfarwevecome += pausetime;  
  }
  dc_stop(motor2, motor4);
}

void backtobase(int lines){//do we even need this function?
  dc_move(motor1, motor3, BACKWARD, lines*linetime);
  //thought: maybe change the dc_move runtime to some arbitrarily large number (10000) so that we just run until we hit the wall. 
  //Can our bot take some bumps?
}

void dump(){
  //QUESTION: Should we add the are_we_home() if statement here? What if we're not home?
  dc_spin(motor2, motor4, 180); //doesn't matter which two motors, really
  step_open();
  dc_move(motor1, motor3, BACKWARD, linetime);
  step_close();
  dc_spin(motor2, motor4, 180);
}

void collect(){   //collects and returns to its place
  step_open();
  dc_move(motor1, motor3, FORWARD, collect_time);
  step_close();
  dc_move(motor1, motor3, BACKWARD, collect_time);
  
}
