#include <Arduino.h>
#include <EEPROM.h>
#include <Storage.hpp>


#define SIGNATURE       0xbeaf
#define STORAGE_VERSION 3

#define DEFAULT_PROG    1
#define DEFAULT_PERIOD 40

#define HW_VERSION      'B'
#define FIRM_VERSION    0x0200

typedef struct
{
   uint16_t  signature;
   uint8_t   version;
   uint16_t  program;
   uint16_t  period;

   char HWVersion;
   uint16_t firmwareVersion;
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
      myStore.program   = DEFAULT_PROG;
      myStore.period    = DEFAULT_PERIOD;

      myStore.HWVersion = HW_VERSION;
      myStore.firmwareVersion = FIRM_VERSION;

      writeStore();
   }
   _init = true;
}

// Getters
uint16_t Storage::getProgram()
{
   int8_t retVal = -1;

   // If its initialized, read the contents
   if (_init)
   {
      retVal = myStore.program;
   }
   return (retVal);
}

uint16_t Storage::getPeriod()
{
   uint16_t retVal = -1;

   // If its initialized, read the contents
   if (_init)
   {
      retVal = myStore.period;
   }
   return (retVal);
}


char Storage::getHWVersion()
{
   char retVal = ' ';

   // If its initialized, read the contents
   if (_init)
   {
      retVal = myStore.HWVersion;
   }
   return (retVal);
}

// Setters
void Storage::setPeriod(uint16_t period)
{
   if (_init)
   {
      myStore.period = period;
      writeStore();
   }
}

void Storage::setProgram(uint16_t program)
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

void Storage::printInfo()
{
   Serial.print(F("Firmware version: "));
   Serial.print(myStore.firmwareVersion && 0xFF00);
   Serial.print(".");
   Serial.println(myStore.firmwareVersion && 0x00FF);

   Serial.print(F("HW Version: "));
   Serial.println(myStore.HWVersion);

   Serial.print(F("Storege Version: "));
   Serial.println(myStore.version);
}
