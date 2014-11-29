#include <DS1624.h>
#include <Wire.h>
#include <LiquidCrystal.h>

LiquidCrystal lcd(13,12,11,10,9,8);
//Знак "градус"
byte degreeS[8] = {
0b00110,
0b01001,
0b01001,
0b00110,
0b00000,
0b00000,
0b00000,
0b00000
};

DS1624 temperature(0x48);

void setup() {  
  lcd.begin(16,2);
  temperature.start();
  lcd.createChar(0, degreeS);
} 

void loop() {
  lcd.print("Temp:");
  //Получаемпоказания с датчика
  temperature.getTemp();
  delay(200);
  lcd.setCursor(0,1);
  lcd.print(temperature.getTemp());
  //Выводим на экран температуру
  lcd.write(byte(0));
  lcd.print("C");
  delay(200);
  lcd.home();
  lcd.clear();
}
