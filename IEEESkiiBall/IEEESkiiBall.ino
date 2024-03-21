/**
 * @file IEEESkiiBall.ino
 * @author Strahinja Marinkovic
 * @date March 21, 2024
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This file contains the main program for the IEEE
 * Skii Ball machine. Currently, it only has a test
 * for a single photoresistor.
 */

int const PHOTO_RESISTOR = 26;

void setup() {
  pinMode(PHOTO_RESISTOR, INPUT);
  Serial.begin(19200);
}

void loop() {
  int photoresistor_value = analogRead(PHOTO_RESISTOR);
  Serial.println(photoresistor_value);
}
