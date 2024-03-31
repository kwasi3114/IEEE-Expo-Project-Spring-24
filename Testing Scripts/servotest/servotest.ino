/**
 * @file servotest.ino
 * @author Strahinja Marinkovic
 * @date March 31, 2024
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This file contains a test script for the servo.
 */
 
#include <Servo.h>

Servo servo;
int const SERVO_PIN = 3;
int servoPosition = 0;

void setup() {
  servo.attach(SERVO_PIN);
}

void loop() {
  for (servoPosition = 0; servoPosition <= 180; servoPosition += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo.write(servoPosition);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (servoPosition = 180; servoPosition >= 0; servoPosition -= 1) { // goes from 180 degrees to 0 degrees
    servo.write(servoPosition);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
}
