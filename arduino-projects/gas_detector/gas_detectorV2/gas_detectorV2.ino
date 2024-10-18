#include <dht.h>
#include <BLEDevice.h>
#include <BLEUtils.h>
#include <BLEServer.h>

dht DHT;

#define DHT11_PIN 7
const int threshold = 500; // Adjust this threshold based on your sensor and environment
const int analogPin = A0;

BLECharacteristic *pCharacteristic;
bool fireDetected = false;

class MyServerCallbacks : public BLEServerCallbacks {
  void onConnect(BLEServer *pServer) {
    Serial.println("Connected to phone");
  }

  void onDisconnect(BLEServer *pServer) {
    Serial.println("Phone disconnected");
  }
};

void setup() {
  Serial.begin(115200);

  // Bluetooth setup
  BLEDevice::init("ESP32-Alerts");
  BLEServer *pServer = BLEDevice::createServer();
  pServer->setCallbacks(new MyServerCallbacks());

  BLEService *pService = pServer->createService(BLEUUID("4fafc201-1fb5-459e-8fcc-c5c9c331914b"));
  pCharacteristic = pService->createCharacteristic(
      BLEUUID("beb5483e-36e1-4688-b7f5-ea07361b26a8"),
      BLECharacteristic::PROPERTY_READ |
          BLECharacteristic::PROPERTY_WRITE);

  pService->start();
  BLEAdvertising *pAdvertising = pServer->getAdvertising();
  pAdvertising->start();

  delay(1000); // Allow time for Bluetooth initialization
}

void loop() {
  int sensorValue = analogRead(analogPin);

  Serial.print("Sensor Value: ");
  Serial.println(sensorValue); // Print raw sensor value to Serial Monitor

  if (sensorValue > threshold && !fireDetected) {
    Serial.println("Fire Detected!"); // Print if fire is detected

    // Send message to phone
    sendMessage("Fire Detected!");
    fireDetected = true;
  } else if (sensorValue <= threshold) {
    fireDetected = false;
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

void sendMessage(const char *message) {
  Serial.println("Sending message to phone");
  pCharacteristic->setValue(message);
  pCharacteristic->notify();
}
