const int moisturePin = 36;
const int mq135AnalogPin = 34;
const int mq135DigitalPin = 2;
const int moistureThreshold = 1488;
const unsigned long warmupMs = 120000;

int cleanAirBaseline = 0;

void setup() {
  Serial.begin(115200);
  pinMode(mq135DigitalPin, INPUT);
  analogSetAttenuation(ADC_11db);

  Serial.println("Starting combined sensor monitor");
  Serial.println("MQ135 warming up. Keep the sensor in clean air.");
  delay(warmupMs);

  cleanAirBaseline = analogRead(mq135AnalogPin);
  Serial.print("MQ135 warm-up complete. Baseline: ");
  Serial.println(cleanAirBaseline);
}

void loop() {
  int moisture = analogRead(moisturePin);
  int airQuality = analogRead(mq135AnalogPin);
  int alarm = digitalRead(mq135DigitalPin);
  int airChange = airQuality - cleanAirBaseline;

  Serial.print("Moisture=");
  Serial.print(moisture);
  Serial.print(moisture > moistureThreshold ? " DRY" : " WET");
  Serial.print(" | MQ135=");
  Serial.print(airQuality);
  Serial.print(" | DO=");
  Serial.print(alarm);
  Serial.print(" | Air change=");

  if (airChange > 300) {
    Serial.println("HIGH");
  } else if (airChange > 100) {
    Serial.println("MEDIUM");
  } else {
    Serial.println("LOW");
  }

  delay(1000);
}
