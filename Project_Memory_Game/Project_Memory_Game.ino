#include <Tone.h>

Tone speakerpin;
int starttune[] = {NOTE_C4, NOTE_F4, NOTE_C4, NOTE_F4, NOTE_C4,
 NOTE_F4, NOTE_C4, NOTE_F4, NOTE_G4, NOTE_F4, NOTE_E4, NOTE_F4,
 NOTE_G4};
int duration2[] = {100, 200, 100, 200, 100, 400, 100, 100, 100, 100,
 200, 100, 500};
int note[] = {NOTE_C4, NOTE_C4, NOTE_G4, NOTE_C5, NOTE_G4, NOTE_C5};
int duration[] = {100, 100, 100, 300, 100, 300};

byte button[] = {2, 3, 4, 5};  // Pins connected to pushbutton inputs
byte ledpin[] = {7, 8, 9, 10}; // Pins connected to LEDs

int turn = 0; // Turn counter
int buttonstate = 0; // Check pushbutton state
int randomArray[100]; // Array that can store up to 100 inputs
int inputArray[100];

void setup() {
  Serial.begin(9600);
  speakerpin.begin(12); // Pin connected to piezo buzzer
  for (int x = 0; x < 4; x++) {
    pinMode(ledpin[x], OUTPUT); // Set LED pins as output
  }
  for (int x = 0; x < 4; x++) {
    pinMode(button[x], INPUT_PULLUP); // Set pushbutton pins as inputs
    //digitalWrite(button[x], HIGH); // Enable internal pullup;
    // pushbuttons start in high
    // position; logic reversed    
  }
  // Generate "more randomness" with randomArray for the output
  // function so pattern is different each time
  randomSeed(analogRead(0));
  for (int thisNote = 0; thisNote < 13; thisNote ++) {
    speakerpin.play(starttune[thisNote]); // Play the next note
    if (thisNote == 0 || thisNote == 2 || thisNote == 4 ||
    thisNote == 6) { // Hold the note
      digitalWrite(ledpin[0], HIGH);
    }
    if (thisNote == 1 || thisNote == 3 || thisNote == 5 ||
    thisNote == 7 || thisNote == 9 || thisNote == 11) {
      digitalWrite(ledpin[1], HIGH);
    }
    if (thisNote == 8 || thisNote == 12) {
      digitalWrite(ledpin[2], HIGH);
    }
    if (thisNote == 10) {
      digitalWrite(ledpin[3], HIGH);
    }
    delay(duration2[thisNote]);
    speakerpin.stop(); // Stop for the next note
    writeLeds(0);
    delay(25);
  }
  delay(1000);
}

void loop() {
  // Generate the array to be matched by the player
  for (int y = 0; y <= 99; y++) {
    writeLeds(255);
    // Play the next note
    for (int thisNote = 0; thisNote < 6; thisNote ++) {
      speakerpin.play(note[thisNote]); // Hold the note
      delay(duration[thisNote]); // Stop for the next note
      speakerpin.stop();
      delay(25);
    }
    writeLeds(0);
    delay(1000);
    // Limited by the turn variable
    for (int y = turn; y <= turn; y++) {
      Serial.println("");
      Serial.print("Turn: ");
      Serial.print(y);
      Serial.println("");
      randomArray[y] = random(1, 5); // Assign a random number (1-4)
      // Light LEDs in random order
      for (int x = 0; x <= turn; x++) {
        Serial.print(randomArray[x]);
        for (int y = 0; y < 4; y++) {
          if (randomArray[x] == 1 && ledpin[y] == 7) {
            digitalWrite(ledpin[y], HIGH);
            speakerpin.play(NOTE_G3, 100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
            delay(100);
          }
          if (randomArray[x] == 2 && ledpin[y] == 8) {
            digitalWrite(ledpin[y], HIGH);
            speakerpin.play(NOTE_A3, 100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
            delay(100);
          }
          if (randomArray[x] == 3 && ledpin[y] == 9) {
            digitalWrite(ledpin[y], HIGH);
            speakerpin.play(NOTE_B3, 100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
            delay(100);
          }
          if (randomArray[x] == 4 && ledpin[y] == 10) {
            digitalWrite(ledpin[y], HIGH);
            speakerpin.play(NOTE_C4, 100);
            delay(400);
            digitalWrite(ledpin[y], LOW);
            delay(100);
          }
        }
      }
    }
    input();
  }
}

// Check whether input matches the pattern
void input() {
  for (int x = 0; x <= turn;) {
    for (int y = 0; y < 4; y++) {
      buttonstate = digitalRead(button[y]); // Check for button push
      if (buttonstate == LOW && button[y] == 2) {
        digitalWrite(ledpin[0], HIGH);
        speakerpin.play(NOTE_G3, 100);
        delay(200);
        digitalWrite(ledpin[0], LOW);
        inputArray[x] = 1;
        delay(250);
        Serial.print(" ");
        Serial.print(1);
        // Check if value of user input matches the generated array
        if (inputArray[x] != randomArray[x]) {
          fail(); // If not, fail function is called
        }
        x++;
      }
      if (buttonstate == LOW && button[y] == 3) {
        digitalWrite(ledpin[1], HIGH);
        speakerpin.play(NOTE_A3, 100);
        delay(200);
        digitalWrite(ledpin[1], LOW);
        inputArray[x] = 2;
        delay(250);
        Serial.print(" ");
        Serial.print(2);
        if (inputArray[x] != randomArray[x]) {
          fail();
        }
        x++;
      }
      if (buttonstate == LOW && button[y] == 4) {
        digitalWrite(ledpin[2], HIGH);
        speakerpin.play(NOTE_B3, 100);
        delay(200);
        digitalWrite(ledpin[2], LOW);
        inputArray[x] = 3;
        delay(250);
        Serial.print(" ");
        Serial.print(3);
        if (inputArray[x] != randomArray[x]) {
          fail();
        }
        x++;
      }
      if (buttonstate == LOW && button[y] == 5) {
        digitalWrite(ledpin[3], HIGH);
        speakerpin.play(NOTE_C4, 100);
        delay(200);
        digitalWrite(ledpin[3], LOW);
        inputArray[x] = 4;
        delay(250);
        Serial.print(" ");
        Serial.print(4);
        if (inputArray[x] != randomArray[x]) {
          fail();
        }
        x++;
      }
    }
  }
  delay(500);
  turn++; // Increment turn count
}

// Function used if player fails to match the sequence
void fail() {
  for (int y = 0; y <= 2; y++) { // Flash lights to indicate failure
    writeLeds(255);
    speakerpin.play(NOTE_G3, 300);
    delay(200);
    writeLeds(0);
    speakerpin.play(NOTE_C3, 300);
    delay(200);
  }
  delay(500);
  turn = -1; // Reset turn value to start the game again
}

// Function to turn all 4 lights on or off
void writeLeds(int brightness) {
  for (int i = 0; i<4; i++) {
    digitalWrite(ledpin[i], brightness);
  }
}
