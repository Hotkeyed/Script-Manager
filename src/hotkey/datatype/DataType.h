#pragma once
#include <string>
//Alot of these are redefined elsewhere so we use a different name here with the _DATA_TYPE suffix
enum DataTypes {
	VOID_DATA_TYPE,
	//represented as long long int
	INTEGER_DATA_TYPE,
	//represented as double
	FLOAT_DATA_TYPE,
	//represented as std::string
	STRING_DATA_TYPE
};
template <typename T>
class DataTypeImpl;
//Below class is needed to use various datatypes in a vector, acts like a wildcard
struct DataType { 
	virtual constexpr DataTypes getType() const = 0;
	template<typename T>
	const T* getData() const {
		return static_cast<const DataTypeImpl<T>*>(this);
	}
};
template <typename T>
class DataTypeImpl : public DataType {	
public:
	T value;
	DataTypeImpl(const T& value) : value(value) {};
	virtual const T getDefaultValue() const = 0;
	virtual const bool isValid(const std::string& text) const = 0;
};
