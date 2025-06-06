#pragma once
#include "DataType.h"
#include <Util.h>
class DataTypeInteger : public DataTypeImpl<long long int> {
public:
	DataTypeInteger(const std::string& text) : DataTypeImpl(std::stoll(text)) {};
	DataTypeInteger(const long long int number) : DataTypeImpl(number) {};
	constexpr DataTypes getType() const override { return DataTypes::INTEGER_DATA_TYPE; }
	const long long int getDefaultValue() const override { return 0; };
	const bool isValid(const std::string& text)  const override { return Util::isNumber(text); };
};

