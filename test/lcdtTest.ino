//YWROBOT
//Compatible with the Arduino IDE 1.0
//Library version:1.1
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);  // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup()
{
  lcd.init();                  // 初始化LCD
  lcd.backlight();             //设置LCD背景等亮
}

void loop()
{
  lcd.setCursor(0,0);                //设置显示指针
  lcd.print("LCD1602 iic Test");     //输出字符到LCD1602上
  lcd.setCursor(0,1);
  lcd.print("         by L.L.");
  delay(1000);
}