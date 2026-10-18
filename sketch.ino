#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN);
LiquidCrystal_I2C lcd(0x27, 16, 2);

struct Student {
  const char* uid;
  const char* name;
  bool attendanceMarked;
};

Student students[] = {
  {"01:02:03:04", "Ishan", false},
  {"11:22:33:44", "Ayush", false},
  {"AA:BB:CC:DD", "Divya", false}
};

const int studentCount = sizeof(students) / sizeof(students[0]);

String readUID() {
  String uid = "";

  for (byte i = 0; i < rfid.uid.size; i++) {
    if (i > 0) uid += ":";
    if (rfid.uid.uidByte[i] < 0x10) uid += "0";
    uid += String(rfid.uid.uidByte[i], HEX);
  }

  uid.toUpperCase();
  return uid;
}

void setup() {
  Serial.begin(9600);
  SPI.begin();
  rfid.PCD_Init();

  Wire.begin();
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("RFID ATTENDANCE");
  lcd.setCursor(0, 1);
  lcd.print("Scan Your Card");

  Serial.println("RFID SMART ATTENDANCE SYSTEM");
  Serial.println("System Ready. Scan your card...");
}

void loop() {
  if (!rfid.PICC_IsNewCardPresent()) return;
  if (!rfid.PICC_ReadCardSerial()) return;

  String uid = readUID();

  Serial.print("Card UID: ");
  Serial.println(uid);

  lcd.clear();

  bool found = false;

  for (int i = 0; i < studentCount; i++) {
    if (uid == students[i].uid) {
      found = true;

      Serial.print("Student: ");
      Serial.println(students[i].name);

      lcd.setCursor(0, 0);
      lcd.print("Name: ");
      lcd.print(students[i].name);

      if (!students[i].attendanceMarked) {
        students[i].attendanceMarked = true;

        Serial.println("Attendance: PRESENT");
        lcd.setCursor(0, 1);
        lcd.print("Present!");
      } else {
        Serial.println("Attendance: ALREADY MARKED");
        lcd.setCursor(0, 1);
        lcd.print("Already Marked");
      }

      break;
    }
  }

  if (!found) {
    Serial.println("Student: Unknown");
    Serial.println("Attendance: NOT MARKED");

    lcd.setCursor(0, 0);
    lcd.print("Unknown Card");
    lcd.setCursor(0, 1);
    lcd.print("Access Denied");
  }

  Serial.println("------------------------");

  rfid.PICC_HaltA();
  rfid.PCD_StopCrypto1();

  delay(2000);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Scan Your Card");
}
