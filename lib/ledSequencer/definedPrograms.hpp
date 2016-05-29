#include <inttypes.h>
#include <sequences.hpp>
#include <leds.hpp>
#include <avr/pgmspace.h>


#ifndef __DEFINED_PROGS__
#define __DEFINED_PROGS__

#define SET_SEQUENCE(seq) seq, sizeof(seq)

typedef struct
{
   uint8_t led;
   uint8_t seqIndex;
} t_sequenceDesc;

// user defined sequence
t_sequenceDesc user[LEDS_ON_BOARD] =
{
   {LED1, FAST_BLINK_LP_0},
   {LED2, FAST_BLINK_LP_0},
   {LED3, FAST_BLINK_LP_0},
   {LED4, FAST_BLINK_LP_0},
   {LED5, FAST_BLINK_LP_0},
   {LED6, FAST_BLINK_LP_0},
   {LED7, FAST_BLINK_LP_0},
   {LED8, FAST_BLINK_LP_0}
};

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

// Emergency car 1 - 4 fixed, 4 blink
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

// Emergency car 2 - 4 fixed, 2 blink, 2 fast blink
t_sequenceDesc emergencyCar2[LEDS_ON_BOARD] =
{
   {LED1, FIXED},
   {LED2, FIXED},
   {LED3, FIXED},
   {LED4, FIXED},
   {LED5, BLINK_0},
   {LED6, BLINK_90},
   {LED7, FAST_BLINK_LP_0},
   {LED8, FAST_BLINK_LP_90}
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

// Diorama 2 - 2 buring, 2 shots, 3 fixed, 1 burst (explosions)
t_sequenceDesc diorama2[LEDS_ON_BOARD] =
{
   {LED1, RAND_FLICK_0},
   {LED2, RAND_FLICK_180},
   {LED3, FAST_BLINK_P_0},
   {LED4, FAST_BLINK_P_180},
   {LED5, FIXED},
   {LED6, FIXED},
   {LED7, FIXED},
   {LED8, BURSTLP_0}
};

// Diorama 3 - 2 buring, 2 shots, 2 fixed, 2 burst (explosions)
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

// Diorama 4 - 2 buring, 2 shots, 2 fixed, 2 burst (explosions)
t_sequenceDesc diorama4[LEDS_ON_BOARD] =
{
   {LED1, RAND_FLICK_0},
   {LED2, RAND_FLICK_180},
   {LED3, FAST_BLINK_LP_0},
   {LED4, FAST_BLINK_LP_180},
   {LED5, FIXED},
   {LED6, FIXED},
   {LED7, BURSTLP_0},
   {LED8, BURSTLP_1_90}
};

// Chaser following patern
t_sequenceDesc chaser1[LEDS_ON_BOARD] =
{
   {LED1, BLINK_0},
   {LED2, BLINK_90},
   {LED3, BLINK_180},
   {LED4, BLINK_270},
   {LED5, BLINKP_0},
   {LED6, BLINKP_90},
   {LED7, BLINKP_180},
   {LED8, BLINKP_270}
};

// Chaser 2
t_sequenceDesc chaser2[LEDS_ON_BOARD] =
{
   {LED1, BLINKP_0},
   {LED2, BLINKP_90},
   {LED3, BLINKP_180},
   {LED4, BLINKP_270},
   {LED5, BLINKP_0B},
   {LED6, BLINKP_90B},
   {LED7, BLINKP_180B},
   {LED8, BLINKP_270B}
};

// All flicker random (space craft with may lights of buildings)
t_sequenceDesc allFlicker[LEDS_ON_BOARD] =
{
   {LED1, RAND_FLICK_0},
   {LED2, RAND_FLICK_180},
   {LED3, RAND_FLICK_0},
   {LED4, RAND_FLICK_180},
   {LED5, RAND_FLICK_0},
   {LED6, RAND_FLICK_180},
   {LED7, RAND_FLICK_0},
   {LED8, RAND_FLICK_180}
};

t_sequenceDesc allFastBlick[LEDS_ON_BOARD] =
{
   {LED1, VFAST_BLINK_0},
   {LED2, VFAST_BLINK_180},
   {LED3, VFAST_BLINK_0},
   {LED4, VFAST_BLINK_180},
   {LED5, VFAST_BLINK_0},
   {LED6, VFAST_BLINK_180},
   {LED7, VFAST_BLINK_0},
   {LED8, VFAST_BLINK_180}
};

t_sequenceDesc falconLights[LEDS_ON_BOARD] =
{
   {LED1, RAND_FLICK_0},
   {LED2, RAND_FLICK_180},
   {LED3, FAST_BLINK_LP_0},
   {LED4, FAST_BLINK_LP_180},
   {LED5, FAST_BLINK_0},
   {LED6, FIXED},
   {LED7, FIXED},
   {LED8, FIXED}
};


t_sequenceDesc cylonRaider[LEDS_ON_BOARD] =
{
   {LED1, CHASER_1},
   {LED2, CHASER_2},
   {LED3, CHASER_3},
   {LED4, CHASER_4},
   {LED5, CHASER_5},
   {LED6, CHASER_6},
   {LED7, RAND_FLICK_0},
   {LED8, BURSTLP_0}
};

// All blinking blink
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

// All blinking alternating
t_sequenceDesc blinkAltern[LEDS_ON_BOARD] =
{
   {LED1, BLINK_0},
   {LED2, BLINK_90},
   {LED3, BLINK_0},
   {LED4, BLINK_90},
   {LED5, BLINK_0},
   {LED6, BLINK_90},
   {LED7, BLINK_0},
   {LED8, BLINK_90}
};

const char userDesc[] PROGMEM = "USER DEFINED";
const char airplane1Desc[] PROGMEM = "AIRPLANE 1";
const char airplane2Desc[] PROGMEM = "AIRPLANE 2";
const char helicopterDesc[] PROGMEM = "HELICOPTER";
const char emergencyCar1Desc[] PROGMEM = "EMERGENCY CAR 1";
const char emergencyCar2Desc[] PROGMEM = "EMERGENCY CAR 2";
const char shots1Desc [] PROGMEM = "SHOTS 1";
const char shots2Desc [] PROGMEM = "SHOTS 2";
const char diorama1Desc [] PROGMEM = "DIORAMA 1";
const char diorama2Desc [] PROGMEM = "DIORAMA 2";
const char diorama3Desc [] PROGMEM = "DIORAMA 3";
const char diorama4Desc [] PROGMEM = "DIORAMA 4";
const char chaser1Desc[] PROGMEM = "CHASER 1";
const char chaser2Desc[] PROGMEM = "CHASER 2";
const char allFlickerDesc[] PROGMEM = "ALL FLICKER";
const char allFastBlinkDesc[] PROGMEM = "ALL FAST BLINK";
const char falconLightsDesc[] PROGMEM = "BANDAI FALCON";
const char cylonRaiderDesc[] PROGMEM = "CYLON RAIDER";

const char fixedDesc[] PROGMEM = "FIXED";

const char blinkAltDesc[] PROGMEM = "BLINK ALT.";
const char blinkDesc[] PROGMEM = "BLINK";

// Predefined program names
const char * const names[] PROGMEM =
{ userDesc, airplane1Desc, airplane2Desc, helicopterDesc, emergencyCar1Desc,
   emergencyCar2Desc, shots1Desc, shots2Desc, diorama1Desc, diorama2Desc, diorama3Desc,
   diorama4Desc, chaser1Desc, chaser2Desc, allFlickerDesc, allFastBlinkDesc,
   falconLightsDesc, cylonRaiderDesc,

   blinkAltDesc, fixedDesc,
   // Last all blink
   blinkDesc

};

// Predefined programs
t_sequenceDesc *demoSequence[] =
{ user, airplane1, airplane2, helicopter, emergencyCar1, emergencyCar2,
   gunShot1, gunShot2, diorama1, diorama2, diorama3, diorama4, chaser1,
   chaser2, allFlicker, allFastBlick, falconLights, cylonRaider,

   blinkAltern, allFixed,
   // Last all blink
   blink
};


#endif // __DEFINED_PROGS__
