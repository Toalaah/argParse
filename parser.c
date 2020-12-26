#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "parser.h"

argParser *createParser(char *description)
{
  // allocates necessary memory and returns pointer to a parser

  argParser *tmp = malloc(sizeof(argParser));
  tmp->desc = description;
  tmp->argCount = 0;

  return tmp;
}

void argInfo(arg *arg) { if(arg->name != NULL) printf("Name: '%s'\nDescription: %s\nType: %d\n", arg->name, arg->desc, arg->type); return; }
void parserInfo(argParser *parser) { printf("* Description: %s\n* Number args: %d\n", parser->desc, parser->argCount); return; }
void printArgs(argParser *parser) { for(int i = 0; i < parser->argCount; i++) { argInfo(&parser->args[i]); } return; }

void addArgument(argParser *parser, string name, TYPE_T type, void *value, string desc)
{
  // adds an argument of given name, type, description,
  // and void pointer to desired variable to the parser
    
  if(name != NULL)
  {
    int i = parser->argCount;
    parser->args[i].name = name;
    parser->args[i].type = type;
    parser->args[i].value = value;
    parser->args[i].desc = desc;
    parser->argCount++;
  }

  return;
}

void setArg(argParser *parser, int index, char *newValue)
{
  /* takes the value and casts it as the apropriate type based on 
     the argument's type attribute casts the argument's void pointer 
     to the apropriate value, which is then set to the new value */

  // find and set type 
  switch(parser->args[index].type)
  {
    case TYPE_INT: 
    {
      int newVal = atoi(newValue); 
      *(int*)(parser->args[index].value) = newVal; 
      break;
    }
    case TYPE_STRING:
    {
      *(char**)(parser->args[index].value) = newValue; 
      break;
    }
    case TYPE_FLOAT:
    {
      float newVal = atof(newValue); 
      *(float*)(parser->args[index].value) = newVal; 
      break;
    }
    case TYPE_NONE:
    {
      break;
    }
  }

  return;
}

int isValidArg(int i, char **args, argParser *parser)
{
  /* checks if a given string is a valid argument (i.e is contained in the
     parser's argument list), and if so returns the index of said argument. 
     otherwise returns -1 */
  
  for(int j = 0; j < parser->argCount; j++)
  {
    if(!(strcmp(parser->args[j].name, args[i])))
      return j;
  }

  return -1;
}

void parserAbort()
{
  /* aborts the parsing process and terminates the process */

  printf("* Error: could not parse arguments. Please check inputs and try again\n");
  exit(EXIT_FAILURE);
}

void parseArguments(argParser *parser, char **args, int argc)
{
  /* parses argument list provided by user and sets values accordingly */
   
  if(2*parser->argCount < argc-1)
  {
    printf("* Error: invalid number of arguments given! Arguments given: %d, Arguments expected: <= %d\n", (argc-1)/2, parser->argCount);
    exit(EXIT_FAILURE);
  }

  for(int i = 1; i < argc; i+=2)
  {
    int index = isValidArg(i, args, parser);
    if(index != -1)
      setArg(parser, index, args[i+1]); 
    else
      parserAbort();
  }

  return;
}


void deleteParser(argParser *parser) 
{ 
  /* frees memory and deletes parser */
  free(parser); 
  return;
}


