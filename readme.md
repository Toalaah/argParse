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

The example above illustrates how the variables **foo** and **bar** become tethered to the command-line arguments `-f` and `-b` respectively. The full example file (with additional comments) can be found in `examples/main.c` and can be compiled and run with `make example`.

### Still in Progress

* Add support for non-argument parameters (eg. --help or --version)
* Fix bugs which I have inevitably overlooked
* Make error handling more robust

