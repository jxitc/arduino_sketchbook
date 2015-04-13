#include <IRremote.h>

// http://diy.elecfans.com/P/166/751 
const int irReceiverPin = 11;
IRrecv irrecv(irReceiverPin);
decode_results results;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
}


// show protocol type
void showIRProtocol(decode_results *results) {
  Serial.print("Protocol: ");
  switch(results->decode_type) {
    case NEC:
      Serial.print("NEC");
      break;
    case SONY:
      Serial.print("SONY");
      break;
    case RC5:
      Serial.print("RC5");
      break;
    case RC6:
      Serial.print("RC6");
      break;
    default:
      Serial.print("Unkown encoding");
  }

  // Show IR code
  Serial.print(", irCode: ");
  Serial.print(results->value, HEX);
  Serial.print(", bits: ");
  Serial.println(results->bits);
}


void loop() {
  if (irrecv.decode(&results)) {
    showIRProtocol(&results);
    irrecv.resume(); // continue receive next signal
  }
}
