# Console Calculator Project

## Overview

This project was created as part of an assignment for BGTU. The Console Calculator is a simple calculator program that parses a mathematical expression provided by the user, builds a tree of mathematical operations, and computes the result. It currently supports the following operations:

- Addition (`+`)
- Subtraction (`-`)
- Multiplication (`*`)
- Division (`/`)

### Limitations:
- Unary operations (e.g., `-5`) are not supported.
- Parentheses for grouping operations are not supported.

## Project Structure

- **include/ConsoleCalculator/i_calculator.h**  
  Defines the `ICalculator` interface, which exposes the `Evaluate` method that accepts a mathematical expression as a string and returns a `double` result.

- **src/calculator.h & src/calculator.cpp**  
  Implements the `Calculator` class that parses and evaluates the mathematical expression by constructing a tree of operations.

- **src/main.cpp**  
  The entry point of the console application, where user input is collected and passed to the `Calculator` for evaluation. The result is printed to the console.

### Key Components:
- **Parsers**  
  Various parser classes handle different parts of the mathematical expression, such as numbers and operators. Each operator has its own parser class (e.g., `AdditionOperatorParser`, `DivisionOperatorParser`).

- **Models**  
  The models represent the parsed mathematical entities:
  - `BaseOperand`, `Number`: Represents numbers in the expression.
  - `BaseBinaryOperator`, `AdditionOperator`, `DivisionOperator`, etc.: Represents binary operations.

- **Controllers**  
  The `MathExpressionController` orchestrates the parsing process and manages the root node of the parsed expression tree.

## How to Build and Run

### Requirements:
- C++ compiler (e.g., MSVC, GCC)
- CMake for project configuration

### Steps:
1. Clone the repository to your local machine.
2. Run the provided batch script `cmake_build.bat` or manually follow the steps below.

### Building with CMake:
To build the project using CMake on Windows, follow these steps:

1. Create the build directory:
   ```sh
   mkdir build
   cd build

2. Run CMake to generate the project files for Visual Studio:
   ```sh
   cmake -G "Visual Studio 17 2022" ..

3. Build the project using the generated Visual Studio files:
   ```sh
   cmake --build . --config Release --target ConsoleCalculator

## Usage

To use the console calculator, follow these steps:

1. Run the calculator using the provided `cmake_build.bat` script to compile the project.
2. Once compiled, run the executable `ConsoleCalculator.exe`.

### Example

Enter a mathematical expression such as:
   ```sh
   Enter math expression: 3 + 5 * 2 - 8 / 4
   Result: 11
