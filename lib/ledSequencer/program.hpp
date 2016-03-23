#include <inttypes.h>
#include <ledSequence.hpp>
#include <leds.hpp>
#include <Storage.hpp>

#ifndef __PROGRAM__
#define __PROGRAM__

class program
{

public:
   program();
   void init(int);
   void setPeriod(uint16_t);
   void loadProgram(uint16_t);
   void playProgram();
   int getNumPrograms();
   int getCurrentProgram();


};
#endif // __PROGRAM__
