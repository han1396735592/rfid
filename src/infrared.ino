#include "infrared.h"
#include <IRremote.h>

int PIN_RECV = 4;
IRrecv irrecv(PIN_RECV);
decode_results results;

void infrared_init() { irrecv.enableIRIn(); }

