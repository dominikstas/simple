# Simple Terminal Library

Simple Terminal Library is a lightweight C library that provides basic terminal functionalities. It allows users to interact with the terminal by executing simple commands such as echoing text, changing directories, listing directory contents, creating directories, and exiting the terminal.

## Features

- **Echo Text**: Write a specified text to the terminal.
- **Change Directory (cd)**: Navigate through directories.
- **List Directory Contents (ls)**: Display the contents of the current directory.
- **Make Directory (mkdir)**: Create a new directory.
- **Help Command**: Display a list of available commands.
- **Exit Terminal**: Quit the terminal application.

## Usage

To use Simple Terminal Library in your project, follow these steps:

1. Include the `simple.h` header file in your source code.
2. Compile your project with `simple.c`.
3. Implement your main loop to interact with the terminal using the provided functions.

### Example:

```c
#include "simple.h"

int main() {
    char *command;
    init();
    while(1){
        printf(">");
        command = getInput();

        if(strlen(command) != 0){
            execute(command);
            free(command);
        }
    }
    return 0;
}
```

## Building

To build the provided example, you can use CMake:

```bash

mkdir build
cd build
cmake ..
make
```

## Projects Using Simple Terminal Library

   - **Swallow**: [GitHub Repo](https://github.com/dominikstas/Swallow) - A system for working with microcontrollers.
   - **Neutrino**: [GitHub Repo](https://github.com/dominikstas/Neutrino) - A terminal-based program that aids in studying. (In this project, Simple has been translated into C++!)


## Contributing

Contributions to Simple Terminal Library are welcome! If you find any issues or have suggestions for improvements, please open an issue or submit a pull request on the GitHub repository.