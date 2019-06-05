#include "infrared.h"
#define RGB_R 2

#define RGB_G 5

#define RGB_B 6

#define R__ A1

byte r_value = 0;
byte g_value = 0;
byte b_value = 0;

void rgb_led_init() {
  pinMode(RGB_R, OUTPUT);
  pinMode(RGB_G, OUTPUT);
  pinMode(RGB_B, OUTPUT);
  pinMode(R__, OUTPUT);
}

void setColor(int value) {
  switch (value) {
  case 7:
    r_value = 255;
    g_value = 255;
    b_value = 255;
    break;
  case 6:
    r_value = 255;
    g_value = 255;
    b_value = 0;
    break;
  case 5:
    r_value = 255;
    g_value = 0;
    b_value = 255;
    break;
  case 4:
    r_value = 255;
    g_value = 0;
    b_value = 0;
    break;
  case 3:
    r_value = 0;
    g_value = 255;
    b_value = 255;
    break;
  case 2:
    r_value = 0;
    g_value = 255;
    b_value = 0;
    break;
  case 1:
    r_value = 0;
    g_value = 0;
    b_value = 255;
    break;
  case 0:
    r_value = 0;
    g_value = 0;
    b_value = 0;
    break;
  }
}

void rgb_led() {
  lcd.clear();
  lcd.setCursor(0, 0); //设置显示指针
  lcd.print("type: rgb led");
  lcd.print("                      ");
  lcd.setCursor(0, 1); //设置显示指针
  lcd.print("please set color");
  lcd.print("                      ");
  delay(100);
  setColor(0);
  while (1) {

    // lcd.setCursor(0, 1); //设置显示指针
    // lcd.print("                                ");
    lcd.setCursor(0, 1); //设置显示指针
    lcd.print("r=");
    lcd.print(r_value);
    lcd.print("g=");
    lcd.print(g_value);
    lcd.print("b=");
    lcd.print(b_value);
    lcd.print("       ");
    analogWrite(RGB_R, r_value);
    analogWrite(RGB_G, g_value);
    analogWrite(RGB_B, b_value);

    if (irrecv.decode(&results)) {

      switch (results.value) {
      case Infrared_eq:
        return;
      case Infrared_0:
        setColor(0);
        break;
      case Infrared_1:
        setColor(1);
        break;
      case Infrared_2:
        setColor(2);
        break;
      case Infrared_3:
        setColor(3);
        break;
      case Infrared_4:
        setColor(4);
        break;
      case Infrared_5:
        setColor(5);
        break;
      case Infrared_6:
        setColor(6);
        break;
      case Infrared_7:
        setColor(7);
        break;
      case Infrared_ch__1:
        r_value--;
        break;
      case Infrared_ch__2:
        r_value++;
        break;
      case Infrared__l:
        g_value--;
        break;
      case Infrared__r:
        g_value++;
        break;
      case Infrared__1:
        b_value--;
        break;
      case Infrared__2:
        b_value++;
        break;
      case Infrared__s:
        set_r_value();
        lcd.setCursor(0, 0); //设置显示指针
        lcd.print("type: rgb led");
        lcd.print("                      ");
        break;
      }

      irrecv.resume();
    }
  }
}

void set_r_value() {

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("set rgb's ");

  lcd.setCursor(0, 1);
  int index = 0;
  byte lastV = map(analogRead(R__), 0, 1023, 0, 255);
  while (1) {

    if (index < 0 || index > 2) {
      index = 0;
    }
    byte temp_v = map(analogRead(R__), 0, 1023, 0, 255);
    switch (index) {
    case 0:
      lcd.setCursor(10, 0);
      lcd.print("r=");
      if (lastV != temp_v) {
        r_value = temp_v;
        lastV = temp_v;
        analogWrite(RGB_R, r_value);
      }
      break;
    case 1:
      lcd.setCursor(10, 0);
      lcd.print("g=");
      if (lastV != temp_v) {
        g_value = temp_v;
        lastV = temp_v;
        analogWrite(RGB_G, g_value);
      }
      break;
    case 2:
      lcd.setCursor(10, 0);
      lcd.print("b=");
      if (lastV != temp_v) {
        b_value = temp_v;
        lastV = temp_v;
        analogWrite(RGB_B, b_value);
      }
      break;
    }
    lcd.print(temp_v);
    lcd.print("     ");
    lcd.setCursor(0, 1); //设置显示指针
    lcd.print("r=");
    lcd.print(r_value);
    lcd.print("g=");
    lcd.print(g_value);
    lcd.print("b=");
    lcd.print(b_value);
    lcd.print("       ");

    if (irrecv.decode(&results)) {

      switch (results.value) {
      case Infrared_ch:
        index++;
        break;
      case Infrared_eq:
        return;
      }

      irrecv.resume();
    }
  }
}