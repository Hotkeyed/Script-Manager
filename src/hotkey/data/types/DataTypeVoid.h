#pragma once
#include <Util.h>
#include "../DataType.h"
class DataTypeVoid : public DataType<void> {
public:
	virtual constexpr DataTypesEnum getType() const override {
		return DataTypesEnum::VOID_DATA_TYPE;
	}
	virtual constexpr std::string getTypeName() const override {
		return "void";
	}
	virtual constexpr bool isValid(const std::string& value) const override {
		return true;
	}
	virtual constexpr void getDefaultValue() const override {}
};

