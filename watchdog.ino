#include <DHT.h>
#include "global_vars.h"
#include "pin_define.h"
#include "wifi_cloud.h"
#include "blynk.h"

//#define ENABLE_WIFI
//#define ENABLE_BLYNK


void setup() {
  ESP.wdtDisable();

  Serial.begin(19200, SERIAL_8N1, SERIAL_TX_ONLY);

#ifdef ENABLE_WIFI
  WIFI_Connect();
  setupDateTime();

#ifdef ENABLE_BLYNK
  blynkSetup();
#endif
#endif

  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_OUT_WD_TRIGGER, INPUT);       // Return to high impedance  

  pinMode(PIN_IN_WD_PULSE, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_IN_WD_PULSE), blink, CHANGE); // LOW, CHANGE, RISING, FALLING, HIGH

  ESP.wdtEnable(5000); // msec
}

unsigned long prevWdMillis = millis();

unsigned long previousMillis = millis();
unsigned long currentMillis = millis();
// =======================================================
void loop (){
  ESP.wdtFeed();

  currentMillis = millis();
  runtimeMinutes = currentMillis / 60000;

  if(abs(currentMillis - prevWdMillis) > WD_DELAY){
    pinMode(PIN_OUT_WD_TRIGGER, OUTPUT);    // Sink current
    digitalWrite(PIN_OUT_WD_TRIGGER, LOW);  // Reset (EN pin to LOW)
    delay(1000);
    pinMode(PIN_OUT_WD_TRIGGER, INPUT);     // trigger EN pin, use as input to withdraw current
  }

  if(abs(currentMillis - previousMillis) > 5000){ // sampling sensors every 5 sec
#ifdef ENABLE_WIFI
    if(WiFi.status() == WL_DISCONNECTED){
      Serial.println("WiFi connection lost! Reconnecting...");
      WiFi.disconnect();
      WIFI_Connect();    
    }
  
      getServerTime();
#endif

    previousMillis = currentMillis;
    flipLed();
  }

#ifdef ENABLE_WIFI
#ifdef ENABLE_BLYNK
  blynkLoop();
#endif
#endif

}
