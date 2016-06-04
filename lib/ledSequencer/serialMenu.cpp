#include <serialMenu.hpp>

command::command()
{
   myCommand = -1;
   value = -1;
}

void command::execute(program *myProgram)
{
   uint16_t numProgs = myProgram->getNumPrograms();

   if (myCommand == SET_PROGRAM )
   {
      if ((value>= 0) && (value < numProgs) &&
         (value != myProgram->getCurrentProgram()))
         {
            myProgram->loadProgram(value, true); // load program and store
         }
   }

   if (myCommand == SET_PERIOD )
   {
      if ((value>= 0) && (value != myProgram->getPeriod()))
         {
            myProgram->setPeriod(value, true); // load period and store
         }
   }

   if (myCommand == LIST_PROGRAMS )
   {
      for (uint16_t i=0; i < numProgs; i++)
      {
         Serial.print(i);
         Serial.print(". ");
         Serial.println(myProgram->getProgramName(i));
      }
   }


   if (myCommand == GET_INFO)
   {
      Serial.println("Programs: ");
      for (uint16_t i=0; i < numProgs; i++)
      {
         Serial.print(i);
         Serial.print(". ");
         Serial.println(myProgram->getProgramName(i));
      }
      this->listCommands(myProgram);
   }
}

// private methods
void command::listCommands(program *currentProg)
{
   Serial.println("");
   Serial.println("Current settings: ");
   Serial.print("\tNum. Programs: ");
   Serial.println(currentProg->getNumPrograms());
   Serial.print("\tCurrent Program: ");
   Serial.println(currentProg->getCurrentProgram());
   Serial.print("\tCurrent Period: ");
   Serial.println(currentProg->getPeriod());
   Serial.print("Options: p <program id>, s <speed>, l (list programs), i (information)\n");
}

serialCommand::serialCommand()
{

}

command *serialCommand::getCommand ( )
{
   static String inString = "";
   command *retVal = NULL;

   while (Serial.available() > 0) {

      char inChar = Serial.read();
      Serial.write(inChar);

      if (inChar == 'p')
      {
         _command.myCommand = SET_PROGRAM;
      }
      if (inChar == 's')
      {
         _command.myCommand = SET_PERIOD;
      }
      if (inChar == 'l')
      {
         _command.myCommand = LIST_PROGRAMS;
      }

      if (inChar == 'i')
      {
         _command.myCommand = GET_INFO;
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
