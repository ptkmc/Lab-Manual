// Visit www.makexchange.com for exciting new coding projects
// and to expand your inventing skills and knowledge.

/*
 Using a potentiometer coupled with a temperature sensor to 
 create a thermostat.

 The potentiometer allows the user to set the temperature at
 which the fan should be turned on.

*/

int potpin = 0;  // Anaolog pin 0 measures potentiometer voltage
int temppin = 1;  // Analog pin 1 measures the temperature sensor voltage.
int fanpin = 9;  // Digital pin #9 turns the fan on or off
int thermostat_val;    // stores position of the thermostat
int temp_sensor;  // stores the analog reading from the temperature sensor.
                  // this is an integer because the value read from the analog pin will
                  // always be a whole number between the values of 0 and 1023.
                  
float temperature; // stores the actual temperature. We use float because this number
                   // will include a decimal place like 68.56-degrees.
                   // remember that int is for integer, which is a whole number like 68, 69, or 70.

void setup() {
  pinMode(fanpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  thermostat_val = analogRead(potpin);            // read the value of the potentiometer (value between 0 and 1023)
  temp_sensor = analogRead(temppin);          // read the value of the temperature sensor
  Serial.print("First reading of temp is:  "); Serial.print(temp_sensor); Serial.print("\n");

  
  thermostat_val = map(thermostat_val, 0, 1023, 58, 90);     // scale it to use it with the servo (value between 58-degrees and 90-degrees)

  //Convert the analog pin output for the temperature sensor to degrees F
  temperature = temp_sensor * 5;  // 
  temperature = temperature/1024*100;
  
  
  Serial.print("Thermostat reads:  "); Serial.print(thermostat_val); Serial.print("\n");
  Serial.print("Temp is:  "); Serial.print(temperature); Serial.print("\n");

  if (thermostat_val < temperature){    // Turn on the fan if the temperature
    digitalWrite(fanpin, HIGH);             // gets hotter than the thermostat setting.
  }
  else {
    digitalWrite(fanpin, LOW);
  }
  delay(100);
}

