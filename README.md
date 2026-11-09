# Resolve

**Resolve** is a C++17-based Lexical Analyzer (LEX Tool) that reads source code, identifies tokens, detects invalid characters, and continues scanning after encountering lexical errors.

The project demonstrates the fundamentals of lexical analysis, one of the first phases of compiler design.

## Features

- **Keyword Recognition:** Identifies reserved keywords such as `int`, `float`, `double`, `return`, `if`, and `while`.
- **Identifier Recognition:** Recognizes variable names and identifiers, including those containing underscores and numbers.
- **Integer Recognition:** Identifies integer literals in source code.
- **Operator Recognition:** Detects arithmetic, assignment, and comparison operators, including `==`, `!=`, `<=`, and `>=`.
- **Separator Recognition:** Identifies punctuation and grouping symbols such as semicolons, commas, parentheses, and braces.
- **Invalid Character Detection:** Identifies unrecognized characters in source code.
- **Basic Error Recovery:** Continues lexical analysis after encountering invalid characters.
- **Position Tracking:** Tracks the line and column number of each token.
- **Command-Line Interface:** Accepts multiline source code through the terminal and displays the generated token table.

## Technologies Used

- C++17
- Standard Template Library (STL)
- Object-Oriented Programming
- Git and GitHub

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

- A C++17-compatible compiler (G++ recommended).
- Git installed on your system.
- A terminal or command-line interface.

### 1. Clone the Repository

```bash
git clone https://github.com/jaindhruv04/Resolve.git
```

### 2. Navigate to the Project Directory

```bash
cd Resolve
```

### 3. Compile the Project

Using G++:

```bash
g++ -std=c++17 src/main.cpp src/token.cpp src/lexer.cpp -o Resolve
```

### 4. Run the Program

**Windows:**

```powershell
.\Resolve.exe
```

**Linux/macOS:**

```bash
./Resolve
```

## Usage

After executing the program, enter source code directly into the terminal.

Type `END` on a new line to finish entering the source code and begin lexical analysis.

### Example Input

```cpp
int age = 20;
float marks = 95;
return age;
END
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

Resolve identifies invalid characters during lexical analysis.

When an unrecognized character is encountered:

1. The lexer generates an `INVALID` token.
2. It records the character's line and column position.
3. It advances past the invalid character.
4. It continues scanning the remaining source code.

### Example Input

```cpp
int marks = @95;
return marks;
END
```

In this example, `@` is identified as an invalid token. The lexer continues processing the remaining source code instead of terminating the analysis.

## How It Works

Resolve follows a straightforward lexical analysis process:

1. **Input Collection:** Reads multiline source code from the terminal.
2. **Character Scanning:** Processes the source code character by character.
3. **Token Identification:** Classifies sequences into keywords, identifiers, numbers, operators, and separators.
4. **Error Detection:** Identifies unsupported or unrecognized characters.
5. **Position Tracking:** Maintains the line and column position of each token.
6. **Token Generation:** Stores recognized tokens with their corresponding types and positions.
7. **Output Generation:** Displays the generated token table in the terminal.

## Current Limitations

The current implementation focuses on basic lexical analysis and does not yet provide complete compiler functionality.

Some features not currently implemented include:

- Floating-point number recognition.
- String and character literal handling.
- Single-line and multiline comment handling.
- Complete C++ keyword and operator support.
- Syntax analysis and parsing.
- Semantic analysis.
- Advanced lexical error recovery.

## Future Improvements

Potential enhancements for future versions include:

- Extended support for C++ keywords and operators.
- Recognition of floating-point literals.
- Support for string and character literals.
- Improved handling of malformed numeric literals.
- Better lexical error reporting and recovery.
- Implementation of syntax analysis.
- Introduction of semantic analysis.

## Project Objective

The objective of Resolve is to demonstrate the implementation of a basic lexical analyzer using C++17.

It focuses on token identification, lexical error detection, source position tracking, and basic error recovery through a command-line interface.

The project provides a foundation for understanding compiler design and the different stages involved in processing source code.

## License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---

**Developed by [Dhruv Jain](https://github.com/jaindhruv04)**

GitHub Repository: https://github.com/jaindhruv04/Resolve
