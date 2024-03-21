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
 * for a single photoresistor and the matrix.
 */
 
#include <DFRobot_RGBMatrix.h> // Hardware-specific library
#include <Wire.h>

#define OE    9
#define LAT   10
#define CLK   11
#define A     A0
#define B     A1
#define C     A2
#define D     A3
#define E     A4
#define WIDTH 64
#define HIGH  64
int a=0;
int b=16;
DFRobot_RGBMatrix matrix(A, B, C, D, E, CLK, LAT, OE, false, WIDTH, HIGH);

int const PHOTO_RESISTOR = A5;

void setup_matrix() {
  matrix.begin();
  // fill the screen with 'black'
  matrix.setTextSize(1);     // size 1 == 8 pixels high
  matrix.fillScreen(matrix.Color333(0, 0, 0));

  matrix.fillScreen(0);
  matrix.setTextSize(2);
  matrix.setCursor(0, 0);    
  matrix.setTextColor(matrix.Color333(4, 0, 4));
  matrix.println("hello");
}

void setup() {
  pinMode(PHOTO_RESISTOR, INPUT);
  Serial.begin(19200);

  setup_matrix();
}

void loop() {
  int photoresistor_value = analogRead(PHOTO_RESISTOR);
  Serial.println(photoresistor_value);
}
