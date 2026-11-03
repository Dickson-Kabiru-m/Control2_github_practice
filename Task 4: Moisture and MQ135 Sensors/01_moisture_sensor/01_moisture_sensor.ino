#define AOUT_PIN 36
#define THRESHOLD 1488

void setup() {
  Serial.begin(115200);
  analogSetAttenuation(ADC_11db);
  Serial.println("Moisture sensor ready");
}

void loop() {
  int value = analogRead(AOUT_PIN);

  Serial.print("Moisture ADC: ");
  Serial.print(value);
  Serial.print("  --> ");
  Serial.println(value > THRESHOLD ? "DRY" : "WET");

  delay(1000);
}
