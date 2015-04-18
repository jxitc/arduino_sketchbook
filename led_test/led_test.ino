int led =  2;

void setup() {
  Serial.begin(9600);
  pinMode(led, OUTPUT);
}

void loop() {
   Serial.println("Running");

  digitalWrite(led, HIGH);

}
