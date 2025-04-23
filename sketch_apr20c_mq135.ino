// MQ-135 with ESP32 and Buzzer - Air Quality Monitor

const int mq135Pin = 34;     // Analog pin for MQ-135 sensor
const int buzzerPin = 15;    // Digital pin for buzzer

void setup() {
  Serial.begin(115200);           // Start Serial Monitor
  pinMode(buzzerPin, OUTPUT);     // Set buzzer pin as output
  digitalWrite(buzzerPin, LOW);   // Ensure buzzer is off
}

// Function to get air quality status
String getAirQualityStatus(int value) {
  if (value <= 300) return "Fresh Air";
  else if (value <= 600) return "Moderate";
  else if (value <= 1000) return "Poor Air";
  else if (value <= 2000) return "Unhealthy";
  else return "Very Unhealthy";
}

void loop() {
  int airValue = analogRead(mq135Pin);        // Read sensor
  String status = getAirQualityStatus(airValue); // Get quality status

  // Print to Serial Monitor
  Serial.print("Air Quality Value: ");
  Serial.print(airValue);
  Serial.print(" - Status: ");
  Serial.println(status);

  // Trigger buzzer if air quality is poor or worse
  if (airValue > 1000) {
    digitalWrite(buzzerPin, HIGH); // Turn on buzzer
    delay(1000);                   // Buzzer on for 1 second
    digitalWrite(buzzerPin, LOW);  // Turn off buzzer
  }

  delay(2000);  // Wait before next reading
}
