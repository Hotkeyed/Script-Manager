#pragma once
#include <Util.h>
#include "../DataType.h"
class DataTypeInteger : public DataType<long long int> {
public:
	virtual constexpr DataTypesEnum getType() const override {
		return DataTypesEnum::INTEGER_DATA_TYPE;
	}
	virtual constexpr std::string getTypeName() const override {
		return "int";
	}
	virtual constexpr bool isValid(const std::string& value) const override {
		return false;
	}
	virtual constexpr long long int getDefaultValue() const override {
		return 0;
	}
};

