#pragma once
#include "../TokenParser.h"
struct TokenParserHotkey : public TokenParser {
	std::optional<std::string> parse(const std::string& input, size_t& pos) const override {
        if (input[pos] != '[') return std::nullopt;
		pos++; // skip opening left bracket
        std::string result;
        while (pos < input.size() && input[pos] != ']') {
            if (input[pos] == '\\' && input[pos+1] == ']') {
				pos++; // skip escape character
            }
            result += input[pos++];
        }
        if (pos < input.size() && input[pos] == ']') pos++; // skip closing bracket
        return result; // No parsing for unknown tokens
	}
	constexpr std::string type() const override { return "Hotkey"; };
	constexpr int precedence() const override { return 10; };
};