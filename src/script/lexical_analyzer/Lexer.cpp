#include "Lexer.h"

void Lexer::advance() {
	if (pos < source.size()) {
		pos++;
		if (source[pos] == '\n') {
			line++;
			column = 0;
		} else {
			column++;
		}
	}
	
}

void Lexer::skipWhitespace() {
	while (pos < source.size() && std::isspace(source[pos])) {
		advance();
	}
}
Token Lexer::getNextToken() {
	skipWhitespace();
	if (pos >= source.size()) {
		return Token(TokenParserEndOfFile(), "", line, column);
	}
	for (std::shared_ptr<const TokenParser> parser : TokenParsers::tokens) {
		const size_t originalPos = pos;
		size_t newPos = pos;
		std::optional<std::string> value = parser->parse(source, newPos);
		if (value) {
			Token t = Token(*parser, *value, line, column);
			for (size_t i = 0; i < newPos - originalPos;i++) {
				advance();
			}
			return t;
		}
	}
	//move on to the next character if no parser matched to prevent infinite loop
	advance();
	return Token(TokenParserUnknown(), "", line, column);
}

std::vector<Token> Lexer::tokenize() {
	std::vector<Token> tokens;
	while (Token token = getNextToken()) {
		tokens.push_back(token);
	}

	return tokens;
}
