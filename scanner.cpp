// scanner.cpp
// Code to find tokens from the input string.

#include "scanner.h"
#include <cctype>

// Token constructor
Token::Token(TokenType typeOfToken, const string& valueOfToken) {
    type = typeOfToken;
    value = valueOfToken;
}

// Finds the next token in the input
Token getNextToken(const string& input, size_t& pos) {
    // Skip spaces
    while (pos < input.length() && isspace(input[pos])) {
        pos++;
    }

    // If we're at the end, return END_OF_INPUT
    if (pos >= input.length()) {
        return { END_OF_INPUT, "" };
    }

    // Check for negative number like -5
    if (input[pos] == '-') {
        if (pos + 1 < input.length() && isdigit(input[pos + 1])) {
            string number;
            number += input[pos++]; // Add '-'
            while (pos < input.length() && isdigit(input[pos])) {
                number += input[pos++];
            }
            return Token(NUMBER, number);
        } else {
            pos++;
            return Token(SUBTRACTION, "-");
        }
    }

    // Check for regular number
    if (isdigit(input[pos])) {
        string number;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos++];
        }
        return Token(NUMBER, number);
    }

    // Check for symbols and operators
    switch (input[pos]) {
        case '+': pos++; return { ADDITION, "+" };
        case '*': case 'x': pos++; return { MULTIPLICTION, "*" };
        case '/': pos++; return { DIVISION, "/" };
        case '(': pos++; return { LEFT_PARENTHESIS, "(" };
        case ')': pos++; return { RIGHT_PARENTHESIS, ")" };
        default:
            // Anything else is unknown
            return { UNKNOWN, string(1, input[pos++]) };
    }
}
