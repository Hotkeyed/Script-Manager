#pragma once
#pragma once
#include "../TokenParser.h"

struct TokenParserComment : public TokenParser {
    std::optional<std::string> parse(const std::string& input, size_t& pos) const override {
        size_t start = pos;

        // Single-line comment
        if (input[pos] == '/' && pos + 1 < input.size() && input[pos + 1] == '/') {
            pos += 2;
            std::string content;
            while (pos < input.size() && input[pos] != '\n') {
                content += input[pos++];
            }
            return content;
        }

        // Multi-line comment
        if (input[pos] == '/' && pos + 1 < input.size() && input[pos + 1] == '*') {
            pos += 2;
            std::string content;
            while (pos + 1 < input.size() && !(input[pos] == '*' && input[pos + 1] == '/')) {
                content += input[pos++];
            }
            if (pos + 1 < input.size()) {
                pos += 2; // Skip closing */
            }
            return content;
        }

        return std::nullopt;
    }
    constexpr std::string type() const override { return "Comment"; };
    constexpr int precedence() const override { return 11; };
};