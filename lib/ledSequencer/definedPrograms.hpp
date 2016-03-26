#include <inttypes.h>
#include <sequences.hpp>
#include <leds.hpp>


#ifndef __DEFINED_PROGS__
#define __DEFINED_PROGS__

#define SET_SEQUENCE(seq) seq, sizeof(seq)

typedef struct
{
   uint8_t led;
   uint8_t seqIndex;
} t_sequenceDesc;

// All fixed
t_sequenceDesc allFixed[LEDS_ON_BOARD] =
{
   {LED1, FIXED},
   {LED2, FIXED},
   {LED3, FIXED},
   {LED4, FIXED},
   {LED5, FIXED},
   {LED6, FIXED},
   {LED7, FIXED},
   {LED8, FIXED}
};

// Airplane
t_sequenceDesc airplane1[LEDS_ON_BOARD] =
{
   {LED1, FIXED},
   {LED2, FIXED},
   {LED3, FIXED},
   {LED4, FIXED},
   {LED5, RAND_FLICK_0},
   {LED6, BLINK_0},
   {LED7, DOUBLE_BLINK_0},
   {LED8, DOUBLE_BLINK_0}
};

// Airplane 2
t_sequenceDesc airplane2[LEDS_ON_BOARD] =
{
   {LED1, FIXED},
   {LED2, FIXED},
   {LED3, FIXED},
   {LED4, FIXED},
   {LED5, RAND_FLICK_0},
   {LED6, BLINK_0},
   {LED7, DOUBLE_BLINK_0},
   {LED8, FIXED}
};

// Helicopter
t_sequenceDesc helicopter[LEDS_ON_BOARD] =
{
   {LED1, FIXED},
   {LED2, FIXED},
   {LED3, FIXED},
   {LED4, FIXED},
   {LED5, FIXED},
   {LED6, FIXED},
   {LED7, FIXED},
   {LED8, DOUBLE_BLINK_0}
};

// Emergency car 1
t_sequenceDesc emergencyCar1[LEDS_ON_BOARD] =
{
   {LED1, FIXED},
   {LED2, FIXED},
   {LED3, FIXED},
   {LED4, FIXED},
   {LED5, BLINK_0},
   {LED6, BLINK_90},
   {LED7, BLINK_0},
   {LED8, BLINK_90}
};

// Emergency car 1
t_sequenceDesc emergencyCar2[LEDS_ON_BOARD] =
{
   {LED1, FIXED},
   {LED2, FIXED},
   {LED3, FIXED},
   {LED4, FIXED},
   {LED5, BLINK_0},
   {LED6, BLINK_90},
   {LED7, FAST_BLINK_0},
   {LED8, FAST_BLINK_90}
};


// Gun shot scene 1 all shotting
t_sequenceDesc gunShot1[LEDS_ON_BOARD] =
{
   {LED1, FAST_BLINK_P_0},
   {LED2, FAST_BLINK_P_90},
   {LED3, FAST_BLINK_P_180},
   {LED4, FAST_BLINK_P_270},
   {LED5, FAST_BLINK_LP_0},
   {LED6, FAST_BLINK_LP_90},
   {LED7, FAST_BLINK_LP_180},
   {LED8, FAST_BLINK_LP_270}
};

// Gun shot scene 2 - 2 gunshots slow, 2 fire, 2 explosions
t_sequenceDesc gunShot2[LEDS_ON_BOARD] =
{
   {LED1, FAST_BLINK_P_0},
   {LED2, FAST_BLINK_P_90},
   {LED3, RAND_FLICK_0},
   {LED4, BURST_0},
   {LED5, FAST_BLINK_LP_0},
   {LED6, FAST_BLINK_LP_90},
   {LED7, RAND_FLICK_180},
   {LED8, BURST_0}
};


// Diorama 1 - 4 burning, 4 fixed (urban fire)
t_sequenceDesc diorama1[LEDS_ON_BOARD] =
{
   {LED1, RAND_FLICK_0},
   {LED2, RAND_FLICK_180},
   {LED3, RAND_FLICK_0},
   {LED4, RAND_FLICK_180},
   {LED5, FIXED},
   {LED6, FIXED},
   {LED7, FIXED},
   {LED8, FIXED}
};

// Diorama 2 - 2 buring, 2 shots, 3 fixed, 1 burst
t_sequenceDesc diorama2[LEDS_ON_BOARD] =
{
   {LED1, RAND_FLICK_0},
   {LED2, RAND_FLICK_180},
   {LED3, FAST_BLINK_P_0},
   {LED4, FAST_BLINK_P_180},
   {LED5, FIXED},
   {LED6, FIXED},
   {LED7, FIXED},
   {LED8, BURST_0}
};

// Diorama 3 - 2 buring, 2 shots, 2 fixed, 2 burst
t_sequenceDesc diorama3[LEDS_ON_BOARD] =
{
   {LED1, RAND_FLICK_0},
   {LED2, RAND_FLICK_180},
   {LED3, FAST_BLINK_P_0},
   {LED4, FAST_BLINK_P_180},
   {LED5, FIXED},
   {LED6, FIXED},
   {LED7, BURST_0},
   {LED8, BURST_1_90}
};

// Blink
t_sequenceDesc blink[LEDS_ON_BOARD] =
{
   {LED1, BLINK_0},
   {LED2, BLINK_0},
   {LED3, BLINK_0},
   {LED4, BLINK_0},
   {LED5, BLINK_0},
   {LED6, BLINK_0},
   {LED7, BLINK_0},
   {LED8, BLINK_0}
};

t_sequenceDesc chaser[LEDS_ON_BOARD] =
{
   {LED1, BLINK_0},
   {LED2, BLINK_90},
   {LED3, BLINK_180},
   {LED4, BLINK_270},
   {LED5, BLINK_0},
   {LED6, BLINK_90},
   {LED7, BLINK_180},
   {LED8, BLINK_270}
};


// Predefined programs
t_sequenceDesc *demoSequence[] =
   { allFixed, airplane1, airplane2, helicopter, emergencyCar1, emergencyCar2,
      gunShot1, gunShot2, diorama1, diorama2, diorama3,blink, chaser };

const char *names[] =
{ "FIXED", "AIRPLANE 1", "AIRPLANE 2", "HELICOPTER", "EMERG. CAR 1", "EMERG. CAR 2",
"SHOTS 1", "SHOTS 2", "DIORAMA 1", "DIORAMA 2", "DIORAMA 3", "BLINK", "CHASER" };

#endif // __DEFINED_PROGS__
