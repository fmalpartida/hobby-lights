#include <inttypes.h>


#ifndef __COMMON_CONSTANTS__
#define __COMMON_CONSTANTS__

const int timerPeriod_us    = 500; // will give a 1ms resolution sequence

#define TIMER_TICKS_PER_MS    (1000/timerPeriod_us)

#define CONTROLLER_PERIOD     10  // ms
const int controllerPeriod  = CONTROLLER_PERIOD * TIMER_TICKS_PER_MS;  // Main controller period

#define INDICATION_PROGRAM    0
#define INDICATION_FREQ       40
#define INIDICATION_TIMEOUT   1500/CONTROLLER_PERIOD


// Button pind definition
#define UP_BUTTON     10
#define DOWN_BUTTON   8
#define SELECT_BUTTON 9

// LED pin definition
#include <leds.hpp>

#endif
