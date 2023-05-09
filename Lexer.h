#pragma once
#include "Token.h"
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>
#include <span>

class Lexer {
public:
    explicit Lexer(std::string input) : input_(std::move(input)), pos_(0) {}

    std::vector<Token> Tokenize() {
        std::vector<Token> tokens;

        while (pos_ < input_.length()) {
            char c = input_[pos_];

            if (std::isdigit(c)) {
                tokens.push_back(ScanNumber());
            }
            else if (IsOperator(c)) {
                tokens.push_back(ScanOperator());
            }
            else if (IsPunctuation(c)) {
                tokens.push_back(ScanPunctuation());
            }
            else {
                ++pos_;
            }
        }

        return tokens;
    }

private:
    std::string input_;
    std::size_t pos_;

    Token ScanNumber() {
        size_t start_pos = pos_;
        while (pos_ < input_.length() && std::isdigit(input_[pos_])) {
            ++pos_;
        }
        std::span<const char> number_span(input_.data() + start_pos, pos_ - start_pos);
        return Token{ std::string(number_span.data(), number_span.size()), TokenType::NUMBER };
    }

    bool IsOperator(char c) const {
        return c == '+' || c == '-' || c == '*' || c == '/';
    }

    bool IsPunctuation(char c) const {
        return c == '(' || c == ')' || c == '{' || c == '}' || c == ';';
    }


    Token ScanOperator() {
        std::span<const char> operator_span(input_.data() + pos_, 1);
        ++pos_;
        return Token{ std::string(operator_span.data(), operator_span.size()), TokenType::OPERATOR };
    }


    Token ScanPunctuation() {
        std::span<const char> punctuation_span(input_.data() + pos_, 1);
        ++pos_;
        return Token{ std::string(punctuation_span.data(), punctuation_span.size()), TokenType::PUNCTUATION };
    }
};
