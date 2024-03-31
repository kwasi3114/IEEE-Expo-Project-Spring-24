/**
 * @file IEEESkiiBall.ino
 * @author Strahinja Marinkovic
 * @date March 21, 2024
 * @version 1.0
 *
 * @section DESCRIPTION
 *
 * This file contains the main program for the IEEE
 * Skii Ball machine. 
 */
 
#include <DFRobot_RGBMatrix.h> // Hardware-specific library
#include <Wire.h>
#include <Servo.h>

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

int const PR1_PIN = A5;
int const PR2_PIN = A6;
int const PR3_PIN = A7;

Servo servo;
int const SERVO_PIN = 3;
int const BUTTON_PIN = 2;

int const prSensitivity = 400;

int buttonState = 0;
int highScore = 0;
int score = 0;
int servoPosition = 0;

void reset() {
  if (score > highScore){
    highScore = score;
  }

  score = 0;

  //open servo for balls then close

  matrix.print("High Score");
  matrix.println(highScore);
}

void setup_matrix() {
  matrix.begin();
  // fill the screen with 'black'
  matrix.setTextSize(1);     // size 1 == 8 pixels high
  matrix.fillScreen(matrix.Color333(0, 0, 0));

  matrix.fillScreen(0);
  matrix.setTextSize(1);
  matrix.setCursor(0, 0);    
  matrix.setTextColor(matrix.Color333(4, 0, 4));
}

void setup() {
  pinMode(PR1_PIN, INPUT);
  pinMode(PR2_PIN, INPUT);
  pinMode(PR3_PIN, INPUT);

  servo.attach(SERVO_PIN);
  pinMode(BUTTON_PIN, INPUT);

  Serial.begin(19200);

  setup_matrix();
  reset();
}

void loop() {
  // read photoresistor values
  int pr1_val = analogRead(PR1_PIN);
  int pr2_val = analogRead(PR2_PIN);
  int pr3_val = analogRead(PR3_PIN);

  buttonState = digitalRead(BUTTON_PIN);

  if (buttonState == HIGH) {
    reset();
  } 
  else {
    if (pr1_val > prSensitivity) {
      score = score + 25;
    }
    else if (pr2_val > prSensitivity) {
      score = score + 50;
    }
    else if (pr3_val > prSensitivity) { 
      score = score + 100;
    }

    matrix.print("Score: ");
    matrix.println(score);
    delay(500);
  }
}
