#include <serialMenu.hpp>

command::command()
{
   myCommand = -1;
   value = -1;
}

void command::execute(program *myProgram)
{

   if (myCommand == SET_PROGRAM )
   {
      if ((value>= 0) && (value < myProgram->getNumPrograms()) &&
         (value != myProgram->getCurrentProgram()))
         {
            myProgram->loadProgram(value);
         }
   }

   if (myCommand == SET_PERIOD )
   {
      if ((value>= 0) && (value != myProgram->getPeriod()))
         {
            myProgram->setPeriod(value);
         }
   }

   if (myCommand == LIST_PROGRAMS)
   {
      uint16_t numProgs = myProgram->getNumPrograms();

      Serial.println("Programs: ");
      for (uint16_t i=0; i < numProgs; i++)
      {
         Serial.print(i);
         Serial.print(" ");
         Serial.println(myProgram->getProgramName(i));
      }
   }
}


serialMenu::serialMenu()
{

}

command *serialMenu::getCommand ( )
{
   static String inString = "";
   command *retVal = NULL;

   while (Serial.available() > 0) {

      char inChar = Serial.read();

      if (inChar == 'p')
      {
         _command.myCommand = SET_PROGRAM;
      }
      if (inChar == 'f')
      {
         _command.myCommand = SET_PERIOD;
      }
      if (inChar == 'h')
      {
         _command.myCommand = LIST_PROGRAMS;
      }

      if (isDigit(inChar))
      {
         // convert the incoming byte to a char
         // and add it to the string:
         inString += inChar;
      }

      // if you get a newline, print the string,
      // then the string's value:
      if (inChar == '\n')
      {
         _command.value = inString.toInt();
         inString = ""; // Clear it for the next input
         retVal = &_command;
      }
   }
   return (retVal);
}


void serialMenu::printOptions(program *currentProg)
{
   Serial.println("");
   Serial.println("Current settings: ");
   Serial.print("\tNum. Programs: ");
   Serial.println(currentProg->getNumPrograms());
   Serial.print("\tCurrent Program: ");
   Serial.println(currentProg->getCurrentProgram());
   Serial.print("\tCurrent Period: ");
   Serial.println(currentProg->getPeriod());
   Serial.print("Options: p <program id>, f <period>, h (list programs)\n");
}
