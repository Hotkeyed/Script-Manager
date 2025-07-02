#pragma once
#include "../TokenParser.h"

struct TokenParserIdentifier : public TokenParser {
    std::optional<std::string> parse(const std::string& input, size_t& pos) const override {
        size_t start = pos;
        if (std::isalpha(input[pos]) || input[pos] == '_') {
            while (pos < input.size() && (std::isalnum(input[pos]) || input[pos] == '_')) pos++;
            std::string word = input.substr(start, pos - start);
            return word;
        }
        return std::nullopt;
    }
    constexpr std::string type() const override { return "Identifier"; };
    virtual const std::unordered_set<std::string> keywords() const override {
        return {
            "if", "else", "while", "for", "return", "int", "bool", "float", "string", "true", "false"
        };
    }
    constexpr int precedence() const override { return 8; };
};