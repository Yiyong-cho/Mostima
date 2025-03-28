// C++ code
//
#include <LiquidCrystal.h>
LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int sensorPin = A0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.cursor();
  lcd.blink();
  lcd.home();
  lcd.print("Hello, LCD");
  lcd.setCursor(0,1);
  lcd.print("  Aurduino");
  delay(2000);
  lcd.clear();
}
int tc = 0;

void loop()
{
  int reading = analogRead(sensorPin);
  if (tc!=reading)
  {
    lcd.clear();
    float voltage = reading /1024.0;
    float tempertureC = (voltage*5 - 0.5) * 100;
    lcd.print((int)(tempertureC+0.5));
    lcd.write(0xB2);
    lcd.print("C");
    tc = reading;
    delay(1000);
  }
}