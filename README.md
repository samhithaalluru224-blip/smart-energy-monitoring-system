
**SMART ENERGY MONITORING SYSTEM**

 Overview

The **Smart Energy Home System** is an Arduino-based project designed to monitor environmental conditions and control electrical devices automatically. It integrates multiple sensors to collect real-time data such as temperature, humidity, air quality, distance, and current consumption.

The system displays this information on an LCD and performs automatic actions like turning ON/OFF appliances and triggering alerts.

---

 Objectives

* Monitor temperature and humidity
* Detect air quality (dust/smoke levels)
* Measure distance for proximity detection
* Track electrical current usage
* Automate appliance control using relay
* Provide safety alerts using buzzer

---

 Components Used

* Arduino Uno
* Breadboard
* I2C LCD Display (16x2)
* DHT11 Temperature & Humidity Sensor
* Ultrasonic Sensor (HC-SR04)
* Dust/Smoke Sensor
* ACS712 Current Sensor
* Relay Module
* Buzzer
* Motor (Load)
* Jumper Wires
* External 12V Power Supply

---

 Working Principle

1. Sensors collect real-time data:

   * DHT11 → Temperature & Humidity
   * Ultrasonic → Distance (object detection)
   * Dust Sensor → Air quality
   * ACS712 → Current consumption

2. Arduino processes all sensor data.

3. LCD displays:

   * Temperature
   * Distance
   * Dust level

4. Automatic control:

   * If distance < threshold → Relay turns ON (appliance ON)
   * If dust level is high → Buzzer turns ON (alert)

5. System runs continuously in a loop.

---

Circuit Connections (Summary)

| Component       | Arduino Pin |
| --------------- | ----------- |
| DHT11           | D2          |
| Ultrasonic TRIG | D4          |
| Ultrasonic ECHO | D5          |
| Relay           | D7          |
| Buzzer          | D8          |
| ACS712          | A0          |
| Dust Sensor     | A1          |
| LCD SDA         | A4          |
| LCD SCL         | A5          |

👉 All VCC → 5V
👉 All GND → GND

---

Power Supply

* Arduino powered via USB
* Motor powered using external 12V supply
* Relay used to isolate high-power load

---

 Features

* Real-time monitoring
* Automatic device control
* Energy usage tracking
* Safety alert system
* User-friendly LCD display

---

 Applications

* Smart homes
* Energy management systems
* Air quality monitoring
* Industrial safety systems

---

 Limitations

* Ultrasonic sensor cannot identify objects (only distance)
* Basic automation (no AI/IoT cloud integration)

---

 Future Improvements

* Add IoT (mobile app monitoring)
* Use WiFi module (ESP8266)
* Improve accuracy with advanced sensors
* Add data logging

---

 Conclusion

This project demonstrates how embedded systems and sensors can be combined to create an intelligent and automated home system that improves energy efficiency, safety, and convenience.

---

AUTHOR
Samhitha.A
Amrutha.K



