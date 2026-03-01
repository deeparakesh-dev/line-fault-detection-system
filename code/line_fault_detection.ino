#include <LiquidCrystal.h>

// LCD pin mapping (RS, E, D4, D5, D6, D7)
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);

const int faultButton = 8;
const int sensePin = A0;

void setup() {
  pinMode(faultButton, INPUT_PULLUP);   // Button with internal pull-up
  lcd.begin(16, 2);
  lcd.clear();

  lcd.print("Telecom Fault");
  lcd.setCursor(0, 1);
  lcd.print("Detection Sys");
  delay(2000);

  lcd.clear();
}

void loop() {
  int buttonState = digitalRead(faultButton);
  int sensorValue = analogRead(sensePin);

  // Convert analog value (0-1023) to distance (0-10 km)
  float distance = map(sensorValue, 0, 1023, 100, 0) / 10.0;

  lcd.setCursor(0, 0);

  if (buttonState == LOW) {   // Button pressed
    lcd.print("SHORT CIRCUIT ");
    lcd.setCursor(0, 1);
    lcd.print("Fault Detected ");
  } 
  else {
    lcd.print("LINE STATUS OK ");
    lcd.setCursor(0, 1);
    lcd.print("Dist: ");
    lcd.print(distance, 1);   // One decimal value
    lcd.print(" km   ");      // Extra spaces to clear old data
  }

  delay(800);
}
