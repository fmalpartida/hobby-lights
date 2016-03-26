#include <Arduino.h>
#include <program.hpp>
#include <serialMenu.hpp>


program myProgram;
serialMenu myInput;


void setup ()
{
   Serial.begin(115200);
   myProgram.init(0);
   myInput.printOptions(&myProgram);

}

void loop ()
{
   command *newCommand;

   myProgram.playProgram();
   newCommand = myInput.getCommand();

   if ( newCommand != NULL )
   {
      newCommand->execute(&myProgram);
      myInput.printOptions(&myProgram);
   }
}
