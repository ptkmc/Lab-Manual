// Visit www.makexchange.com for exciting new coding projects
// and to expand your inventing skills and knowledge.

// declare variables
int potpin = A0;
int val;
int fanpin = 9;


void setup() {
  // Prepare the fan pin to send out electricity
  pinMode(fanpin, OUTPUT);      

}

void loop() {
  // Read the potentiometer level
  val = analogRead(potpin);

  // Send the right amount of electricity to the motor.
  val = map(val, 0, 1023, 0, 255);
  analogWrite(fanpin, val);
  delay(15);

}
