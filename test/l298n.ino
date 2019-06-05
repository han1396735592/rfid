
//#include "l298.h"
#include <Arduino.h>

L298N l298nInit(int enable,int inA,int inB){
    L298N l298n;
    l298n.enable = enable;
    l298n.ina = inA;
    l298n.inb = inB;
    pinMode(enable, OUTPUT);
    pinMode(intA, OUTPUT);
    pinMode(inB, OUTPUT);
    digitalWrite(enable, HIGH);
}

void front(L298N L298N){
     digitalWrite(L298N->intA, HIGH);
    digitalWrite(L298N->intB, LOW);


}
void back(L298N l298n){
    digitalWrite(L298N->intA, Low);
    digitalWrite(L298N->intB, HIGH);
}












