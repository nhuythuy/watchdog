#ifndef GLOBAL_VARS
#define GLOBAL_VARS

#define WD_DELAY          120000      // 2 min

#define DELAY_LONG        5000      // 5,0 seconds
#define DELAY_SHORT       2500
long delayMs = DELAY_SHORT;

int debugCounter = 0;
int wdCounter = 0;


bool stateLed = 0;


int runtimeMinutes = 0;
int currentHour = -1;
int currentDay = -1;
int currentMin = -1;
float systemHourMinute = 0.0;

#endif
