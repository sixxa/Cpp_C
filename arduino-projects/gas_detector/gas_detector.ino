#include <dht.h>

dht DHT;

#define DHT11_PIN 7
const int threshold = 500; // Adjust this threshold based on your sensor and environment
const int analogPin = A0;
const int buzzerPin = 9; // Connect the buzzer to digital pin 9

void setup() {
  Serial.begin(9600); // Initialize serial communication
  pinMode(buzzerPin, OUTPUT); // Set the buzzer pin as an OUTPUT
}

void loop() {
  int sensorValue = analogRead(analogPin);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue); // Print raw sensor value to Serial Monitor

  if (sensorValue > threshold) {
    Serial.println("Fire Detected!"); // Print if fire is detected
    soundBuzzer(); // Sound the buzzer when fire is detected
  } else {
    Serial.println("No Fire Detected."); // Print if no fire is detected
    noTone(buzzerPin); // Turn off the buzzer
  }

  int chk = DHT.read11(DHT11_PIN);
  Serial.print("Temperature = ");
  Serial.print(DHT.temperature);
  Serial.println(" °C");
  Serial.print("Humidity = ");
  Serial.print(DHT.humidity);
  Serial.println(" %");

  delay(2000); // Adjust the delay based on your requirements
}

void soundBuzzer() {
  tone(buzzerPin, 1000); // Sound the buzzer at a frequency of 1000 Hz
  delay(2000); // Sound the buzzer for 2 seconds (adjust as needed)
  noTone(buzzerPin); // Turn off the buzzer
}
