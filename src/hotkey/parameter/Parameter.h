#pragma once
#include <string>
#include <memory>
#include "../data/Data.h"
#include "../data/DataTypes.h"
//parameter to be held in a function or action
struct Parameter {
	const std::string name;
	const std::string description;
	const bool optional = false;
	//stores data type and default value
	const Data dataType;

	//this constructor should be used if parameter is not optional
	Parameter(
		const std::string& name,
		const Data& dataType = Data(DataTypes::dataTypeVoid),
		const std::string& description = "",
		const bool optional = false
		) : name(name), dataType(dataType), description(description), optional(optional) {
	};
};
