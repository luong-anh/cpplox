#pragma once

#include <string>

#include "TokenType.h"

class Token {
public:
    Token(TokenType type, std::string&& lexeme, std::string&& literal, int line);

    std::string toString();

private:
    TokenType type_;
    std::string lexeme_;
    std::string literal_;
    [[maybe_unused]] int line_;
};
