#pragma once
#include "TokenParser.h"
#include "parsers/TokenParserUnkown.h"
#include "parsers/TokenParserEndOfFile.h"
#include "parsers/TokenParserString.h"
#include "parsers/TokenParserComment.h"
#include "parsers/TokenParserKeyword.h"
#include "parsers/TokenParserIdentifier.h"
#include "parsers/TokenParserOperator.h"
#include "parsers/TokenParserType.h"
#include "parsers/TokenParserSymbol.h"
#include "parsers/TokenParserNumber.h"
#include "parsers/TokenParserHotkey.h"
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