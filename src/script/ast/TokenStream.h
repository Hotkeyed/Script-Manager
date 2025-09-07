#pragma once
#include <vector>
#include "../lexical_analyzer/token/Token.h"
class TokenStream {
    std::vector<Token> tokens;
    size_t pos = 0;
public:
    TokenStream(std::vector<Token> t) : tokens(std::move(t)) {}
    const Token& peek(size_t offset = 0) const {
        static Token eof;
        if (pos + offset >= tokens.size()) return eof;
        return tokens[pos + offset];
    }
    const Token& get() {
        static Token eof;
        if (pos >= tokens.size()) return eof;
        return tokens[pos++];
    }
    bool eof() const { return pos >= tokens.size(); }
};