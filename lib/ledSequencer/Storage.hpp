#ifndef __STORAGE__
#define __STORAGE__
#include <inttypes.h>

class Storage
{
  bool _init;

private:
   void readStore ();
   void writeStore();

public:
   Storage();
   void init();
   uint16_t getProgram();
   void setProgram(uint16_t);
   uint16_t getPeriod();
   void setPeriod(uint16_t);
};

#endif // __STORAGE__
