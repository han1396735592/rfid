
#include "DHT.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
// set the LCD address to 0x27 for a 16 chars and 2 line display
extern DHT dht;

void lcd_init(void) {
  lcd.init();      // 初始化LCD
  lcd.backlight(); //设置LCD背景等亮
}

void show_main_ui(int index) {
  lcd.setCursor(0, 0); //设置显示指针
  lcd.print("input key -pd+pu      ");
  lcd.setCursor(0, 1);
  switch (index) {
  case 0:
    lcd.print("0:RFID read card    ");
    break;
  case 1:
    lcd.print("1:RFID  led        ");
    break;
  case 2:
    lcd.print("2:Te,hu monitor     ");
    break;
  case 3:
    lcd.print("3:rgb led          ");
    break;
  }
}

void temperature_and_humidity_monitoring() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("type Temperature");
  lcd.setCursor(0, 1);
  lcd.print("humidity monitor");
  int lasth = dht.readHumidity();
  int lastt = dht.readTemperature();
  delay(1000);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature:");
  lcd.print(lastt);
  lcd.setCursor(0, 1);
  lcd.print("humidity:");
  lcd.print(lasth);

  while (1) {
    int h = dht.readHumidity();
    int t = dht.readTemperature();
    if (h != lasth && t != lastt) {
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Temperature:");
      lcd.print(t);
      lcd.setCursor(0, 1);
      lcd.print("humidity:");
      lcd.print(h);
      lasth = h;
      lastt = t;
    }
    if (irrecv.decode(&results)) {

      switch (results.value) {
      case Infrared_eq:
        return;
      }
      irrecv.resume();
    }
  }
}
