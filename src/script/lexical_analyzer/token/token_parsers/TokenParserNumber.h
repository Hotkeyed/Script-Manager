#pragma once
#include "../TokenParser.h"
struct TokenParserNumber : public TokenParser {
    std::optional<std::string> parse(const std::string& input, size_t& pos) const override {
        size_t start = pos;
        bool hasDot = false;
        while (pos < input.size() && (std::isdigit(input[pos]) || input[pos] == '.')) {
            if (input[pos] == '.') {
                if (hasDot) break;
                hasDot = true;
            }
            pos++;
        }
        if (pos > start) {
            return input.substr(start, pos - start);
        }
        return std::nullopt;
    }
    constexpr std::string type() const override { return "Number"; };
    constexpr int precedence() const override { return 4; };
};