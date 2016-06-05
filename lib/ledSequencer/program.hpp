#include <inttypes.h>

#ifndef __PROGRAM__
#define __PROGRAM__


class program
{
uint8_t progInMem;

public:
   program();
   void init(int);
   void setPeriod(uint16_t, bool store);
   uint16_t getPeriod();
   uint16_t getStorePeriod();
   uint16_t getNumPrograms();
   uint16_t getCurrentProgram();
   uint16_t getStoreProgram();
   char *getProgramName(uint8_t);
   void loadProgram(uint8_t, bool store);
   void playProgram();
};
#endif // __PROGRAM__
