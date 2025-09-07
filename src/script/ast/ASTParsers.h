#pragma once
#include <set>
#include <memory>
#include "ASTParser.h"
#include "ast_parsers/PrimaryParser.h"

namespace ASTParsers {
	const std::set<std::shared_ptr<ASTParser>, CustomASTParserComparator> parsers = {
		std::make_shared<PrimaryParser>(),
		
	};
}