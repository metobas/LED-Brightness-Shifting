int const x_axis = A0;
int const Y_axis = A1;
int const joyStick_sw = 2;

int LED1 = 3;
int LED2 = 5;
int LED3 = 6;
int LED4 = 9;
int LED5 = 10;
int LED6 = 11;

int LED1Value;
int LED2Value;
int LED3Value;
int LED4Value;
int LED5Value;
int LED6Value;

int read_X;
int read_Y;
int read_SW;

int buttonState;
int memory = HIGH;
int programMode = 1;

int wait (10);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);

  pinMode(x_axis, INPUT);
  pinMode(Y_axis, INPUT);
  pinMode(joyStick_sw, INPUT_PULLUP);

  pinMode(LED1, OUTPUT);
  pinMode(LED2, OUTPUT);
  pinMode(LED3, OUTPUT);
  pinMode(LED4, OUTPUT);
  pinMode(LED5, OUTPUT);
  pinMode(LED6, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  read_X = analogRead(x_axis);
  read_Y = analogRead(Y_axis);
  read_SW = digitalRead(joyStick_sw);
  buttonState = digitalRead(joyStick_sw);

  if (buttonState == HIGH && memory == HIGH){
    if (programMode == 2){
      programMode = 1;
    }else {
      programMode = 2;
    }
    memory = LOW;
    delay(wait);                   // this delay is added to handle the debouncing effect caused by the physical button.
  } else if (buttonState == LOW && memory == LOW) {
    memory = HIGH;                 // this memeory bit is added to handle multiple commands at very short time intervals.
  }

  if (programMode == 1) {
  LED1Value = -sq(((read_Y/20.)-10.23*(0.)))+255;
  LED2Value = -sq(((read_Y/20.)-10.23*(1.)))+255;
  LED3Value = -sq(((read_Y/20.)-10.23*(2.)))+255;
  LED4Value = -sq(((read_Y/20.)-10.23*(3.)))+255;
  LED5Value = -sq(((read_Y/20.)-10.23*(4.)))+255;
  LED6Value = -sq(((read_Y/20.)-10.23*(5.)))+255;
  }

  if (programMode == 2){
  LED1Value = sq(((read_Y/40.)-5.11*(0.)))-15;
  LED2Value = sq(((read_Y/40.)-5.11*(1.)))-15;
  LED3Value = sq(((read_Y/40.)-5.11*(2.)))-15;
  LED4Value = sq(((read_Y/40.)-5.11*(3.)))-15;
  LED5Value = sq(((read_Y/40.)-5.11*(4.)))-15;
  LED6Value = sq(((read_Y/40.)-5.11*(5.)))-15;
  }

  if (LED1Value<1){
    analogWrite(LED1, 0);
  }else if (LED1Value>254){
    analogWrite(LED1, 255);
  }else {
    analogWrite(LED1, LED1Value);
  }

  if (LED2Value<1){
    analogWrite(LED2, 0);
  }else if (LED2Value>254){
    analogWrite(LED2, 255);
  }else {
    analogWrite(LED2, LED2Value);
  }

  if (LED3Value<1){
    analogWrite(LED3, 0);
  }else if (LED3Value>254){
    analogWrite(LED3, 255);
  }else {
  analogWrite(LED3, LED3Value);
  }

  if (LED4Value<1){
    analogWrite(LED4, 0);
  }else if (LED4Value>254){
    analogWrite(LED4, 255);
  }else {
  analogWrite(LED4, LED4Value);
  }

  if (LED5Value<1){
    analogWrite(LED5, 0);
  }else if (LED5Value>254){
    analogWrite(LED5, 255);
  }else {
  analogWrite(LED5, LED5Value);
  }

  if (LED6Value<1){
    analogWrite(LED6, 0);
  }else if (LED6Value>254){
    analogWrite(LED6, 255);
  }else {
  analogWrite(LED6, LED6Value);
  }

  Serial.println(LED1Value);
}
