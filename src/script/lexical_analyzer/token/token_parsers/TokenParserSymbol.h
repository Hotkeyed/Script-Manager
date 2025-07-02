#pragma once
#include "../TokenParser.h"

struct TokenParserSymbol : public TokenParser {
    std::optional<std::string> parse(const std::string& input, size_t& pos) const override {
        if (keywords().contains(input.substr(pos,1))) {
            std::string sym(1, input[pos]);
            pos++;
            return sym;
        }
        return std::nullopt;
    }
    constexpr std::string type() const override { return "Symbol"; };
    virtual const std::unordered_set<std::string> keywords() const override {
        return {
            "(", ")", "{", "}", ";", ":", ","
        };
    }
    constexpr int precedence() const override { return 6; };
};