#pragma once
#include "../TokenParser.h"
struct TokenParserEndOfFile : public TokenParser {
	std::optional<std::string> parse(const std::string& input, size_t& pos) const override {
		return std::nullopt; 
	}
	constexpr std::string type() const override { return "End Of File"; };
	constexpr int precedence() const override { return 1; };
};