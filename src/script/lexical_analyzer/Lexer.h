#pragma once
#include "token/Token.h"
#include "token/TokenParsers.h"
#include <string>
#include <unordered_set>
#include <vector>
class Lexer {
private:
    std::string source;
    size_t pos = 0,line = 0, column = 0;
public:
	Lexer(const std::string& source) : source(source), pos(0), line(0), column(0) {}
    void advance();
	void skipWhitespace();
    Token getNextToken();
	std::vector<Token> tokenize();
};

