
#ifndef LEXER_H
#define LEXER_H

#include <string>
#include <vector>
#include "token.h"

using namespace std;

class Lexer
{
private:
    string source;
    int position;
    int line;
    int column;

public:
    Lexer(string input)
    {
        source = input;
        position = 0;
        line = 1;
        column = 1;
    }

    char currentChar()
    {
        if (position >= source.length())
        {
            return '\0';
        }

        return source[position];
    }

    void advance()
    {
        if (position < source.length())
        {
            if (source[position] == '\n')
            {
                line++;
                column = 1;
            }
            else
            {
                column++;
            }

            position++;
        }
    }

    void skipWhitespace()
    {
        while (currentChar() == ' ' ||
               currentChar() == '\t' ||
               currentChar() == '\n' ||
               currentChar() == '\r')
        {
            advance();
        }
    }

    bool isLetter(char ch)
    {
        return (ch >= 'a' && ch <= 'z') ||
               (ch >= 'A' && ch <= 'Z');
    }

    bool isDigit(char ch)
    {
        return ch >= '0' && ch <= '9';
    }

    bool isKeyword(string word)
    {
        if (word == "int" ||
            word == "float" ||
            word == "double" ||
            word == "char" ||
            word == "void" ||
            word == "return" ||
            word == "if" ||
            word == "else" ||
            word == "while" ||
            word == "for")
        {
            return true;
        }

        return false;
    }

    Token readWord()
    {
        string word = "";

        int startLine = line;
        int startColumn = column;

        word += currentChar();
        advance();

        while (isLetter(currentChar()) ||
               isDigit(currentChar()) ||
               currentChar() == '_')
        {
            word += currentChar();
            advance();
        }

        Token token;

        if (isKeyword(word))
        {
            token.type = TokenType::KEYWORD;
        }
        else
        {
            token.type = TokenType::IDENTIFIER;
        }

        token.lexeme = word;
        token.line = startLine;
        token.column = startColumn;

        return token;
    }

    Token readNumber()
    {
        string number = "";

        int startLine = line;
        int startColumn = column;

        while (isDigit(currentChar()))
        {
            number += currentChar();
            advance();
        }

        Token token;

        token.type = TokenType::NUMBER;
        token.lexeme = number;
        token.line = startLine;
        token.column = startColumn;

        return token;
    }

    Token readOperator()
    {
        string op = "";

        int startLine = line;
        int startColumn = column;

        op += currentChar();
        advance();

        if ((op == "=" || op == "!" ||
             op == "<" || op == ">") &&
            currentChar() == '=')
        {
            op += currentChar();
            advance();
        }

        Token token;

        token.type = TokenType::OPERATOR;
        token.lexeme = op;
        token.line = startLine;
        token.column = startColumn;

        return token;
    }

    Token readSeparator()
    {
        string separator = "";

        int startLine = line;
        int startColumn = column;

        separator += currentChar();
        advance();

        Token token;

        token.type = TokenType::SEPARATOR;
        token.lexeme = separator;
        token.line = startLine;
        token.column = startColumn;

        return token;
    }

    vector<Token> tokenize()
    {
        vector<Token> tokens;

        while (currentChar() != '\0')
        {
            skipWhitespace();

            if (currentChar() == '\0')
            {
                break;
            }

            if (isLetter(currentChar()) || currentChar() == '_')
            {
                tokens.push_back(readWord());
            }
            else if (isDigit(currentChar()))
            {
                tokens.push_back(readNumber());
            }
            else if (currentChar() == '+' ||
                     currentChar() == '-' ||
                     currentChar() == '*' ||
                     currentChar() == '/' ||
                     currentChar() == '%' ||
                     currentChar() == '=' ||
                     currentChar() == '!' ||
                     currentChar() == '<' ||
                     currentChar() == '>')
            {
                tokens.push_back(readOperator());
            }
            else if (currentChar() == ';' ||
                     currentChar() == ',' ||
                     currentChar() == '(' ||
                     currentChar() == ')' ||
                     currentChar() == '{' ||
                     currentChar() == '}' ||
                     currentChar() == '[' ||
                     currentChar() == ']')
            {
                tokens.push_back(readSeparator());
            }
            else
            {
                Token token;

                token.type = TokenType::INVALID;
                token.lexeme = string(1, currentChar());
                token.line = line;
                token.column = column;

                tokens.push_back(token);

                advance();
            }
        }

        return tokens;
    }
};

#endif
