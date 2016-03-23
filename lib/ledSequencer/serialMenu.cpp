#include <serialMenu.hpp>

int processSerial ( )
{
   static String inString = "";
   int retVal = -1;

   while (Serial.available() > 0) {

      char inChar = Serial.read();

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
         retVal = inString.toInt();
         inString = ""; // Clear it for the next input
      }
   }
   return (retVal);
}
