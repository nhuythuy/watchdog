#include "global_vars.h"
#include "pin_define.h"


#ifndef LIB
#define LIB


void flipLed(){
  stateLed = !stateLed;
  digitalWrite(PIN_LED, stateLed);
}

#endif
