#include <Arduino.h>
#include <program.hpp>
#include <serialMenu.hpp>


program myProgram;

void setup ()
{
   Serial.begin(115200);
   myProgram.init(0);
}

void loop ()
{
   static int currentProg = 0;
   int newProg;

   myProgram.playProgram();
   newProg = processSerial();

   // If the program has changed, load it and start using it for the next
   // cycle
   if (( newProg >= 0 ) && ( newProg < myProgram.getNumPrograms() ) &&
      (newProg != myProgram.getCurrentProgram()))
   {
      currentProg = newProg;
      myProgram.loadProgram(currentProg);
   }
}
