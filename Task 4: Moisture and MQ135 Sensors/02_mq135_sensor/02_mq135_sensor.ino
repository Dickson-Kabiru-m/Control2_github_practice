const int aoPin = 34;
const int doPin = 2;
const unsigned long warmupMs = 120000;

int cleanAirBaseline = 0;

void setup() {
  Serial.begin(115200);
  pinMode(doPin, INPUT);
  analogSetAttenuation(ADC_11db);

  Serial.println("MQ135 warming up. Keep the sensor in clean air.");
  delay(warmupMs);
  cleanAirBaseline = analogRead(aoPin);
  Serial.print("Clean-air baseline: ");
  Serial.println(cleanAirBaseline);
}

void loop() {
  int raw = analogRead(aoPin);
  int digitalAlarm = digitalRead(doPin);
  int change = raw - cleanAirBaseline;

  Serial.print("Raw=");
  Serial.print(raw);
  Serial.print("  DO=");
  Serial.print(digitalAlarm);
  Serial.print("  Air change: ");

  if (change > 300) {
    Serial.println("HIGH");
  } else if (change > 100) {
    Serial.println("MEDIUM");
  } else {
    Serial.println("LOW");
  }

  delay(1000);
}
