#pragma once
#include <string>
enum TokenType {
	TOKEN_KEYWORD,
	TOKEN_TYPE,
	TOKEN_NUMBER,
	TOKEN_STRING,
	TOKEN_BOOLEAN,
	TOKEN_OPERATOR,
	TOKEN_COMMENT,
	TOKEN_WHITESPACE,
	TOKEN_UNKNOWN,
	TOKEN_END_OF_FILE, // Special token for end of file
};
struct Token {
	TokenType type;
	std::string value;
	int line;
	int column;
	Token() : type(TOKEN_UNKNOWN), value(""), line(-1), column(-1) {}
	Token(TokenType type, const std::string& value, int line, int column)
		: type(type), value(value), line(line), column(column) {}
	
	std::string toString() const {
		return "Token(" + std::to_string(type) + ", \"" + value + "\", " + std::to_string(line) + ", " + std::to_string(column) + ")";
	}
	// Utility for printing tokens
	static std::string tokenTypeToString(const TokenType& type) {
		switch (type) {
			case TOKEN_KEYWORD: return "Keyword";
			case TOKEN_TYPE: return "Type";
			case TOKEN_NUMBER: return "Number";
			case TOKEN_STRING: return "String";
			case TOKEN_BOOLEAN: return "Boolean";
			case TOKEN_OPERATOR: return "Operator";
			case TOKEN_COMMENT: return "Comment";
			case TOKEN_WHITESPACE: return "Whitespace";
			case TOKEN_UNKNOWN: return "Unknown";
			case TOKEN_END_OF_FILE: return "End of File";
			default: return "Invalid";
		}
	}
};