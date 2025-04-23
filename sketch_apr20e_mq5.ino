#define MQ5PIN 34  // MQ-5 analog output connected to GPIO34

void setup() {
  Serial.begin(115200);
  Serial.println("ESP32 MQ-5 Gas Sensor Monitoring");
}

void loop() {
  int gasValue = analogRead(MQ5PIN); // Read analog value

  Serial.println("------ MQ-5 Sensor Data ------");
  Serial.print("Gas Value: ");
  Serial.println(gasValue);

  if (gasValue > 3000) {
    Serial.println("⚠️ High gas level detected!");
  } else {
    Serial.println("Gas level normal.");
  }

  Serial.println();
  delay(2000);
}