#pragma once
#include "TokenType.h"
#include <string>
#include <sstream>
class Token {
private:
    const std::string value;
    const TokenType type;

public:
    explicit Token(std::string value, TokenType type) : value(std::move(value)), type(type) {}

    std::string toString() const {
        const char* tokenTypes[] = { "INVALID", "NUMBER", "OPERATOR", "PUNCTUATION" };

        std::stringstream ss;
        ss << "type: " << tokenTypes[static_cast<int>(this->type)];
        ss << ", value: " << this->value;

        return ss.str();
    }
};