#include <Arduino.h>
#include <serialMenu.hpp>
#include <TimerOne.h>
#include <FastIO.h>
#include <program.hpp>
#include <controller.hpp>
#include <commonConstants.hpp>


bool wakeUp = false;

program myProgram;
serialCommand myInput;
button up(UP_BUTTON);
button down(DOWN_BUTTON);
button select(SELECT_BUTTON);
controller myController(controllerPeriod, &up, &down, &select,
   &myProgram);

// Define my ISR to wake the sequencer
void myTimerInt ()
{
   ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
   {
      wakeUp = true;
   }
}

void setup ()
{
   Serial.begin(115200);
   myProgram.init(0);
   //myInput.printOptions(&myProgram);

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
      //myInput.printOptions(&myProgram);
   }

   if (wakeUp)
   {
      // Sequence the program currently loaded
      myController.monitorKeyboard();
      myProgram.playProgram();

      ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
      {
         wakeUp = false;
      }
   }
}
