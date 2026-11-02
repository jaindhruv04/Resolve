#ifndef TOKEN_H
#define TOKEN_H

#include <string>
using namespace std;

enum class TokenType
{
    KEYWORD,
    IDENTIFIER,
    NUMBER,
    OPERATOR,
    SEPARATOR,
    INVALID
};

class Token
{
public:
    TokenType type;
    string lexeme;
    int line;
    int column;
};

string tokenTypeToString(TokenType type);

#endif