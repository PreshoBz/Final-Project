// scanner.h
// Defines tokens and the getNextToken function.

#ifndef SCANNER_H
#define SCANNER_H

#include <string>
using namespace std;

// Different types of tokens in a math expression
enum TokenType {
    NUMBER,             // A number like 3 or -5
    UNKNOWN,            // Something not recognized
    END_OF_INPUT,       // No more input
    ADDITION,           // +
    SUBTRACTION,        // -
    MULTIPLICTION,      // * or x
    DIVISION,           // /
    RIGHT_PARENTHESIS,  // )
    LEFT_PARENTHESIS    // (
};

// A token has a type and its text value
struct Token {
    TokenType type;
    string value;

    // Constructor for a token
    Token(TokenType typeOfToken, const string& valueOfToken);
};

// Finds and returns the next token in the input
Token getNextToken(const string& input, size_t& pos);

#endif
