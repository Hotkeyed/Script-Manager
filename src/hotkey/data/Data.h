#pragma once
#include <any>
#include "DataTypes.h"
#include "DataType.h"
#include <stdexcept>
struct Data {
	const IDataType& type;
	std::any value;
	Data(const IDataType& type) : type(type) {
		for (std::shared_ptr<IDataType> t : DataTypes::dataTypes) {
			if (type.getType() == t->getType()) {
				this->value = getDefaultValue(*t);
				break;
			}
		}
	}
	Data(const IDataType& type, std::any value) : type(type), value(value) {}

	template<typename T>
	T getData() const {
		if (!isDataTypeValid<T>()) {
			throw std::runtime_error("Invalid data type conversion");
		}
		return std::any_cast<T>(value);
	}
	template<typename T>
	constexpr bool isDataTypeValid() const {
		switch (type.getType()) {
			case DataTypesEnum::INTEGER_DATA_TYPE:
				return std::is_same_v<T, long long int>;
			case DataTypesEnum::FLOAT_DATA_TYPE:
				return std::is_same_v<T, float>;
			case DataTypesEnum::STRING_DATA_TYPE:
				return std::is_same_v<T, std::string>;
			case DataTypesEnum::BOOLEAN_DATA_TYPE:
				return std::is_same_v<T, bool>;
			case DataTypesEnum::VOID_DATA_TYPE:
				return std::is_same_v<T, void>;
			default:
				return false;
		}
	}
	static constexpr std::any getDefaultValue(const IDataType& type) {
		switch (type.getType()) {
			case DataTypesEnum::INTEGER_DATA_TYPE:
				return dynamic_cast<const DataTypeInteger&>(type).getDefaultValue();
			case DataTypesEnum::FLOAT_DATA_TYPE:
				return dynamic_cast<const DataTypeFloat&>(type).getDefaultValue();
			case DataTypesEnum::STRING_DATA_TYPE:
				return dynamic_cast<const DataTypeString&>(type).getDefaultValue();
			case DataTypesEnum::BOOLEAN_DATA_TYPE:
				return dynamic_cast<const DataTypeBoolean&>(type).getDefaultValue();
			case DataTypesEnum::VOID_DATA_TYPE:
				return std::any{}; // Default value for void type
			default:
				throw std::runtime_error("Unknown data type");
		}
	}

	//Helper to create an empty Data object
	//Use when returning on a void type
	static inline const std::shared_ptr<Data> EMPTY = std::make_shared<Data>(DataTypes::dataTypeVoid);
};
