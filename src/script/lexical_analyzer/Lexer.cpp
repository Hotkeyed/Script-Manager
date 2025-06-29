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
		current = pos < source.size() ? source[pos] : '\0';
	}
	
}

void Lexer::skipWhitespace() {
	while (pos < source.size() && isspace(source[pos])) {
		advance();
	}
}

Token Lexer::getNextToken() {
	skipWhitespace();
	if (pos >= source.size()) {
		return Token(TokenType::TOKEN_END_OF_FILE, "", line, column);
	}


	return ;
}

std::vector<Token> Lexer::tokenize() {
	std::vector<Token> tokens;
	Token token;
	do {
		token = getNextToken();
		tokens.push_back(token);
	} while (token.type != TokenType::TOKEN_END_OF_FILE);
	return tokens;
}
