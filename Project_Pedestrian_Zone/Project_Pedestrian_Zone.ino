/* Building on the code and wiring from the 'Intersection' project, this project will install a cross-walk signal
showing pedestrians when it is safe to cross the intersection.

The new crosswalk also includes an crosswalk signal light to tell pedestrians when it is safe and unsafe to cross by changing colors and flashing.

While traffic is keeping the pedestrian from crossing the street, The signal light will shine a steady orange color. 
Once the traffic has a red light, it will be safe to cross the street and the crosswalk signal light will shine white.

After a few seconds, the signal light will begin to flash orange, telling the pedestrian that the light is about to change.
Eventually, the other street's green light will turn yellow, then red. Once it turns red, the pedestrian signal light will 
stop flashing and return to its original steady orange.

Our new crosswalk also includes a button the pedestrian can press to immediately change the traffic light from green light to yellow
and then red, allowing them to safely cross the street.*/

const int buttonPin = 2;
int buttonState = 0;

// Traffic Light #1
const int Green1 = 11;
const int Yellow1 = 12;
const int Red1 = 13; 

// Traffic Light #2
const int Green2 = 8;
const int Yellow2 = 9;
const int Red2 = 10;

// If you are using a common-anode RGB LED
// you can change the below boolean to 'false'
boolean common_cathode = true;

// A common-cathode RGB LED works similarly to
// other LEDs, with 0 being LOW and 255 being HIGH
// For common-anode RGB LEDs the highest value (255)
// stops the flow of electricity, turning off the color

void setup() {
  // Loop through pins 3 through 13 setting each as OUTPUTs
  for (int x=3; x<14; x++) {
    pinMode(x, OUTPUT);
  }
  // The buttonPin will be used to check for button inputs
  pinMode(buttonPin, INPUT);
}

void loop() {
  // When Traffic Light #1 is green the pedestrians must wait to cross
  // Fortunately, they have a button they can use to speed things up
  stopTimer(8000, Green1, Red2);
  stopTimer(2000, Yellow1, Red2);
  
  // When Traffic Light #2 comes on the pedestrians can safely cross
  goTimer(4000, Red1, Green2);
  blinkTimer(4, 2000, Red1, Green2); 
  stopTimer(2000, Red1, Yellow2);
}

void stopTimer(int duration, int light1, int light2 ) {
  lightsOut(); // Turn off the traffic lights
  walkLight(10, 0, 255); // Set the RGB LED to an orange-red color
  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);  
  // This for loop checks for a button press every 1 millisecond
  // for the length of the duration parameter  
  for (int x=0; x<duration; x++) {
    buttonState = digitalRead(buttonPin);
    if (light1 == Green1 and buttonState == HIGH) {
      break; 
    } else {
      delay(1);   
    } 
  }      
}

void goTimer(int duration, int light1, int light2) {  
  lightsOut();
  walkLight(40, 0, 0); // Set the RGB LED to white
  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);
  delay(duration);       
}

void blinkTimer(int cycles, int duration, int light1, int light2 ) {  
  // Blink the crossing light (cycles) number of times 
  // over (duration) seconds
  duration = (duration / cycles);
  lightsOut();
  for (int i=0; i<cycles; i++) {
    // Turn off the RGB LED
    walkLight(255, 255, 255);
    digitalWrite(light1, HIGH);
    digitalWrite(light2, HIGH);
    delay(duration);
    // Set the RGB LED to an orange-red color
    walkLight(10, 0, 255);
    delay(duration);    
  }     
}

void walkLight(int R, int G, int B) {
  // Set the color of the RGB LED using PWM to write
  // a value between 0 and 255
  if (common_cathode == true) {
    R = 255 - R;
    G = 255 - G;
    B = 255 - B;
  }
  analogWrite(6, R);   // Red
  analogWrite(5, G);   // Green
  analogWrite(3, B);   // Blue     
}

void lightsOut() {
  // Turn off all 6 traffic lights
  for (int i=8; i<14; i++) {
    digitalWrite(i, LOW);
  }
}

