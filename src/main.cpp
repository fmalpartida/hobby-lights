#include <Arduino.h>
#include <program.hpp>
#include <serialMenu.hpp>
#include <TimerOne.h>
#include <FastIO.h>
#include <button.hpp>


#define CHECK_BUTTON_PERIOD 10     //Check very 10ms
const int timerPeriod_us    = 500; // will give a 1ms resolution sequence

bool wakeUp = false;

program myProgram;
serialMenu myInput;

extern void clickedCallback();
extern void longPressCallback();
extern void doublePressCallback();

#define LED 13

button myButton1(A0, clickedCallback, doublePressCallback, longPressCallback);

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
   pinMode (LED, OUTPUT);

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
      static uint8_t buttonPeriod = CHECK_BUTTON_PERIOD;

      // Check for button press
      if ( buttonPeriod != 0 )
      {
         myButton1.getEvent();
         buttonPeriod = CHECK_BUTTON_PERIOD;
      }
      buttonPeriod--;

      // Play the program
      myProgram.playProgram();

      ATOMIC_BLOCK(ATOMIC_RESTORESTATE)
      {
         wakeUp = false;
      }
   }
}

void clickedCallback()
{
   digitalWrite (LED, 1);
}
void longPressCallback()
{
   digitalWrite (LED, 0);
}
void doublePressCallback()
{
   digitalWrite (LED, 1);
   delay(500);
   digitalWrite (LED, 0);
   delay(500);
   digitalWrite (LED, 1);
   delay(500);
   digitalWrite (LED, 0);
}
