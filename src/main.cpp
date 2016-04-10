#include <Arduino.h>
#include <program.hpp>
#include <serialMenu.hpp>
#include <TimerOne.h>
#include <FastIO.h>


program myProgram;
serialMenu myInput;

const int timerPeriod_us = 500; // will give a 1ms resolution sequence
bool wakeUp = false;

// Define my ISR to wake the sequencer
void myTimerInt ()
{
   wakeUp = true;
}

void setup ()
{
   Serial.begin(115200);
   myProgram.init(0);
   myInput.printOptions(&myProgram);

   // Initialize the periodic timer
   Timer1.initialize(timerPeriod_us);
   Timer1.attachInterrupt(myTimerInt, timerPeriod_us);

}

void loop ()
{
   command *newCommand;


   // Check for serial inputs
   newCommand = myInput.getCommand();

   if ( newCommand != NULL )
   {
      newCommand->execute(&myProgram);
      myInput.printOptions(&myProgram);
   }

   if (wakeUp)
   {
      // Check for button press

      // Play the program
      myProgram.playProgram();

      ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
      {
         wakeUp = false;
      }
   }
}
