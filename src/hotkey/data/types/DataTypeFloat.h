#pragma once
#include <Util.h>
#include "../DataType.h"
class DataTypeFloat : public DataType<double> {
public:
	virtual constexpr DataTypesEnum getType() const override {
		return DataTypesEnum::FLOAT_DATA_TYPE;
	}
	virtual constexpr std::string getTypeName() const override {
		return "float";
	}
	virtual constexpr bool isValid(const std::string& value) const override {
		return false;
	}
	virtual constexpr double getDefaultValue() const override {
		return 0.0;
	}
};

