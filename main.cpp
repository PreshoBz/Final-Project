// main.cpp
// Gets input and shows the tokens found.

#include <iostream>
#include <vector>
#include "scanner.h"
using namespace std;

int main() {
    string input;
    cout << "Enter input: ";
    getline(cin, input);

    size_t position = 0;
    vector<Token> tokens;

    // Get all tokens from input
    while (true) {
        Token token = getNextToken(input, position);
        if (token.type == END_OF_INPUT) break;
        tokens.push_back(token);
    }

    // Print each token
    for (const Token& token : tokens) {
        cout << "Token(Type: ";
        switch (token.type) {
            case NUMBER: cout << "NUMBER"; break;
            case ADDITION: cout << "ADDITION"; break;
            case SUBTRACTION: cout << "SUBTRACTION"; break;
            case MULTIPLICTION: cout << "MULTIPLICTION"; break;
            case DIVISION: cout << "DIVISION"; break;
            case LEFT_PARENTHESIS: cout << "LEFT_PARENTHESIS"; break;
            case RIGHT_PARENTHESIS: cout << "RIGHT_PARENTHESIS"; break;
            case UNKNOWN: cout << "UNKNOWN"; break;
            default: cout << "OTHER";
        }
        cout << ", Value: \"" << token.value << "\")\n";
    }

    return 0;
}
