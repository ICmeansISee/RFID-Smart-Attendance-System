# RFID-Based Smart Attendance System

## Project Overview
This project demonstrates an RFID-based attendance system using an Arduino Uno R3, an MFRC522 RFID reader, and a 16x2 I2C LCD. When a registered RFID card is scanned, the system identifies the student and displays the attendance status on the LCD and Serial Monitor.

## Components Used
- Arduino Uno R3
- MFRC522 RFID reader
- RFID card or tag
- 16x2 I2C LCD
- Jumper wires
- Wokwi online simulator

## Circuit Connections

### RC522 RFID Reader

| RC522 Pin | Arduino Uno |
|---|---|
| SDA / SS | D10 |
| SCK | D13 |
| MOSI | D11 |
| MISO | D12 |
| RST | D9 |
| 3.3V | 3.3V |
| GND | GND |
| IRQ | Not connected |

### I2C LCD

| LCD Pin | Arduino Uno |
|---|---|
| GND | GND |
| VCC | 5V |
| SDA | A4 |
| SCL | A5 |

## Required Libraries
Install or include these Arduino libraries:
- `MFRC522`
- `LiquidCrystal_I2C`

The code also uses the built-in `SPI` and `Wire` libraries.

## How It Works
1. The system initializes the RFID reader and LCD.
2. A user scans an RFID card.
3. The Arduino reads the card's UID.
4. If the UID matches the registered student's UID, attendance is marked as present.
5. Unknown cards are rejected.
6. The attendance status is displayed on the LCD and Serial Monitor.

## Simulation
The project was tested using the Wokwi online simulator.

**Wokwi Project Link:** https://wokwi.com/projects/478195688271631361

## Important Notes
- The example code uses a registered UID of `01:02:03:04` and the sample student name `Ishan`. Update these values to match your own card and student details.
- Attendance is stored in RAM, so the attendance flag resets when the Arduino restarts.
- This is an educational prototype, not a production attendance system.

## Future Improvements
- Support multiple registered students.
- Store attendance records with date and time.
- Add an SD card or database for permanent storage.
- Prevent duplicate attendance across restarts.
- Add a real-time clock module.

## Author
- Anurag (Roll No - 21)
- Ayush Raj (Roll No - 22)
- Aryan Raj (Roll No - 23)
- Divya Jyoti Mehta (Roll No - 24)
- Ishan Chetan (Roll No - 25)
