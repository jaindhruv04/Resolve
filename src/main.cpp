#include <iostream>
#include "../include/token.h"

using namespace std;

int main()
{
    Token token;

    token.type = TokenType::KEYWORD;
    token.lexeme = "int";
    token.line = 1;
    token.column = 1;

    cout << "Token Type: " << tokenTypeToString(token.type) << endl;
    cout << "Lexeme: " << token.lexeme << endl;
    cout << "Line: " << token.line << endl;
    cout << "Column: " << token.column << endl;

    return 0;
}