#include <inttypes.h>
#include <sequences.hpp>
#include <ledSequence.hpp>
#include <leds.hpp>

#ifndef __DEFINED_PROGS__
#define __DEFINED_PROGS__

#define SET_SEQUENCE(seq) seq, sizeof(seq)

// All fixed
ledSequence program1[LEDS_ON_BOARD] =
{
   ledSequence( LED1, SET_SEQUENCE(fixed)),
   ledSequence( LED2, SET_SEQUENCE(fixed)),
   ledSequence( LED3, SET_SEQUENCE(fixed)),
   ledSequence( LED4, SET_SEQUENCE(fixed)),
   ledSequence( LED5, SET_SEQUENCE(fixed)),
   ledSequence( LED6, SET_SEQUENCE(fixed)),
   ledSequence( LED7, SET_SEQUENCE(fixed)),
   ledSequence( LED8, SET_SEQUENCE(fixed))
};

// Airplane
ledSequence program2[LEDS_ON_BOARD] =
{
   ledSequence( LED1, SET_SEQUENCE(fixed)),
   ledSequence( LED2, SET_SEQUENCE(fixed)),
   ledSequence( LED3, SET_SEQUENCE(fixed)),
   ledSequence( LED4, SET_SEQUENCE(fixed)),
   ledSequence( LED5, SET_SEQUENCE(blink0)),
   ledSequence( LED6, SET_SEQUENCE(randFliker0)),
   ledSequence( LED7, SET_SEQUENCE(doubleBlink90)),
   ledSequence( LED8, SET_SEQUENCE(doubleBlink90))
};

// Airplane 2
ledSequence program3[LEDS_ON_BOARD] =
{
   ledSequence( LED1, SET_SEQUENCE(fixed)),
   ledSequence( LED2, SET_SEQUENCE(fixed)),
   ledSequence( LED3, SET_SEQUENCE(fixed)),
   ledSequence( LED4, SET_SEQUENCE(fixed)),
   ledSequence( LED5, SET_SEQUENCE(fixed)),
   ledSequence( LED6, SET_SEQUENCE(randFliker0)),
   ledSequence( LED7, SET_SEQUENCE(blink0)),
   ledSequence( LED8, SET_SEQUENCE(doubleBlink90))
};

// Helicopter
ledSequence program4[LEDS_ON_BOARD] =
{
   ledSequence( LED1, SET_SEQUENCE(fixed)),
   ledSequence( LED2, SET_SEQUENCE(fixed)),
   ledSequence( LED3, SET_SEQUENCE(fixed)),
   ledSequence( LED4, SET_SEQUENCE(fixed)),
   ledSequence( LED5, SET_SEQUENCE(fixed)),
   ledSequence( LED6, SET_SEQUENCE(fixed)),
   ledSequence( LED7, SET_SEQUENCE(fixed)),
   ledSequence( LED8, SET_SEQUENCE(doubleBlink0))
};

// All blinking in pairs of 4
ledSequence program5[LEDS_ON_BOARD] =
{
   ledSequence( LED1, SET_SEQUENCE(doubleBlink270)),
   ledSequence( LED2, SET_SEQUENCE(doubleBlink270)),
   ledSequence( LED3, SET_SEQUENCE(doubleBlink270)),
   ledSequence( LED4, SET_SEQUENCE(doubleBlink270)),
   ledSequence( LED5, SET_SEQUENCE(doubleBlink0)),
   ledSequence( LED6, SET_SEQUENCE(doubleBlink0)),
   ledSequence( LED7, SET_SEQUENCE(doubleBlink0)),
   ledSequence( LED8, SET_SEQUENCE(doubleBlink0))
};

// All random flicker all
ledSequence program6[LEDS_ON_BOARD] =
{
   ledSequence( LED1, SET_SEQUENCE(randFliker0)),
   ledSequence( LED2, SET_SEQUENCE(randFliker0)),
   ledSequence( LED3, SET_SEQUENCE(randFliker0)),
   ledSequence( LED4, SET_SEQUENCE(randFliker0)),
   ledSequence( LED5, SET_SEQUENCE(randFliker0)),
   ledSequence( LED6, SET_SEQUENCE(randFliker0)),
   ledSequence( LED7, SET_SEQUENCE(randFliker0)),
   ledSequence( LED8, SET_SEQUENCE(randFliker0))
};

// Fast blink
ledSequence program7[LEDS_ON_BOARD] =
{
   ledSequence( LED1, SET_SEQUENCE(fastBlink0)),
   ledSequence( LED2, SET_SEQUENCE(fastBlink0)),
   ledSequence( LED3, SET_SEQUENCE(fastBlink0)),
   ledSequence( LED4, SET_SEQUENCE(fastBlink0)),
   ledSequence( LED5, SET_SEQUENCE(fastBlink0)),
   ledSequence( LED6, SET_SEQUENCE(fastBlink0)),
   ledSequence( LED7, SET_SEQUENCE(fastBlink0)),
   ledSequence( LED8, SET_SEQUENCE(fastBlink0))
};

ledSequence program8[LEDS_ON_BOARD] =
{
   ledSequence( LED1, SET_SEQUENCE(fastBlink0)),
   ledSequence( LED2, SET_SEQUENCE(fastBlink90)),
   ledSequence( LED3, SET_SEQUENCE(fastBlink180)),
   ledSequence( LED4, SET_SEQUENCE(fastBlink270)),
   ledSequence( LED5, SET_SEQUENCE(fastBlink0)),
   ledSequence( LED6, SET_SEQUENCE(fastBlink90)),
   ledSequence( LED7, SET_SEQUENCE(fastBlink180)),
   ledSequence( LED8, SET_SEQUENCE(fastBlink270))
};

// Blink
ledSequence program9[LEDS_ON_BOARD] =
{
   ledSequence( LED1, SET_SEQUENCE(fastBlinkP0)),
   ledSequence( LED2, SET_SEQUENCE(fastBlinkP90)),
   ledSequence( LED3, SET_SEQUENCE(fastBlinkP180)),
   ledSequence( LED4, SET_SEQUENCE(fastBlinkP270)),
   ledSequence( LED5, SET_SEQUENCE(fastBlinkBurstLP0)),
   ledSequence( LED6, SET_SEQUENCE(fastBlinkBurstLP90)),
   ledSequence( LED7, SET_SEQUENCE(fastBlinkBurstLP180)),
   ledSequence( LED8, SET_SEQUENCE(fastBlinkBurstLP270))
};

ledSequence program10[LEDS_ON_BOARD] =
{
   ledSequence( LED1, SET_SEQUENCE(blink0)),
   ledSequence( LED2, SET_SEQUENCE(blink0)),
   ledSequence( LED3, SET_SEQUENCE(blink0)),
   ledSequence( LED4, SET_SEQUENCE(blink0)),
   ledSequence( LED5, SET_SEQUENCE(blink0)),
   ledSequence( LED6, SET_SEQUENCE(blink0)),
   ledSequence( LED7, SET_SEQUENCE(blink0)),
   ledSequence( LED8, SET_SEQUENCE(blink0))
};

#endif // __DEFINED_PROGS__
