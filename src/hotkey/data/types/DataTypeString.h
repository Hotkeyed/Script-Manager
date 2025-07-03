#pragma once
#include <string>
#include <Util.h>
#include "../DataType.h"
class DataTypeString : public DataType<std::string> {
public:
	virtual constexpr DataTypesEnum getType() const override {
		return DataTypesEnum::STRING_DATA_TYPE;
	}
	virtual constexpr std::string getTypeName() const override {
		return "string";
	}
	virtual constexpr bool isValid(const std::string& value) const override {
		return true;
	}
	virtual constexpr std::string getDefaultValue() const override {
		return "";
	}
};

