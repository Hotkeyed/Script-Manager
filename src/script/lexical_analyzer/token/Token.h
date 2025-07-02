#pragma once
#include "TokenParser.h"
#include "parsers/TokenParserUnkown.h"
#include <string>
struct Token {
	const TokenParser& parser;
	std::string value;
	int line;
	int column;
	Token() : Token(TokenParserUnknown(), "", -1, -1) {}
	Token(const TokenParser& parser, const std::string& value, int line, int column)
		: parser(parser), value(value), line(line), column(column) {}
	operator bool() const { return parser.type() != "End Of File"; }
};