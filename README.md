
# Monty Bytecode Interpreter

## Overview
Monty 0.98 is a scripting language that is first compiled into Monty bytecodes. It relies on a unique stack and uses specific instructions to manipulate it. The goal of this project is to create an interpreter for Monty ByteCodes files, part of a school project to learn about data structures (stacks, queues) and interpreting.

## Features
- **Basic Stack Operations**: Implements stack operations such as `push`, `pall`, `pint`, `pop`, etc.
- **Queue Operations**: Supports toggling between stack and queue modes using the `queue` and `stack` commands.
- **Comprehensive Error Management**: Ensures robust error handling for file I/O, syntax, and runtime errors.

## Installation

### Prerequisites
- GCC (GNU Compiler Collection)
- Git for cloning the repository

### Compiling the Program
Clone the repository and compile using GCC with C89 standard flags:

```bash
git clone https://github.com/Hassan220022/monty.git
cd monty
gcc -Wall -Werror -Wextra -pedantic -std=c89 *.c -o monty
```

## Usage
To run the program with a Monty bytecode file:

```bash
./monty bytecode_file.m
```
Replace `bytecode_file.m` with the path to a valid Monty bytecode file.

### Example
Run a provided bytecode script:

```bash
./monty bytecodes/00.m
```
This command executes the Monty commands in the `00.m` file.

## Supported Commands
- `push <int>`: Pushes an integer onto the stack.
- `pall`: Prints all the values on the stack from the top.
- `pint`: Displays the value at the top of the stack.
- `pop`: Removes the top element of the stack.
- Other commands include `swap`, `add`, `nop`, etc.

## Contributing
Contributions are welcome! To contribute:
1. Fork the repository.
2. Create your feature branch (`git checkout -b feature/AmazingFeature`).
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`).
4. Push to the branch (`git push origin feature/AmazingFeature`).
5. Open a Pull Request.

## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Authors
- **Hassan Mahmoud** - *Initial work* - [Hassan220022](https://github.com/Hassan220022)

## Acknowledgments
- Thanks to the ALX School for providing the project guidelines.
- Inspiration from various open-source projects and code snippets.


### Customization and Personalization
The provided README is structured to reflect your GitHub repository for the Monty interpreter project. Ensure you:
- Check all links, especially the link to the LICENSE file, which should be valid in your repository.
- Adjust any project-specific details as necessary.
- Verify the list of commands and features to match those implemented in your project.

This README.md file will help users understand how to install, run, and contribute to your Monty interpreter project efficiently.