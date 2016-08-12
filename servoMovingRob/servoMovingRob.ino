#include <Servo.h>

Servo servoRight;
Servo servoLeft;

void setup() {
  // put your setup code here, to run once:
  servoLeft.attach(13);
  servoRight.attach(12);
  servoLeft.writeMicroseconds(1500);
  servoRight.writeMicroseconds(1500);

  //forward
  servoLeft.writeMicroseconds(1700);//CCW
  servoRight.writeMicroseconds(1300);//CW
  delay(1500);
  //backward
  servoLeft.writeMicroseconds(1700);//CCW
  servoRight.writeMicroseconds(1300);//CW 
  delay(1500);
  //right turn
  servoLeft.writeMicroseconds(1700);//CCW
  servoRight.writeMicroseconds(1700);//CCW
  delay(1500);
  // left turn 
  servoLeft.writeMicroseconds(1300);//CW
  servoRight.writeMicroseconds(1300);//CW
  delay(1500);
}

void loop() {
  // put your main code here, to run repeatedly:

}
