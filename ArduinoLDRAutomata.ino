
#define LED_PIN  9
#define LDR_PIN  A0

int diff = 50;    // accepted diff between recent values
int threshold = 800;
boolean doTurnOn = false;

int value;
long currTime, prevTime = 0;


void setup() {
  pinMode(LED_PIN, OUTPUT);
  // timer start
  prevTime = millis();
}


void loop() {
  value = analogRead(LDR_PIN);
  currTime = millis();
  
  if (value > 800) doTurnOn = true;
  else doTurnOn = false;
  
  if (currTime - prevTime > 100) {
    if (doTurnOn) digitalWrite(LED_PIN, HIGH);
    else digitalWrite(LED_PIN, LOW);
    // timer restart
    prevTime = currTime;
  }
}
