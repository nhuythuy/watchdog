#ifndef WATCHDOG_IO
#define WATCHDOG_IO

// https://randomnerdtutorials.com/esp8266-pinout-reference-gpios/
// IMPORTANT NOTE: Remove PIN_SS_DOOR_MAIN connector b4 uploading code to NodeMcu, uploading fail otherwise
//   Serial.begin(19200, SERIAL_8N1, SERIAL_TX_ONLY);

// inputs
#define PIN_IN_WD_PULSE             D5 // DHT sensor pin

// outputs
#define PIN_LED                     D4 // D4: same as built in LED GPIO2
#define PIN_OUT_WD_TRIGGER          D6


#endif
