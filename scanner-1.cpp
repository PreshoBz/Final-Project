#include <cctype>  
#include <iostream>
#include <vector>
using namespace std;

enum TokenType {
    NUMBER,
    UNKNOWN,
    END_OF_INPUT,
    ADDITION,
    SUBTRACTION,
    MULTIPLICTION,
    DIVISION,
    RIGHT_PARENTHESIS,
    LEFT_PARENTHESIS

};

struct Token {
    TokenType type;
    string value;
    Token(TokenType typeOfToken, const string& valueOfToken) {
        type = typeOfToken;
        value = valueOfToken;
     }
 
};

Token getNextToken(const string& input, size_t& pos);

int main() {
    string input;
    cout << "Enter input: ";
    getline(cin, input);

    size_t position = 0;
    vector<Token> tokens;

    while (true) {
        Token token = getNextToken(input, position);
        if (token.type == END_OF_INPUT) {
            break;
        } 
        tokens.push_back(token);
    }

    for (size_t i = 0; i < tokens.size(); i++) {
        const Token& token = tokens[i];
        cout << "Token(Type: ";
        switch (token.type) {
            case NUMBER: 
                cout << "NUMBER";
                break;
            case UNKNOWN: 
                cout << "UNKNOWN";
                break;
            case ADDITION:
                cout << "ADDITION";
                break;
            case SUBTRACTION:
                cout << "SUBTRACTION";
            break;
            case MULTIPLICTION:
                cout << "MULTIPLICTION";
            break;
            case DIVISION:
                cout << "DIVISION";
            break;
            case LEFT_PARENTHESIS:
                cout << "LEFT_PARENTHESIS";
            break;
            case RIGHT_PARENTHESIS:
                cout << "RIGHT_PARENTHESIS";
            break;
            default: cout << "OTHER";
        }
        cout << ", Value: \"" << token.value << "\")\n";
    }

    return 0;
}


Token getNextToken(const string& input, size_t& pos) {
    while (pos < input.length() && isspace(input[pos])) {
        pos++;
    }

    if (pos >= input.length()) {
        return { END_OF_INPUT, "" };
    }

    // Check for negative number
    if(input[pos] == '-') {
    if ( pos + 1 < input.length() && isdigit(input[pos + 1])) {
        string number;
        number += input[pos]; // Add '-'
        pos++; // Advance past '-'

        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos];
            pos++;
        }

        return Token(NUMBER, number);
    } else {
        pos++;
        return Token(SUBTRACTION, "-");
    }
}

    // Check for positive number
    if (isdigit(input[pos])) {
        string number;
        while (pos < input.length() && isdigit(input[pos])) {
            number += input[pos];
            pos++;
        }
        return Token(NUMBER, number);
    }

     // Check for expressions
    switch(input[pos]){
        case '+': pos++; return{
            ADDITION,"+"
        };
        case '*': case 'x': pos++; return{
            MULTIPLICTION,"*"
        };
        case '/': pos++; return{
            DIVISION,"/"
        };
        case '(': pos++; return{
            LEFT_PARENTHESIS,"("
        };
        case ')': pos++; return{
            RIGHT_PARENTHESIS,")"
        };
           //  Handle unknown token
   default: return { UNKNOWN, string(1, input[pos++]) };
        


    }
}
