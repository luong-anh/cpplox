#include "Token.h"

Token::Token(TokenType type, std::string&& lexeme, std::string&& literal, int line)
    : type(type), lexeme(std::move(lexeme)), literal(std::move(literal)), line(line){};

std::string Token::toString() { return TokenTypeNames.at(type) + " " + lexeme + " " + literal; }
