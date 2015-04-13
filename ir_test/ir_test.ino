#include <IRremote.h>

int RECV_PIN = 11;
IRrecv irrecv(RECV_PIN);
decode_results dec_rslt;

void setup()
{
  Serial.begin(9600);
  Serial.println("Start running");
  irrecv.enableIRIn();  // start the receiver  
}

void loop() {
  if (irrecv.decode(&dec_rslt))
  {
    Serial.println(dec_rslt.value, HEX);
    irrecv.resume();  // Receive next value; 
  } 
}
