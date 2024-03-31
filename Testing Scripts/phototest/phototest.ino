/**
 * @file phototest.ino
 * @author Strahinja Marinkovic
 * @date March 31, 2024
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This file contains a test script for the photoresistors.
 */
 
int const PR1_PIN = A5;
int const PR2_PIN = A6;
int const PR3_PIN = A7;

void setup() {
  pinMode(PR1_PIN, INPUT);
  pinMode(PR2_PIN, INPUT);
  pinMode(PR3_PIN, INPUT);

  Serial.begin(19200);
}

void loop() {
  // read photoresistor values
  int pr1_val = analogRead(PR1_PIN);
  int pr2_val = analogRead(PR2_PIN);
  int pr3_val = analogRead(PR3_PIN);

  Serial.print("PR1: ");
  Serial.print(pr1_val);
  Serial.print(" PR2: ");
  Serial.print(pr2_val);
  Serial.print(" PR3: ");
  Serial.print(pr3_val);
}
