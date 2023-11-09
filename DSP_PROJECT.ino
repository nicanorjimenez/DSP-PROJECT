#include <Wire.h>
#include <RTClib.h>
#include <SPI.h>
#include <SD.h>

// Define the SD card's chip select (CS) pin
const int chipSelect = 10;  // Replace with the actual CS pin connected to the SD card module

// Analog pins for your sensors
const int waterSensorPin = A0;
const int soilMoisturePin = A1;
const int temperatureSensorPin = A2;

File dataFile;
RTC_DS3231 rtc;

void setup() {
  Serial.begin(9600);
  Serial.println("Initializing SD card...");

  if (SD.begin(chipSelect)) {
    Serial.println("SD card initialized.");
    dataFile = SD.open("data.txt", FILE_WRITE);

    if (dataFile) {
      dataFile.println("Timestamp, Water Level, Soil Moisture, Temperature");
      dataFile.close();
    }
  } else {
    Serial.println("SD card initialization failed.");
  }

  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }

  if (!rtc.isrunning()) {
    Serial.println("RTC is not running! Setting time...");
    rtc.adjust(DateTime(F(__DATE__), F(__TIME__)));
  }
}

void loop() {
  DateTime now = rtc.now();

  // Read sensor values
  int waterLevel = analogRead(waterSensorPin);
  int soilMoisture = analogRead(soilMoisturePin);
  int temperature = analogRead(temperatureSensorPin);

  // Generate a timestamp in the format "YYYY-MM-DD HH:MM:SS"
  String timestamp = String(now.year()) + "-" + formatTime(now.month()) + "-" + formatTime(now.day()) + " " +
                     formatTime(now.hour()) + ":" + formatTime(now.minute()) + ":" + formatTime(now.second());

  // Open the data file and save the data
  dataFile = SD.open("data.txt", FILE_WRITE);

  if (dataFile) {
    dataFile.print(timestamp);
    dataFile.print(", ");
    dataFile.print(waterLevel);
    dataFile.print(", ");
    dataFile.print(soilMoisture);
    dataFile.print(", ");
    dataFile.println(temperature);
    dataFile.close();
  } else {
    Serial.println("Error opening data file.");
  }

  delay(900000);  // 15-minute interval
}

String formatTime(int value) {
  if (value < 10) {
    return "0" + String(value);
  } else {
    return String(value);
  }
}
