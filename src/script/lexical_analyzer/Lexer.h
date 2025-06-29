#pragma once
#include "Token.h"
#include <string>
#include <unordered_set>
#include <vector>
class Lexer {
private:
    std::string source;
    size_t pos = 0,line = 0, column = 0;
    char current;
    static inline const std::unordered_set<std::string> keywords{
            "if", "else", "while", "return", "true", "false"
    };

    static inline  const std::unordered_set<std::string> types{
        "int", "float", "bool", "string"
    };

    static inline const std::unordered_set<char> operators{
		'+', '-', '*', '/', '=', '!','%', '&', '|', '<', '>', '^'
    };

    static inline const std::unordered_set<char> symbols{
        '(', ')', '{', '}', ';', ':', ','
    };
public:
	Lexer(const std::string& source) : source(source), pos(0), line(0), column(0), current(source.empty() ? '\0' : source[0]) {}
    void advance();
	void skipWhitespace();
    Token getNextToken();
	std::vector<Token> tokenize();
	Token readIdentifierOrKeyword();
	Token readNumber();
	Token readString();
	Token readOperator();
	Token readSymbol();
	Token readComment();

    char peek() const { return pos + 1 < source.size() ? source[pos + 1] : '\0'; }
    size_t getPosition() const { return pos; }
	void setPosition(size_t newPos) { pos = newPos; current = (pos < source.size()) ? source[pos] : '\0'; }
};

