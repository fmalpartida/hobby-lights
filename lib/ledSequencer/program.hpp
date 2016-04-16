#include <inttypes.h>

#ifndef __PROGRAM__
#define __PROGRAM__


class program
{


public:
   program();
   void init(int);
   void setPeriod(uint16_t, bool store);
   uint16_t getPeriod();
   void loadProgram(uint8_t, bool store);
   void playProgram();
   uint16_t getNumPrograms();
   uint16_t getCurrentProgram();
   char *getProgramName(uint8_t);


};
#endif // __PROGRAM__
