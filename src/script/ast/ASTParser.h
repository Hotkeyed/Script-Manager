#pragma once
#include <optional>
#include <memory>
#include <set>
#include <vector>
#include "ASTNode.h"
#include "../lexical_analyzer/token/Token.h"
#include "TokenStream.h"

class ASTParser {
public:
    virtual ~ASTParser() = default;
    virtual int precedence() const = 0;
    virtual bool rightAssociative() const { return false; }
    virtual std::optional<std::shared_ptr<ASTNode>> parse(
        TokenStream& tokens,
        std::shared_ptr<ASTNode> left
    ) const = 0;
};
struct CustomASTParserComparator {
    bool operator()(const std::shared_ptr<ASTParser>& a,
                    const std::shared_ptr<ASTParser>& b) const {
        if (a->precedence() != b->precedence())
            return a->precedence() > b->precedence();
        return a.get() < b.get();
    }
};