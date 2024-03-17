

#define D1_PIN D0  
#define D2_PIN D1
#define D3_PIN D2
#define D4_PIN D5
#define D5_PIN D6
#define LED_PIN D7

void setup() {
  Serial.begin(9600);
  pinMode(D1_PIN, INPUT);
  pinMode(D2_PIN, INPUT);
  pinMode(D3_PIN, INPUT);
  pinMode(D4_PIN, INPUT);
  pinMode(D5_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int flame_state1 = digitalRead(D1_PIN);
  int flame_state2 = digitalRead(D2_PIN);
  int flame_state3 = digitalRead(D3_PIN);
  int flame_state4 = digitalRead(D4_PIN);
  int flame_state5 = digitalRead(D5_PIN);

  if (flame_state1 == HIGH || flame_state2 == HIGH || flame_state3 == HIGH || flame_state4 == HIGH || flame_state5 == HIGH){
    digitalWrite(LED_PIN, HIGH);
    Serial.println("API API API");}
  else{
    digitalWrite(LED_PIN, LOW);
    Serial.println("Tidak ada api");}
}
