#include <Arduino.h>
#include <avr/pgmspace.h>

#include <ledSequence.hpp>
#include <Storage.hpp>
#include <program.hpp>
#include <definedPrograms.hpp>
#include <sequences.hpp>


static int sequenceLength;

// Channels controlled by this program
ledSequence _myChannels[LEDS_ON_BOARD];

// Private program management variables
static uint8_t _channelsAvail;  // number of available slots
static uint8_t _used;           // number of used slots
static uint16_t _period;        // Wait delay after playing the entire sequence
static uint16_t _currentPeriod; // Current period counter
Storage store;                  // Added support for persisten storage


// Public methods
program::program( )
{
   _channelsAvail = LEDS_ON_BOARD;
   _used = 0;
   sequenceLength = sizeof(demoSequence)/sizeof(t_sequenceDesc *);
}

void program::init(int period)
{

   store.init();

   // force initialization for the period, if not read the period
   // from the storage area
   if (period != 0)
   {
      _period = period;
   }
   else
   {
      _period = store.getPeriod();
   }
   _currentPeriod = _period; // Load the current period counter

   progInMem = store.getProgram();

   // Setup initial program
   loadProgram(progInMem, false);
}

void program::playProgram( )
{
   if ( _currentPeriod == 0)
   {
      for ( int i = 0; i < _used ; i++ )
      {
         _myChannels[i].playNext();
      }
      _currentPeriod = _period; // reload the period counter
   }
   _currentPeriod--;
   //Serial.println();
}

void program::loadProgram(uint8_t progID, bool save)
{
   progInMem = progID;

   for ( uint8_t i=0; i < LEDS_ON_BOARD; i++)
   {
      _myChannels[i].setLed((int)demoSequence[progID][i].led);
      _myChannels[i].setSequence(sequenceList[demoSequence[progID][i].seqIndex].sequence,
         sequenceList[demoSequence[progID][i].seqIndex].seqSize);
      //Serial.print("Program: ");
      //Serial.println(progID);
      //Serial.print("LED: ");
      //Serial.println(demoSequence[progID][i].led);
      //Serial.print("Sequence: ");
      //Serial.println( demoSequence[progID][i].seqIndex);
      //Serial.println( "------");
   }
   _used = LEDS_ON_BOARD;

   if (save)
   {
      store.setProgram(progID);
   }
}


void program::setPeriod(uint16_t period, bool save)
{
   if ( period > 0)
   {
      _period = period;
   }
   if (save)
   {
      store.setPeriod(period);
   }
}

uint16_t program::getPeriod()
{
   return (_period);
}

uint16_t program::getNumPrograms()
{
   return(sequenceLength);
}

uint16_t program::getCurrentProgram()
{
   return (progInMem);
}

uint16_t program::getStoreProgram()
{
   return (store.getProgram());
}

char *program::getProgramName(uint8_t progID )
{
   static char buffer[20];
   char * ptr = (char *) pgm_read_word (&names[progID]);
   strcpy_P (buffer, ptr);
   return (buffer);
}
// Private methods
// -----------------------------------------------------------------------------
