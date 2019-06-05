#define RST_PIN 9                 // Configurable, see typical pin layout above
#define SS_PIN 10                 // Configurable, see typical pin layout above
MFRC522 mfrc522(SS_PIN, RST_PIN); // Create MFRC522 instance.

MFRC522::MIFARE_Key key;

#define REDLED 8
#define GREENLED 7

int red_led_value = 0;
int green_led_value = 0;

void rfid_init(void) {
  SPI.begin();        // Init SPI bus
  mfrc522.PCD_Init(); // Init MFRC522 card

  // Prepare the key (used both as key A and as key B)
  // using FFFFFFFFFFFFh which is the default at chip delivery from the factory
  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
  pinMode(REDLED, OUTPUT);
  pinMode(GREENLED, OUTPUT);
  Serial.println("rfid_init");
}

void read_card() {
  lcd.clear();
  lcd.setCursor(0, 0); //设置显示指针
  lcd.print("type: read card");
  lcd.setCursor(0, 1); //设置显示指针
  lcd.print("please put card");
  while (1) {
    if (irrecv.decode(&results)) {
      Serial.print("id =");
      switch (results.value) {
      case Infrared_eq:
        return;
      }
      Serial.println(results.value);
      irrecv.resume();
    }
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      lcd.clear();
      lcd.setCursor(0, 0); //设置显示指针
      Serial.print(F("Card UID:"));
      lcd.print("Card UID:"); //输出字符到LCD1602上
      lcd.setCursor(0, 1);
      String idStr = toStr(mfrc522.uid.uidByte, mfrc522.uid.size);
      Serial.println(idStr);
      lcd.print(idStr);
    }
  }
  lcd.clear();
}

void rfid_led() {
  lcd.clear();
  lcd.setCursor(0, 0); //设置显示指针
  lcd.print("type: rfid led");
  lcd.setCursor(0, 1); //设置显示指针
  lcd.print("please put card");
  while (1) {
    if (irrecv.decode(&results)) {
      switch (results.value) {
      case Infrared_eq:
        return;
      }
      irrecv.resume();
    }

    digitalWrite(REDLED, red_led_value);
    digitalWrite(GREENLED, green_led_value);
    if (mfrc522.PICC_IsNewCardPresent() && mfrc522.PICC_ReadCardSerial()) {
      if (toStr(mfrc522.uid.uidByte, mfrc522.uid.size) == A) {
        green_led_value = !green_led_value;
      } else {
        red_led_value = !red_led_value;
      }
      lcd.clear();
      lcd.setCursor(0, 0); //设置显示指针
      lcd.print("red led:");
      if (red_led_value) {
        lcd.print("open");
      } else {
        lcd.print("close");
      }
      lcd.setCursor(0, 1); //设置显示指针
      lcd.print("green led:");
      if (green_led_value) {
        lcd.print("open");
      } else {
        lcd.print("close");
      }

      delay(100);
    }
  }
  lcd.clear();
}

void write_card() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("type write card");
  byte *uid_byte = new byte[4];

  for (byte i = 0; i < 6; i++) {
    uid_byte[i] = 0xFF;
  }
  int i = 0;
  while (1) {
    lcd.setCursor(0, 1);
    lcd.print(toStr(uid_byte, 4));
    Serial.println(toStr(uid_byte, 4));
    if (i == 4) {
      i = 0;
    }
    if (irrecv.decode(&results)) {
      Serial.print("id =");
      switch (results.value) {
      case Infrared_eq:
        return;
      case Infrared_0:
        uid_byte[i] = 12;
        i++;
        break;
      case Infrared_1:
        uid_byte[i] = 34;
        i++;
        break;
      case Infrared_2:
        uid_byte[i] = 89;
        i++;
        break;
      case Infrared_3:
        uid_byte[i] = 56;
        i++;
        break;

      case Infrared_ch:
        if (mfrc522.MIFARE_SetUid(uid_byte, (byte)4, true)) {
          Serial.println(F("Wrote new UID to card."));
          lcd.setCursor(9, 1);
          lcd.print("Write ok");
          delay(1000);
        } else {
          lcd.setCursor(9, 1);
          lcd.print("Write err");
        }
        break;
      }

      Serial.println(results.value);
      irrecv.resume();
    }
  }
}
