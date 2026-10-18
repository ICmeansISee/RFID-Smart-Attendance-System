# RFID-Based Smart Attendance System

## Project Overview
An RFID-based attendance system built using Arduino Uno R3, an MFRC522 RFID reader, and a 16x2 I2C LCD. The system identifies registered students by their RFID card UID and displays their attendance status on the LCD and Serial Monitor.

## Features
- Identifies registered students: Ayush, Ishan, and Divya
- Marks attendance when a registered RFID card is scanned
- Prevents duplicate attendance during the same running session
- Rejects unknown RFID cards
- Displays student names and attendance status on the LCD
- Prints scan details to the Serial Monitor
- Simulated using Wokwi

## Hardware Components
- Arduino Uno R3
- MFRC522 RFID reader
- RFID cards
- 16x2 I2C LCD
- Jumper wires

## Circuit Connections

### RC522 RFID Reader

| RC522 Pin | Arduino Uno Pin |
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

| LCD Pin | Arduino Uno Pin |
|---|---|
| GND | GND |
| VCC | 5V |
| SDA | A4 |
| SCL | A5 |

## Required Libraries
- MFRC522
- LiquidCrystal_I2C

The project also uses the built-in SPI and Wire libraries.

## How It Works
1. The Arduino initializes the RFID reader and LCD.
2. A student scans an RFID card.
3. The system reads the card UID and compares it with the registered UIDs.
4. A recognized student is shown by name, and attendance is marked as present.
5. A repeated scan shows that attendance has already been marked.
6. An unregistered card is rejected.

## Registered Students
- Ayush
- Ishan
- Divya

Each student must have a unique UID matching their RFID card.

## Simulation
**Wokwi Project:** https://wokwi.com/projects/478195688271631361

## Source Code
The Arduino program is available in `sketch.ino` in this repository.

## Limitations
Attendance is stored in RAM, so records reset when the Arduino or simulation restarts. This is an educational prototype and does not yet store permanent attendance records.

## Future Improvements
- Record attendance date and time
- Store attendance permanently
- Support exporting attendance records
- Add more registered students

## Author
- Anurag (Roll No - 21)
- Ayush Raj (Roll No - 22)
- Aryan Raj (Roll No - 23)
- Divya Jyoti Mehta (Roll No - 24)
- Ishan Chetan (Roll No - 25) is **Main**
