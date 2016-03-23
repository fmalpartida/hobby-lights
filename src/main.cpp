#include <Arduino.h>
#include <program.hpp>
#include <definedPrograms.hpp>
#include <serialMenu.hpp>

//
ledSequence *demoSequence[] =
   { program1, program2, program3, program4, program5, program6, program7, program8,
      program9, program10, program1 };
int sequenceLength;

// Cycle through the program with a period of 20ms
program myProgram(30);



void setup ()
{
   Serial.begin(115200);
   sequenceLength = sizeof(demoSequence)/sizeof(ledSequence *);

   // Setup initial program
   myProgram.loadProgram(demoSequence[1]);
}

void loop ()
{
   static int currentProg = 0;
   int newProg;

   myProgram.playProgram();
   newProg = processSerial();

   if (( newProg >= 0 ) && ( newProg < sequenceLength ) && (newProg != currentProg))
   {
      currentProg = newProg;
      myProgram.loadProgram(demoSequence[newProg]);
   }
}
