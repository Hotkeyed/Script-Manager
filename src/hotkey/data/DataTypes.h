#pragma once
#include "DataType.h"
#include "types/DataTypeFloat.h"
#include "types/DataTypeInteger.h"
#include "types/DataTypeString.h"
#include "types/DataTypeVoid.h"
#include "types/DataTypeBoolean.h"
#include <set>
#include <memory>

namespace DataTypes {
	static inline std::set<std::shared_ptr<IDataType>, CustomDataTypeComparator> dataTypes = {};
	template<typename T>
	static inline constexpr T add() {
		std::shared_ptr<T> d = std::make_shared<T>();
		dataTypes.insert(d);
		return *d;
	}

	static const inline DataTypeVoid dataTypeVoid = add<DataTypeVoid>();
	static const inline DataTypeBoolean dataTypeBoolean = add<DataTypeBoolean>();
	static const inline DataTypeInteger dataTypeInteger = add<DataTypeInteger>();
	static const inline DataTypeFloat dataTypeFloat = add<DataTypeFloat>();
	static const inline DataTypeString dataTypeString = add<DataTypeString>();
}