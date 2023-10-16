# DSP-PROJECT
the codes posted here are used for our project "DSP Enhanced Crop Yield Estimation Using Sensors"

## Overview
This Arduino project is designed to collect sensor data from water level, soil moisture, and temperature sensors. The data is timestamped and saved to an external SD card. The project is intended to run for two weeks with 15-minute data collection intervals.

## Hardware Components
- Arduino Uno
- External SD card module
- Real-time clock (RTC) module (e.g., DS3231)
- Water level sensor
- Soil moisture sensor
- Temperature sensor
- power supply

## Wiring
- Connect the water level, soil moisture, and temperature sensors to the analog pins of the Arduino Uno.
- Connect the RTC module to the I2C pins (A4 and A5) of the Arduino Uno.
- Connect the SD card module to the Arduino Uno and configure the chip select (CS) pin (e.g., to pin 10).
- Ensure proper power connections for all components.

## Dependencies
- Arduino IDE
- Libraries: `RTClib` for managing the real-time clock and `SD` for working with the SD card.

## Usage
1. Upload the Arduino code to your Arduino Uno using the Arduino IDE.
2. Ensure that the external SD card is properly formatted and inserted into the SD card module.
3. Power the Arduino Uno and leave the project running for the desired data collection period (two weeks).
4. The data will be stored on the SD card in a file named `data.txt`, along with timestamps.

## Data Format
The data is saved in `data.txt` in the following format:


