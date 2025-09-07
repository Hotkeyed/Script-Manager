#pragma once
#include "../ASTParser.h"
class PrimaryParser : public ASTParser {
public:
    int precedence() const override { return 100; }
    std::optional<std::shared_ptr<ASTNode>> parse(
        TokenStream& tokens,
        std::shared_ptr<ASTNode> /*left*/
    ) const override {
        const Token& t = tokens.peek();
        if (!t) return std::nullopt;

        // Fake logic: if token is number or identifier
        if (!t.value.empty() && (std::isdigit(t.value[0]) || std::isalpha(t.value[0]))) {
            tokens.get();
            return std::make_shared<ASTNode>(t,
                                             std::isdigit(t.value[0]) ? "Number" : "Identifier");
        }
        return std::nullopt;
    }
};