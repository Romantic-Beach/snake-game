#define X_AXIS A0  
#define Y_AXIS A1  
#define BUTTON 7   

void setup() {
  Serial.begin(9600);
  pinMode(BUTTON, INPUT_PULLUP);
}

void loop() {
  int xValue = analogRead(X_AXIS);
  int yValue = analogRead(Y_AXIS);
  int buttonState = digitalRead(BUTTON);

  char direction;
  if (xValue < 300) direction = 'L';
  else if (xValue > 700) direction = 'R';
  else if (yValue < 300) direction = 'U';
  else if (yValue > 700) direction = 'D';
  else direction = 'N';

  Serial.print(direction);
  if (buttonState == LOW) Serial.print('B');
  Serial.println();
  delay(100);
}