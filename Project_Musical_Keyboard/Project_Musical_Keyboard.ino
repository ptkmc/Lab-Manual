int button_C = 9;
int button_D = 8;
int button_E = 7;
int button_F = 6;
int button_G = 5;
int button_A = 4;
int button_B = 3;
int button_Cup = 2;

int speaker = 13;

int buttonstate_C = 0;
int buttonstate_D = 0;
int buttonstate_E = 0;
int buttonstate_F = 0;
int buttonstate_G = 0;
int buttonstate_A = 0;
int buttonstate_B = 0;
int buttonstate_Cup = 0;

// int x = 2;

// NOTES        'c'  , 'd',  'e',  'f',  'g', 'a',  'b',  'C'
int tones[] = { 1915, 1700, 1519, 1432, 1275, 1136, 1014, 956 }; //freq
int Cur_tone = 0;

void setup()
{
 // initialize serial communications at 9600 bps:
 // Serial.begin(9600);
  pinMode(button_C, INPUT);
  pinMode(button_D, INPUT);
  pinMode(button_E, INPUT);
  pinMode(button_F, INPUT);
  pinMode(button_G, INPUT);
  pinMode(button_A, INPUT);
  pinMode(button_B, INPUT);
  pinMode(button_Cup, INPUT);

  pinMode(speaker, OUTPUT);
}

void loop()
{
  buttonstate_C = digitalRead(button_C);
  buttonstate_D = digitalRead(button_D);
  buttonstate_E = digitalRead(button_E);
  buttonstate_F = digitalRead(button_F);
  buttonstate_G = digitalRead(button_G);
  buttonstate_A = digitalRead(button_A);
  buttonstate_B = digitalRead(button_B);
  buttonstate_Cup = digitalRead(button_Cup);

  /*for (x=2; x<10;x++){
    Serial.print("\n button ");
    Serial.print(x );
    Serial.print(" is " );*/
//  Serial.print(digitalRead(x)); 

//  Serial.print("\n");

  if((buttonstate_C == HIGH) || (buttonstate_E == HIGH) || 
    (buttonstate_G == HIGH) || (buttonstate_D == HIGH) || 
    (buttonstate_F == HIGH) || (buttonstate_A == HIGH) || 
    (buttonstate_B == HIGH) || (buttonstate_Cup == HIGH) )
  { 
    if (buttonstate_C == HIGH)
    {
      Cur_tone = 1915;
    }
    if (buttonstate_D == HIGH)
    {
      Cur_tone = 1700;
    }
    if (buttonstate_E == HIGH)
    {
      Cur_tone = 1519;
    }
    if (buttonstate_F == HIGH)
    {
      Cur_tone = 1432;
    }
    if (buttonstate_G == HIGH)
    { 
      Cur_tone = 1275;
    }
    if (buttonstate_A == HIGH)
    {
      Cur_tone = 1136;
    }
    if (buttonstate_B == HIGH)
    {
      Cur_tone = 1014;
    }
    if (buttonstate_Cup == HIGH)
    {
      Cur_tone = 956;
    }
        
    digitalWrite(speaker, HIGH);
    delayMicroseconds(Cur_tone);
    digitalWrite(speaker, LOW);
    delayMicroseconds(Cur_tone);
  }
  else //in case no button is pressed , close the piezo
  {
    digitalWrite(speaker, LOW);
  }

}
