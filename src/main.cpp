
#include <iostream>
#include "../include/lexer.h"

using namespace std;

int main()
{
    string input;

    cout << "Enter source code (type END on a new line to finish):" << endl;

    string line;

    while (getline(cin, line))
    {
        if (line == "END")
        {
            break;
        }

        input += line + "\n";
    }

    Lexer lexer(input);

    vector<Token> tokens = lexer.tokenize();

    cout << "\nTOKEN TABLE\n";
    cout << "-----------------------------------------------\n";
    cout << "TYPE\t\tLEXEME\t\tLINE\tCOLUMN\n";
    cout << "-----------------------------------------------\n";

    for (int i = 0; i < tokens.size(); i++)
    {
        cout << tokenTypeToString(tokens[i].type) << "\t\t"
             << tokens[i].lexeme << "\t\t"
             << tokens[i].line << "\t"
             << tokens[i].column << endl;
    }

    return 0;
}
