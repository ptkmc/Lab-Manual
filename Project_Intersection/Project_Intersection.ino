// Traffic Lights
/* This program controls two traffic lights, each with a red, yellow, and green lamp controlling two different streets in a busy city intersection.

Only one street in this intersection has a crosswalk for pedestrians. A crosswalk signal shines white when it is safe for pedestrians to cross. It will then flash an orange color indicating the lights are about to change. Once it the lights change and it is no longer safe to walk across the street, the orange cross-walk light ceases to flash and shines steadily until it is safe to cross again.

Pedestrians are also given a cross-walk button they can press to stop traffic and be allowed to cross the intersection safely.*/
int NorthStreet[]={13,12,11};
int SouthStreet[]={10,9,8};
int CrossWalk[]={7,6,5};

int TrafficFlowTime = 10000;
int WarningPeriod = 2000;

void setup(){
  Serial.begin(9600);
// prepare digital pins for the lights
  for (int x=5; x<14; x++ ){ 
      pinMode(x, OUTPUT);
   }
  
  }

void loop(){
  // set the initial state of the lights
  LightCycle(NorthStreet,SouthStreet);
  LightCycle(SouthStreet,NorthStreet);

}

void LightCycle(int LightSet1[], int LightSet2[]){
  // LightSet1 is red
  digitalWrite(LightSet1[0],HIGH);
  digitalWrite(LightSet1[1],LOW);
  digitalWrite(LightSet1[2],LOW);
  
  // LightSet2 is green
  digitalWrite(LightSet2[0],LOW);
  digitalWrite(LightSet2[1],LOW);
  digitalWrite(LightSet2[2],HIGH);
  
  // Let traffic flow
  LightWait(TrafficFlowTime);
  
  // Change LightSet2 to yellow
  digitalWrite(LightSet2[1], HIGH);
  digitalWrite(LightSet2[2],LOW);
  
  
  // Wait for warning period
  LightWait(WarningPeriod);
  }
  
  void LightWait(int DelayTime){
    delay(DelayTime);
}

void CrossingRequest(){

}
