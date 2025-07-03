#include "ActionPrint.h"

ActionPrint::ActionPrint() : Action("Print", DataTypes::dataTypeVoid, {Parameter("text",DataTypes::dataTypeString)}, "Prints text to console",
									CATEGORY_MISC | CATEGORY_DEBUG) {
}

std::shared_ptr<Data> ActionPrint::execute(std::vector<std::shared_ptr<Data>>& parameters) {
	std::cout << parameters[0]->getData<std::string>();
	return Data::EMPTY;
}
