#include "../include/token.h"

string tokenTypeToString(TokenType type)
{
    switch (type)
    {
    case TokenType::KEYWORD:
        return "KEYWORD";

    case TokenType::IDENTIFIER:
        return "IDENTIFIER";

    case TokenType::NUMBER:
        return "NUMBER";

    case TokenType::OPERATOR:
        return "OPERATOR";

    case TokenType::SEPARATOR:
        return "SEPARATOR";

    case TokenType::INVALID:
        return "INVALID";

    default:
        return "UNKNOWN";
    }
}