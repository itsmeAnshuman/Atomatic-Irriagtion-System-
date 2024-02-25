#include <LiquidCrystal.h>

LiquidCrystal lcd(13, 12, 11, 10, 9, 8);

const uint8_t SENSOR_PIN = A0; // Use smaller data type uint8_t for sensor pin
const uint8_t MOTOR_PIN = 7;   // Use smaller data type uint8_t for motor pin

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);

  lcd.begin(20, 4);
  lcd.print(F(" THE BRIGHT LIGHT\nSMART PLANT WATERING")); // Combine LCD print statements
  delay(2500);
}

void loop() {
  int Sensor_val = analogRead(SENSOR_PIN);
  uint8_t Moisture = map(Sensor_val, 0, 1019, 0, 100); // Use uint8_t for moisture, as it's a percentage (0-100)

  lcd.setCursor(0, 2);
  lcd.print(F("MOISTURE: "));
  lcd.print(Moisture);
  lcd.print(F("%       "));

  if (Moisture < 30) {
    lcd.setCursor(0, 3);
    lcd.print(F("MOTOR: ON               "));
    digitalWrite(MOTOR_PIN, LOW);
  }
}
