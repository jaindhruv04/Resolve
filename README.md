
# Resolve

**Resolve** is a C++-based Lexical Analyzer (LEX Tool) that reads source code, identifies tokens, detects invalid characters, and continues scanning after encountering lexical errors.

The project demonstrates the basic working of lexical analysis, an important phase of compiler design.

## Features

- **Keyword Recognition:** Identifies reserved keywords such as `int`, `float`, `return`, `if`, and `while`.
- **Identifier Recognition:** Recognizes variable names and other identifiers.
- **Number Recognition:** Identifies integer literals.
- **Operator Recognition:** Detects arithmetic, assignment, and comparison operators.
- **Separator Recognition:** Identifies symbols such as semicolons, commas, parentheses, and braces.
- **Invalid Token Detection:** Identifies unrecognized characters in the source code.
- **Error Recovery:** Continues lexical analysis after encountering invalid characters.
- **Position Tracking:** Tracks the line and column of each token.
- **CLI Interface:** Accepts source code directly through the terminal and displays the generated tokens.

## Technologies Used

- C++
- Standard Template Library (STL)
- Object-Oriented Programming

## Project Structure

```text
Resolve/
│
├── include/
│   ├── token.h
│   └── lexer.h
│
├── src/
│   ├── main.cpp
│   ├── token.cpp
│   └── lexer.cpp
│
├── .gitignore
├── LICENSE
└── README.md
```

## Token Types

Resolve currently supports six token categories:

| Token Type | Description | Example |
|---|---|---|
| KEYWORD | Reserved programming words | `int`, `return` |
| IDENTIFIER | Variable names and identifiers | `age`, `marks` |
| NUMBER | Integer literals | `20`, `95` |
| OPERATOR | Arithmetic and comparison operators | `+`, `=`, `==` |
| SEPARATOR | Punctuation and grouping symbols | `;`, `()`, `{}` |
| INVALID | Unrecognized characters | `@`, `#` |

## Getting Started

### Prerequisites

- A C++ compiler (G++ recommended)
- A terminal or command-line interface

### Compilation

Clone the repository:

```bash
git clone https://github.com/jaindhruv04/Resolve.git
```

Navigate to the project directory:

```bash
cd Resolve
```

Compile the source files:

```bash
g++ src/main.cpp src/token.cpp src/lexer.cpp -o Resolve
```

### Run the Program

On Windows:

```powershell
.\Resolve.exe
```

On Linux or macOS:

```bash
./Resolve
```

## Usage

After running the program, enter source code directly into the terminal.

Type `END` on a new line to finish entering the source code and start lexical analysis.

### Example Input

```cpp
int age = 20;
float marks = 95;
return age;
```

### Example Output

```text
TOKEN TABLE
-----------------------------------------------
TYPE            LEXEME          LINE    COLUMN
-----------------------------------------------
KEYWORD         int             1       1
IDENTIFIER      age             1       5
OPERATOR        =               1       9
NUMBER          20              1       11
SEPARATOR       ;               1       13
KEYWORD         float           2       1
IDENTIFIER      marks           2       7
OPERATOR        =               2       13
NUMBER          95              2       15
SEPARATOR       ;               2       17
KEYWORD         return          3       1
IDENTIFIER      age             3       8
SEPARATOR       ;               3       11
```

## Error Detection and Recovery

Resolve detects invalid characters during lexical analysis.

When an unrecognized character is encountered:

1. It generates an `INVALID` token.
2. It records the character's line and column.
3. It advances past the invalid character.
4. It continues scanning the remaining source code.

### Example Input

```cpp
int marks = @95;
return marks;
```

The Lexer identifies `@` as an invalid token and continues recognizing the remaining tokens.

## Project Objective

The objective of Resolve is to demonstrate the implementation of a basic lexical analyzer using C++.

It focuses on token identification, lexical error detection, position tracking, and basic error recovery through a command-line interface.

## Future Improvements

- Support for additional keywords and operators.
- Improved handling of malformed numeric literals.
- Support for string and character literals.
- Expanded lexical error handling.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.
