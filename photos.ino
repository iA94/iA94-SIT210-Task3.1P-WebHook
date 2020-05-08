int led = D7;
 // The on-board LED
int analogvalue = 0;

void setup() {
   pinMode(A0, INPUT);// Subscribe to the integration response event
  Particle.subscribe("hook-response/photoresistors", myHandler, MY_DEVICES);
  //Particle.variable("analogvalue", &analogvalue, INT);
   
  
}

void myHandler(const char *event, const char *data) {
  // Handle the integration response
}

void loop() {
  // Get some data
   analogvalue = analogRead(A0);
   String data = String(analogvalue);
  
  // Trigger the integration
  Particle.publish("photoresistors", data, PRIVATE);
  // Wait 60 seconds
  delay(6000);
}