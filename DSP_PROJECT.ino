#include <Wire.h>  // library for i2c communication to the
#include <Adafruit_Sensor.h> // both this library is if we're using adafruit sensors if hindi naman I can change the code later on
#include <Adafruit_SHT31.h>  

// Define of sensors and their respective pins sa arduino uno
const int waterSensorPin = A0;  // Analog pin for water sensor
const int soilMoisturePin = A1; // Analog pin for soil moisture sensor

// for the 15 minute intervels (in milliseconds)
const unsigned long interval = 900000; // 15 minutes

// Creating sensor objects (will modify when we get the needed hardware)
Adafruit_SHT31 sht31 = Adafruit_SHT31();

void setup() {
  // to Initialize yung serial communication
  Serial.begin(9600);

  // Initialize sensors  (will modify when needed)
  if (!sht31.begin(0x44)) {
    Serial.println("Couldn't find SHT31 sensor!");
    while (1);
  }
}

void loop() {
  // Check if it's time to collect data
  static unsigned long previousMillis = 0;
  unsigned long currentMillis = millis();

  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;

    // this part po will be the collecting of data from the sensors 
    int waterLevel = analogRead(waterSensorPin);
    int soilMoisture = analogRead(soilMoisturePin);
    float temperature = sht31.readTemperature();

    // dito po IpriPrint yung sensor readings onto the serial monitor
    Serial.print("Water Level: ");
    Serial.println(waterLevel);
    Serial.print("Soil Moisture: ");
    Serial.println(soilMoisture);
    Serial.print("Temperature: ");
    Serial.println(temperature);

    // this part yung ilalagay naten kung saan  Isasave data yung either through an SD card or send it to a server
  }
}
