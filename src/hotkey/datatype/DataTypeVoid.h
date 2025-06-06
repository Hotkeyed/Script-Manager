#include "DataType.h"
#include <any>
class DataTypeVoid : public DataTypeImpl<std::any> {
public:
	DataTypeVoid() : DataTypeImpl(0) {};
	constexpr DataTypes getType() const override { return DataTypes::VOID_DATA_TYPE; }
	const std::any getDefaultValue() const override { return 0; };

	const bool isValid(const std::string& text) const override {
		return true;
	}
};