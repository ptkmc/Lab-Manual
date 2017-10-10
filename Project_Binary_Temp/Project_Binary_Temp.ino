int latchPin = 8;
int clockPin = 12;
int dataPin = 11;
int sensorPin = A0;

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT); 
  Serial.begin(9600); 
}

void loop() {
    int reading = analogRead(sensorPin);
    float voltage = reading * 5.0;
    voltage /= 1024.0;
    //Serial.print(voltage); Serial.println(" volts");
    float temperatureC = (voltage - 0.5) * 100;
    //Serial.print(temperatureC); Serial.println(" degrees C");
    float temperatureF = (temperatureC * 9.0 / 5.0) + 32;
    Serial.print(temperatureF); Serial.println(" degrees F");
    digitalWrite(latchPin, LOW);
    shiftOut(temperatureF);
    digitalWrite(latchPin, HIGH);
    delay(1000);
}

void shiftOut(byte dataOut) {
  boolean pinState;
  digitalWrite(dataPin, LOW);
  digitalWrite(clockPin, LOW);

  for (int i=07; i>=0; i--) {
    digitalWrite(clockPin, LOW);
    if ( dataOut & (1<<i) ) {
      pinState = HIGH;
    }
    else {
      pinState = LOW;
    }
    digitalWrite(dataPin, pinState);
    digitalWrite(clockPin, HIGH);
  }
  digitalWrite(clockPin, LOW);
}

