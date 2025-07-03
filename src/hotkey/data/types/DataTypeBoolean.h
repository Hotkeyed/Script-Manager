#pragma once
#include <Util.h>
#include "../DataType.h"
class DataTypeBoolean : public DataType<bool> {
public:
	virtual constexpr DataTypesEnum getType() const override {
		return DataTypesEnum::BOOLEAN_DATA_TYPE;
	}
	virtual constexpr std::string getTypeName() const override {
		return "int";
	}
	virtual constexpr bool isValid(const std::string& value) const override {
		return false;
	}
	virtual constexpr bool getDefaultValue() const override {
		return false;
	}
};

