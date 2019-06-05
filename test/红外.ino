#include <IRremote.h>

int PIN_RECV = 11;
IRrecv irrecv(PIN_RECV);
decode_results results;

int LED = 13;

void setup() {
  Serial.begin(9600);
  irrecv.enableIRIn();
  pinMode(LED, OUTPUT);
}

void loop() {
  if (irrecv.decode(&results)) {

    switch (results.value) {
    case 16738455:
      digitalWrite(LED, HIGH);
      Serial.println("open");
      break;
    case 16750695:
      digitalWrite(13, LOW);
      Serial.println("close");
      break;
    }

    Serial.println(results.value);
    irrecv.resume();
  }
}