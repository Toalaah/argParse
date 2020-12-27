A simple library aimed to alleviate the pain of handling and parsing command line arguments.

### Installation

Simply clone the repository with 

```bash 
git clone https://github.com/toalaah/argParse 
``` 

and copy **parser.h** as well as **parser.c** into your desired project. All that's left now is to include the library in your main file with 

```c
#include "parser.h"
```

### Example

```c

  float foo = 3.1415192;
  char *bar = "Hello world!";

  argParser *parser = createParser("An argument parser");

  addArgument(parser, "-f", TYPE_FLOAT, (void *)&foo, "Override default float");
  addArgument(parser, "-b", TYPE_STRING, (void *)&bar, "Override default string");

  parseArguments(parser, argv, argc);
```

The example above illustrates how the variables **foo** and **bar** become tethered to the command-line arguments `-f` and `-b` respectively. The full example file (with additional comments) can be found in `examples/main.c` and can be compiled with `make example`.    

Note: when using the library with C++ files you may need to cast the strings in `addArgument` as `(char *)`, other than that everything else should work fine.

### Compiling

These are the ways I recommend compiling the object files for C++ and C projects respectively:

```bash
 g++ -std=c++17 -w -c parser.c -o parser.o     // C++
 gcc -std=c99 -c parser.c -o parser.o          // C
```

### Still in Progress

* Add support for non-argument parameters (eg. --help or --version)
* Fix bugs which I have inevitably overlooked
* Make error handling more robust

