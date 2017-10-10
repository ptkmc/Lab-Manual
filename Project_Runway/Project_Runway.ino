byte ledPin[] = {13, 12, 11, 10, 9, 8};  // Create array for LED pins
int sensorPin = A0;
// int ledDelay(65);  // delay between changes
int direction = 1;
int currentLED = 0;
int ledDelay = 0;
unsigned long changeTime;

void setup() {
  for (int x=0; x<6; x++) {    // set all pins to output
    pinMode(ledPin[x], OUTPUT); }
  changeTime = millis();
  Serial.begin(9600);
}

void loop() {
  ledDelay = analogRead(sensorPin);
  Serial.print(ledDelay);    // delay in ms
  Serial.print('\n');
  if ((millis() - changeTime) > ledDelay) {    // if it has been ledDelay ms since last change
    changeLED();
    changeTime = millis();     
  }
}

void changeLED() {
  for (int x=0; x<6; x++) {    // turn off all LED's
    digitalWrite(ledPin[x], LOW);
  }
  digitalWrite(ledPin[currentLED], HIGH);    // turn on the current LED
  currentLED += direction;    // incrememnt by the direction value
  if (currentLED == 6) {currentLED = 0;}
  // change direction if we reach the end
  // if (currentLED == 5) {direction = -1;}
  // if (currentLED == 0) {direction = 1;}
}

