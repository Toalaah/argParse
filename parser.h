#ifdef __cplusplus
extern "C" {
#endif
#ifndef PARSER_H
#define PARSER_H

#define MAX_ARGS 10

//#######################  TYPEDEFS & DEFINITIONS  ############################

typedef enum TYPE_T {TYPE_INT, TYPE_STRING, TYPE_FLOAT, TYPE_NONE} TYPE_T;
typedef char* string;

typedef struct arg {
  string name;
  TYPE_T type;
  void *value;
  string desc;
} arg;


typedef struct argParser
{
  string desc;  
  arg args[MAX_ARGS];
  int argCount;
} argParser;


//############################  FUNCTIONS  ####################################

// interface functions
void addArgument(argParser *parser, string name, TYPE_T type, void *value, string desc);
void parseArguments(argParser *parser, char **args, int argc);

// helper functions
void setArg(argParser *parser, int index, char *newValue);
int isValidArg(int i, char **args, argParser *parser);
void parserAbort();

// constructors & initializers
argParser *createParser(string description);

// destructors
void deleteParser(argParser *parser);


//###########################  INFO & DEBUG  ##################################

void parserInfo(argParser *parser);
void argInfo(arg *arg);
void printArgs(argParser *parser);

#endif
#ifdef __cplusplus
}
#endif
