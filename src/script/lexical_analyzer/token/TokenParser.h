#pragma once
#include <unordered_set>
#include <string>
#include <memory>
#include <optional>
//abstract class for parsing tokens
struct TokenParser {
	virtual std::optional<std::string> parse(const std::string& input, size_t& pos) const = 0;
	virtual constexpr std::string type() const = 0;
	virtual const std::unordered_set<std::string> keywords() const {return {};}
	virtual constexpr int precedence() const = 0;
};
struct CustomTokenParserComparator {
	bool operator()(const std::shared_ptr<const TokenParser>& lhs, const std::shared_ptr<const TokenParser>& rhs) const {
		return lhs->precedence() > rhs->precedence();
	}
};