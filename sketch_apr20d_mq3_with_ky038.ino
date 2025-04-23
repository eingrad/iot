#define ALCOHOL_SENSOR_PIN 34  // MQ-3 analog pin
#define SOUND_SENSOR_PIN 27    // KY-038 digital pin

int alcoholThreshold = 350;

bool isSoundDetected() {
  return digitalRead(SOUND_SENSOR_PIN) == LOW; // Quick single check
}

int getAverageAlcoholLevel() {
  int total = 0;
  for (int i = 0; i < 5; i++) {
    total += analogRead(ALCOHOL_SENSOR_PIN);
    delay(5);
  }
  return total / 5;
}

void setup() {
  Serial.begin(115200);
  pinMode(SOUND_SENSOR_PIN, INPUT);
  Serial.println("MQ-3 warming up...");
  delay(10000); // Reduced warm-up to 10 sec for faster testing
  Serial.println("Ready.");
}

void loop() {
  if (isSoundDetected()) {
    Serial.println("Sound detected! Testing...");
    delay(500); // Shorter blow time

    int alcoholValue = getAverageAlcoholLevel();
    Serial.print("Alcohol: ");
    Serial.println(alcoholValue);

    if (alcoholValue > alcoholThreshold) {
      Serial.println("⚠️ Alcohol detected!");
    } else {
      Serial.println("✅ No alcohol.");
    }

    delay(1500); // Short pause before next round
  }

  delay(100); // Faster loop
}
