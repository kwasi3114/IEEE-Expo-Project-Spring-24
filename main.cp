
//#include <Servo.h>

int servoPin = 3;
int buttonState = 0;
int buttonPin = 2;
//Servo servo;

void setup_matrix() {
  matrix.begin();
  // fill the screen with 'black'
  matrix.setTextSize(1);     // size 1 == 8 pixels high
  matrix.fillScreen(matrix.Color333(0, 0, 0));

  matrix.fillScreen(0);
  matrix.setTextSize(2);
  matrix.setCursor(0, 0);    
  matrix.setTextColor(matrix.Color333(4, 0, 4));
  //matrix.println("hello");
}

//reset score, store score if high score, release game balls
void reset(){
  if (score > highScore){
    highScore = score;
  }

  score = 0;

  digitalWrite(servoPin, HIGH);
  delay(10000); 
  digitalWrite(servoPin, LOW);

  matrix.println("High Score" + highScore);

}

//initialization of variables for the game loop
void setup()
{
  int score = 0;
  int highScore = 0;
  pinMode(servoPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  setup_matrix();
  matrix.println("High Score" + highScore);
}

//main game loop, track score and reset upon button press
void loop()
{
  buttonState = digitalRead(buttonPin);

  if (buttonState == HIGH){
    reset()
  } else {
    int pr1 = analogRead(A0);
    int pr2 = analogRead(A1);
    int pr3 = analogRead(A2);
  
    if (pr1 > 450) {
      score = score + 25;
    }
    
    if (pr2 > 450) {
      score = score + 50;
    }
    
    if (pr3 > 450) { 
      score = score + 100;
    }

    matrix.println("Score" + score);
    delay(500);
  }
}