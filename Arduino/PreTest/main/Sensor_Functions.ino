
//ULTRASONIC
int get_distance() {
  /* Calculates the distance to nearest object based on ultrasonic readings
      Returns an integer
  */
  int readings[5];
  int sum = 0;
  for (int reading = 0; reading < 5; reading += 1) {
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    int duration = pulseIn(echoPin, HIGH);
    int distance = duration / 58.2;
    readings[reading] = distance;
    sum += distance;
  }
  for (int reading = 0; reading < 5; reading += 1) {
    if (reading - (sum / 5 > 20)) {
      {
        for (int j = reading; j < (4); j++)
        {
          readings[j] = readings[j + 1];
        }
        break;

      }
    }
  }
  return sum/5;
  
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

  if (x>-800){//assuming sensing in only x direction
    return true;
  }

}

