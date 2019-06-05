#include <IRremote.h>
#include <LiquidCrystal_I2C.h>
#include <MFRC522.h>
#include <SPI.h>
#define A "39B8B163"
#include "infrared.h"
#include <DHT.h>
#define DHTPIN A0
#define DHTTYPE DHT11

// Initialize DHT sensor.
DHT dht(DHTPIN, DHTTYPE);

extern LiquidCrystal_I2C lcd;

extern MFRC522 mfrc522;
extern MFRC522::MIFARE_Key key;
extern IRrecv irrecv;
extern decode_results results;

void setup() {
  Serial.begin(9600); // Initialize serial communications with the PC
  while (!Serial)
    ;
  rfid_init();
  lcd_init();
  dht.begin();
  rgb_led_init();
  infrared_init();
}

int k = 0;
void loop() {

  if (k <= 0) {
    k = 0;
  }
  if (k >= 3) {
    k = 3;
  }
  show_main_ui(k);
  if (irrecv.decode(&results)) {
    Serial.print("id =");
    switch (results.value) {
    case Infrared_0:
      read_card();
      lcd.clear();
      break;
    case Infrared_1:
      rfid_led();
      lcd.clear();
      break;
    case Infrared_2:
      temperature_and_humidity_monitoring();
      lcd.clear();
      break;
    case Infrared_3:
      rgb_led();
      lcd.clear();
      break;
    case Infrared__1:
      k--;
      break;
    case Infrared__2:
      k++;

      break;
    }
    Serial.println(results.value);
    irrecv.resume();
  }
}
