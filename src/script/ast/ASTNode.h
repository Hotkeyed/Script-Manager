#pragma once
struct ASTNode {
    Token token;
    std::vector<std::unique_ptr<ASTNode>> children;
    ASTNode(Token t) : token(std::move(t)) {}
};