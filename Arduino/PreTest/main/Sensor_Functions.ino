
//ULTRASONIC
int get_distance() {
  /* Calculates the distance to nearest object based on ultrasonic readings
      Returns an integer
  */
  int readings[5];
  int num = 5;
  int sum = 0;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  int duration = pulseIn(echoPin, HIGH);
  int distance = duration / 58.2;
  return distance;

}



bool is_mag () {
  /* Calculates the disturbance in the magnetic field of the Earth due to the presence of a magnet
    and returns a bool value .   */

  int x, y, z; //triple axis data

  //Tell the HMC5883L where to begin reading data
  Wire.beginTransmission(address);
  Wire.write(0x03); //select register 3, X MSB register
  Wire.endTransmission();


  //Read data from each axis, 2 registers per axis
  Wire.requestFrom(address, 6);
  if (6 <= Wire.available()) {
    x = Wire.read() << 8; //X msb
    x |= Wire.read(); //X lsb
    z = Wire.read() << 8; //Z msb
    z |= Wire.read(); //Z lsb
    y = Wire.read() << 8; //Y msb
    y |= Wire.read(); //Y lsb
  }

  if (x > -800) { //assuming sensing in only x direction
    return true;
  }
  else {
    return false;
  }

}
