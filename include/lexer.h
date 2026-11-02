
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

    vector<Token> tokenize();
};

#endif
