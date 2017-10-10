const int redPin = 6;
const int greenPin = 5;
const int bluePin = 3;
int buttonPin = 2;

void setup() {
  // Start with the LED off.
  setColorRgb(255,255,255);
  pinMode(buttonPin, INPUT);
 }

void loop() {
  unsigned int rgbColor[3];
  
  if (digitalRead(buttonPin) == HIGH) {
    // Start off with red.
    rgbColor[0] = 0;
    rgbColor[1] = 255;
    rgbColor[2] = 255; 

    // Choose the colors to increment and decrement.
    for (int incColor = 0; incColor < 3; incColor += 1) {
      int decColor = incColor == 2 ? 0 : incColor + 1;
  
      
      // cross-fade the two colors.
      for(int i = 0; i < 255; i += 1) {
        rgbColor[incColor] += 1;
        rgbColor[decColor] -= 1; 
        setColorRgb(rgbColor[0], rgbColor[1], rgbColor[2]);
        delay(5); 
        }         
      }
    }
  } else {
    // Turn LED off
    setColorRgb(255,255,255);
        delay(5);
  }
  
}

void setColorRgb(unsigned int red, unsigned int green, unsigned int blue) {
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);
 }
