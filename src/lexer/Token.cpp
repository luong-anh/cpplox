#include "Token.h"

Token::Token(TokenType type, std::string&& lexeme, std::string&& literal, int line)
    : type_(type), lexeme_(std::move(lexeme)), literal_(std::move(literal)), line_(line){};

std::string Token::toString() { return TokenTypeNames.at(type_) + " " + lexeme_ + " " + literal_; }
