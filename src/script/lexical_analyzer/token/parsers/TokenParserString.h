#pragma once
#include "../TokenParser.h"
struct TokenParserString : public TokenParser {
	std::optional<std::string> parse(const std::string& input, size_t& pos) const override {
        if (input[pos] != '"') return std::nullopt;
        pos++; // skip opening quote
        std::string result;
        while (pos < input.size() && input[pos] != '"') {
			//handle escaped characters like \n, \t, \r, \\, and \"
            if (input[pos] == '\\') {
                pos++;
                if (pos >= input.size()) break;
                char escaped = input[pos++];
                switch (escaped) {
                    case 'n': result += '\n'; break;
                    case 't': result += '\t'; break;
                    case 'r': result += '\r'; break;
                    case '\\': result += '\\'; break;
                    case '"': result += '"'; break;
                    default: result += escaped; break;
                }
            } else {
                result += input[pos++];
            }
        }
        if (pos < input.size() && input[pos] == '"') pos++; // skip closing quote
		return result; // No parsing for unknown tokens
	}
	constexpr std::string type() const override { return "String"; };
	constexpr int precedence() const override { return 3; };
};