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
  blinkTimer(4, 500, Red1, Green2); 
  stopTimer(2000, Red1, Yellow2);
}

void stopTimer(int duration, int light1, int light2 ) {
  lightsOut(); // Turn off the traffic lights
  walkLight(0, 150, 255); // Set the RGB LED to an orange-red color
  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);  
  // This FOR loop checks for a button press every 1 millisecond
  // for the length of the duration parameter  
  for (int x=0; x<duration; x++) {
    buttonState = digitalRead(buttonPin);
    if (light1 == 11 and buttonState == HIGH) {
      break; 
    } else {
      delay(1);   
    } 
  }      
}

void goTimer(int duration, int light1, int light2) {  
  lightsOut();
  walkLight(40, 40, 0); // Set the RGB LED to white
  digitalWrite(light1, HIGH);
  digitalWrite(light2, HIGH);
  delay(duration);       
}

void blinkTimer(int cycles, int duration, int light1, int light2 ) {  
  lightsOut();
  for (int i=0; i<cycles; i++) {
    // Turn off the RGB LED
    walkLight(255, 255, 255);
    digitalWrite(light1, HIGH);
    digitalWrite(light2, HIGH);
    delay(duration);
    // Set the RGB LED to an orange-red color
    walkLight(0, 150, 255);
    delay(duration);    
  }     
}

void walkLight(int R, int G, int B) {
  // Set the color of the RGB LED 
  // Remember that for a common-annode RGB LED the highest value (255)
  // stops the flow of electricity, turning off the color
  analogWrite(6, R);   // Red
  analogWrite(5, G);   // Green
  analogWrite(3, B);   // Blue     
}

void lightsOut() {
  for (int i=8; i<14; i++) {
    digitalWrite(i, LOW);
  }
}

