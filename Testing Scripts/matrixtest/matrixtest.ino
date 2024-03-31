/**
 * @file matrixtest.ino
 * @author Strahinja Marinkovic
 * @date March 31, 2024
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This file contains a script to test the LED matrix.
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

DFRobot_RGBMatrix matrix(A, B, C, D, E, CLK, LAT, OE, false, WIDTH, HIGH);

int highScore = 100;
int score = 0;

void setup_matrix() {
  matrix.begin();
  // fill the screen with 'black'
  matrix.setTextSize(1);     // size 1 == 8 pixels high
  matrix.fillScreen(matrix.Color333(0, 0, 0));

  matrix.fillScreen(0);
  matrix.setTextSize(1);
  matrix.setCursor(0, 0);    
  matrix.setTextColor(matrix.Color333(4, 0, 4));
  matrix.print("High Score");
  matrix.println(highScore);
}

void setup() {
  Serial.begin(19200);

  setup_matrix();
}

void loop() {
  for (int i = 0; i < 100; i++) {
    matrix.fillScreen(matrix.Color333(0, 0, 0));
    matrix.setCursor(0, 0); 
    matrix.print("Score: ");
    matrix.print(score);
    score++;
    delay(500);
  }
}
