#pragma once
#include "../TokenParser.h"

struct TokenParserType : public TokenParser {
    std::optional<std::string> parse(const std::string& input, size_t& pos) const override {
        size_t start = pos;
        if (std::isalpha(input[pos]) || input[pos] == '_') {
            while (pos < input.size() && (std::isalnum(input[pos]) || input[pos] == '_')) pos++;
            std::string word = input.substr(start, pos - start);
            if (keywords().count(word)) {
                return word;
            } else {
                pos = start; // Rewind
            }
        }
        return std::nullopt;
    }
    constexpr std::string type() const override { return "Type"; };
    virtual const std::unordered_set<std::string> keywords() const override {
        return {
             "int", "bool", "float", "string", "void"
        };
    }
    constexpr int precedence() const override { return 5; };
};