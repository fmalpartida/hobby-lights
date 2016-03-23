#include <inttypes.h>
#include <ledSequence.hpp>
#include <leds.hpp>

#ifndef __PROGRAM__
#define __PROGRAM__

class program
{
   ledSequence *_myBoard[LEDS_ON_BOARD];
   uint8_t _available;  // number of available slots
   uint8_t _used;       // number of used slots
   int _delay;          // Wait delay after playing the entire sequence

public:
   program(int);
   void addSequence(ledSequence *);
   void loadProgram(ledSequence *);
   void playProgram();
   void clearProgram();
};
#endif // __PROGRAM__
