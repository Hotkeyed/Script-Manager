#pragma once
#include <set>
#include <memory>
#include "ASTNode.h"
#include "ASTParser.h"
#include "ASTParsers.h"
#include "../lexical_analyzer/token/Token.h"
#include "TokenStream.h"

namespace Parser {
    std::shared_ptr<ASTNode> parseExpression(TokenStream& tokens, int minPrec = 0) {
        std::shared_ptr<ASTNode> left = nullptr;

        // prefix / primary
        for (auto& parser : ASTParsers::parsers) {
            if (auto node = parser->parse(tokens, nullptr)) {
                if (node)
                    left = *node;
                break;
            }
        }
        if (!left) return nullptr;

        while (true) {
            bool matched = false;
            for (auto& parser : ASTParsers::parsers) {
                if (parser->precedence() < minPrec) continue;
                if (auto node = parser->parse(tokens, left)) {
                    if (node)
                        left = *node;
                    matched = true;
                    break;
                }
            }
            if (!matched) break;
        }
        return left;
    }
}
