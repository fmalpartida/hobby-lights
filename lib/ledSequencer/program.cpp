#include <Arduino.h>
#include <program.hpp>
#include <ledSequence.hpp>
#include <definedPrograms.hpp>
#include <Storage.hpp>

static ledSequence *demoSequence[] =
   { program1, program2, program3, program4, program5, program6, program7, program8,
      program9, program10, program1 };

static int sequenceLength;
ledSequence *_myBoard[LEDS_ON_BOARD];

// Private management variables
static uint8_t _available;  // number of available slots
static uint8_t _used;       // number of used slots
static int _period;          // Wait delay after playing the entire sequence
Storage store;       // Added support for persisten storage

static void loadProgramSequence(ledSequence *myProgram);
static void addSequence(ledSequence *sequence);
static void clearProgram( );

program::program( )
{
   _available = LEDS_ON_BOARD;
   _used = 0;
   sequenceLength = sizeof(demoSequence)/sizeof(ledSequence *);
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

   // Setup initial program
   loadProgramSequence(demoSequence[store.getProgram()]);
}


void program::playProgram( )
{
   for ( int i = 0; i < _used ; i++ )
   {
      _myBoard[i]->playNext();
   }
   delay(_period);
}


void program::loadProgram(uint16_t progID)
{
   loadProgramSequence(demoSequence[progID]);
   store.setProgram(progID);
}

void program::setPeriod(uint16_t period)
{
   _period = period;
}

int program::getNumPrograms()
{
   return(sequenceLength);
}

int program::getCurrentProgram()
{
   return (store.getProgram());
}

// Private methods
// -----------------------------------------------------------------------------
static void clearProgram( )
{
   _used = 0;
}

static void addSequence(ledSequence *sequence)
{
   // If there are LEDs available, add it
   if ( _used < _available )
   {
      _myBoard[_used] = sequence;
      _used++;
   }
}

static void loadProgramSequence(ledSequence *myProgram)
{
   clearProgram();

   for ( int i = 0; i < _available; i++ )
   {
      addSequence(&myProgram[i]);
   }
}
