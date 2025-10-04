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

        // --- prefix / primary ---
        for (auto& parser : ASTParsers::parsers) {
            auto optNode = parser->parse(tokens, nullptr);
            if (optNode.has_value()) {
                left = *optNode;   // extract shared_ptr<ASTNode>
                break;
            }
        }
        if (!left) return nullptr;

        // --- infix / binary loop ---
        while (true) {
            bool matched = false;
            for (auto& parser : ASTParsers::parsers) {
                if (parser->precedence() < minPrec) continue;

                auto optNode = parser->parse(tokens, left);
                if (optNode.has_value()) {
                    left = *optNode;  // update left side of expression
                    matched = true;
                    break;
                }
            }
            if (!matched) break;
        }

        return left;
    }
}
