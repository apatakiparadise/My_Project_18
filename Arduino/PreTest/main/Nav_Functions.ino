//This is where we put our overall navigational functions

void strip(char dir) {
  int currentTravelTime = 0;
  
  dc_go(motor2, motor4, dir);
  while (currentTravelTime < sidewaysTime) {
    if (get_distance() < lineWidth) {
      dc_stop(motor2, motor4);
      if (is_mag() == true) {
        collect();
      }
      dc_go(motor2, motor4, dir);
      delay(ultraSonicDelay);
    }
    currentTravelTime += ultraSonicDelay;
  }
  dc_stop(motor2, motor4);
}

void dump() {

  dc_spin(motor2, motor4); 
  dc_spin(motor2, motor4); 
  step_open();
  dc_move(motor1, motor3, BACKWARD, nextLineTime);
  step_close();
  dc_spin(motor2, motor4);
  dc_spin(motor2, motor4);
}

void collect() {  //collects and returns to its place
  step_open();
  dc_move(motor1, motor3, FORWARD, nextLineTime);
  step_close();
  dc_move(motor1, motor3, BACKWARD, nextLineTime);

}
