#pragma once
#include "../TokenParser.h"
struct TokenParserUnknown : public TokenParser {
	std::optional<std::string> parse(const std::string& input, size_t& pos) const override {
		return std::nullopt; // No parsing for unknown tokens
	}
	constexpr std::string type() const override { return "Unknown"; };
	constexpr int precedence() const override { return 0; };
}; 