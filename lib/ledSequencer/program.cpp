#include <Arduino.h>
#include <program.hpp>
#include <ledSequence.hpp>

program::program(int delay)
{
   _available = LEDS_ON_BOARD;
   _used = 0;
   _delay = delay;
}

void program::addSequence(ledSequence *sequence)
{
   // If there are LEDs available, add it
   if ( _used < _available )
   {
      _myBoard[_used] = sequence;
      _used++;
   }
}

void program::playProgram( )
{
   for ( int i = 0; i < _used ; i++ )
   {
      _myBoard[i]->playNext();
   }
   delay(_delay);
}

void program::clearProgram( )
{
   _used = 0;
}

void program::loadProgram(ledSequence *myProgram)
{
   this->clearProgram();

   for ( int i = 0; i < _available; i++ )
   {
      this->addSequence(&myProgram[i]);
   }
}
