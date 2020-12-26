#include <stdio.h>
#include "../parser.h"

int main(int argc, char **argv)
{
  // example variables
  float defaultFloat = 3.1415192;
  float originalFloat = defaultFloat;

  // example variables
  string defaultStr = "Hello world!";
  string originalStr = defaultStr;

  // example variables
  int defaultInt = 42;
  int originalInt = defaultInt;

  // create an argument parser with description 'An argument parser'
  argParser *parser = createParser("An argument parser");

  // add arguments to parser with pointers to desired variables
  addArgument(parser, "-i", TYPE_INT, (void *)&defaultInt, "Override default int");
  addArgument(parser, "-f", TYPE_FLOAT, (void *)&defaultFloat, "Override default float");
  addArgument(parser, "-s", TYPE_STRING, (void *)&defaultStr, "Override default string");

  // parse arguments
  parseArguments(parser, argv, argc);
   
  // examine changes / overrides of default example variables
  printf("Default int is: %d (was %d)\n", defaultInt, originalInt);
  printf("Default float is: %f (was %f)\n", defaultFloat, originalFloat);
  printf("Default string is: '%s' (was '%s')\n", defaultStr, originalStr);

  // delete parser
  deleteParser(parser);
  return 0;
}
