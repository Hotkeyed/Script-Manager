#pragma once
#include "../TokenParser.h"
struct TokenParserOperator : public TokenParser {
    std::optional<std::string> parse(const std::string& input, size_t& pos) const override {
        size_t maxLen = (((size_t(3)) < (input.size() - pos)) ? (size_t(3)) : (input.size() - pos));
        for (size_t len = maxLen; len > 0; --len) {
            std::string candidate = input.substr(pos, len);
            if (keywords().contains(candidate)) {
                pos += len;
                return candidate;
            }
        }
        return std::nullopt;
    }
    constexpr std::string type() const override { return "Operator"; };
    virtual const std::unordered_set<std::string> keywords() const override {
        return {
		 "+", "-", "*", "/", "%", "=", "==", "!=", "<", "<=", ">", ">=","++", "--",
        "&&", "||", "!", "&", "|", "^", "~",
        "<<", ">>", "<<=", ">>=", "+=", "-=", "*=", "/=", "%=", "&=", "|=", "^="
        };
    }
    constexpr int precedence() const override { return 7; };
};