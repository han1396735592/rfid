#include <Arduino.h>

String toStr(byte *buffer, byte bufferSize) {
  String str = "";
  for (byte i = 0; i < bufferSize; i++) {
    int t = 0;
    t = buffer[i] / 16;
    switch (t) {
    case 10:
      str += "A";
      break;
    case 11:
      str += "B";
      break;
    case 12:
      str += "C";
      break;
    case 13:
      str += "D";
      break;
    case 14:
      str += "E";
      break;
    case 15:
      str += "F";
      break;
    default:
      str += t;
    }
    t = buffer[i] % 16;
    switch (t) {
    case 10:
      str += "A";
      break;
    case 11:
      str += "B";
      break;
    case 12:
      str += "C";
      break;
    case 13:
      str += "D";
      break;
    case 14:
      str += "E";
      break;
    case 15:
      str += "F";
      break;
    default:
      str += t;
    }
  }
  return str;
}
