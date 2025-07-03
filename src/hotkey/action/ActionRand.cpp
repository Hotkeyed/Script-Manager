#include "ActionRand.h"

ActionRand::ActionRand() : Action("RandInt", DataTypes::dataTypeInteger, {
	Parameter("min",Data(DataTypes::dataTypeInteger,0),"Min Value",true),
	Parameter("max",Data(DataTypes::dataTypeInteger,100), "Max Value", true)
								  }, "Generates a random integer between [min, max]", CATEGORY_MATH) {
}

std::shared_ptr<Data> ActionRand::execute(std::vector<std::shared_ptr<Data>>& parameters) {
	int min = parameters[0]->getData<long long int>();
	int max = parameters[1]->getData<long long int>();

	std::random_device dev;
	std::mt19937 rng(dev());
	// distribution in range [min, max]
	std::uniform_int_distribution<std::mt19937::result_type> distribution(min, max);

	return std::make_shared<Data>(DataTypes::dataTypeInteger,distribution(rng));
}
