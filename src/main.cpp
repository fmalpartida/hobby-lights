#include <Arduino.h>
#include <serialMenu.hpp>
#include <TimerOne.h>
#include <FastIO.h>
#include <program.hpp>
#include <controller.hpp>


const int timerPeriod_us    = 500; // will give a 1ms resolution sequence
const int controllerPeriod  = 10 * (1000/timerPeriod_us);  // 10 ms

bool wakeUp = false;

program myProgram;
serialMenu myInput;

controller myController(controllerPeriod, 8, 9, 10, &myProgram);

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
      // Sequence the program currently loaded
      myController.monitorKeyboard();
      myProgram.playProgram();

      ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
      {
         wakeUp = false;
      }
   }
}
