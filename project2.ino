#define moisturePin A0   // Soil Moisture Sensor Analog Output
#define relayPin 7       // Relay module connected to pin 7

// Moisture Thresholds (Adjust based on testing)
#define dryThreshold 700   // Too dry (Pump ON)
#define wetThreshold 400   // Too wet (Pump OFF)

void setup() {
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, HIGH); // Keep relay OFF initially
  Serial.begin(9600);
}

void loop() {
  int moistureLevel = analogRead(moisturePin); // Read soil moisture (0-1023)

  Serial.print("Soil Moisture Level: ");
  Serial.println(moistureLevel);

  if (moistureLevel > dryThreshold) { // Soil is too dry (High value)
    digitalWrite(relayPin, LOW);  // Turn ON water pump
    Serial.println("Soil is dry - Watering ON 💧");
  } 
  else if (moistureLevel < wetThreshold) { // Soil is too wet (Low value)
    digitalWrite(relayPin, HIGH); // Turn OFF water pump
    Serial.println("Soil is too wet - Watering OFF ❌");
  } 
  else {
    digitalWrite(relayPin, HIGH); // Keep pump OFF in normal range
    Serial.println("Soil moisture is perfect! ✅");
  }

  delay(1000); // Check moisture every second
}
