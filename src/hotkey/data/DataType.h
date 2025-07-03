#pragma once
#include <string>
#include <memory>
//Alot of these are redefined elsewhere so we use a different name here with the _DATA_TYPE suffix
enum DataTypesEnum {
	VOID_DATA_TYPE,
	//represented as bool
	BOOLEAN_DATA_TYPE,
	//represented as long long int
	INTEGER_DATA_TYPE,
	//represented as double
	FLOAT_DATA_TYPE,
	//represented as std::string
	STRING_DATA_TYPE,
};
//interface so we can use wild card templates
//this should be used when interacting with the data type system

struct IDataType {
	virtual constexpr DataTypesEnum getType() const = 0;
	virtual constexpr std::string getTypeName() const = 0;
	virtual constexpr bool isValid(const std::string& value) const = 0;
};

template<typename T>
struct DataType : public IDataType { 
	virtual constexpr T getDefaultValue() const = 0;
};

struct CustomDataTypeComparator {
	bool operator()(const std::shared_ptr<const IDataType>& lhs, const std::shared_ptr<const IDataType>& rhs) const {
		return lhs->getType() > rhs->getType();
	}
};