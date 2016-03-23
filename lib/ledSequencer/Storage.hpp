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
   int8_t getProgram();
   void setProgram(int8_t);
   int8_t getPeriod();
   void setPeriod(int8_t);
};

#endif // __STORAGE__
