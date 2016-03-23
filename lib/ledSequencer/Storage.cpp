#include <Arduino.h>
#include <EEPROM.h>
#include <Storage.hpp>


#define SIGNATURE 0xbeaf
#define STORAGE_VERSION 1

typedef struct
{
   uint16_t signature;
   uint8_t version;
   uint8_t program;
   uint8_t  period;
} t_storageContents;

t_storageContents myStore;

Storage::Storage()
{
  _init = false;

}


void Storage::init()
{
   // read EEPROM contents
   if (_init == false )
   {
      readStore();
   }

   // If the contents of the EEPROM is not valid initialize the EEPROM
   // with the initial conditions values
   // ----------------------------------------------------------------
   if ((myStore.signature != SIGNATURE) || (myStore.version != STORAGE_VERSION))
   {
      myStore.signature = SIGNATURE;
      myStore.version   = STORAGE_VERSION;
      myStore.program   = 1;
      myStore.period    = 20;

      writeStore();
   }
   _init = true;
}

// Getters
int8_t Storage::getProgram()
{
   int8_t retVal = -1;

   // If its initialized, read the contents
   if (_init)
   {
      retVal = myStore.program;
   }
   return (retVal);
}

int8_t Storage::getPeriod()
{
   int8_t retVal = -1;

   // If its initialized, read the contents
   if (_init)
   {
      retVal = myStore.period;
   }
   return (retVal);
}

// Setters
void Storage::setPeriod(int8_t period)
{
   if (_init)
   {
      myStore.period = period;
      writeStore();
   }
}

void Storage::setProgram(int8_t program)
{
   if (_init)
   {
      myStore.program = program;
      writeStore();
   }
}

// Private methods
void Storage::writeStore()
{
   EEPROM.put(0, myStore);
}

void Storage::readStore()
{
   EEPROM.get(0, myStore);
}
