#pragma once
#include "TokenParser.h"
#include "token_parsers/TokenParserUnkown.h"
#include "token_parsers/TokenParserEndOfFile.h"
#include "token_parsers/TokenParserString.h"
#include "token_parsers/TokenParserComment.h"
#include "token_parsers/TokenParserKeyword.h"
#include "token_parsers/TokenParserIdentifier.h"
#include "token_parsers/TokenParserOperator.h"
#include "token_parsers/TokenParserType.h"
#include "token_parsers/TokenParserSymbol.h"
#include "token_parsers/TokenParserNumber.h"
#include "token_parsers/TokenParserHotkey.h"
#include <set>
#include <memory>
namespace TokenParsers {
	const std::set<std::shared_ptr<const TokenParser>, CustomTokenParserComparator> tokens = {
		std::make_shared<TokenParserUnknown>(),
		std::make_shared<TokenParserEndOfFile>(),
		std::make_shared<TokenParserComment>(),
		std::make_shared<TokenParserString>(),
		std::make_shared<TokenParserKeyword>(),
		std::make_shared<TokenParserIdentifier>(),
		std::make_shared<TokenParserOperator>(),
		std::make_shared<TokenParserType>(),
		std::make_shared<TokenParserSymbol>(),
		std::make_shared<TokenParserNumber>(),
		std::make_shared<TokenParserHotkey>(),
	};
}