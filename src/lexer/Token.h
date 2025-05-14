#pragma once

#include <string>

#include "TokenType.h"

class Token {
public:
    Token(TokenType type, std::string&& lexeme, std::string&& literal, int line);

    std::string toString();

private:
    TokenType type;
    std::string lexeme;
    std::string literal;
    int line;
};
