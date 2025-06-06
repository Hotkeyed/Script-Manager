#include "ActionMoveMouse.h"

ActionMoveMouse::ActionMoveMouse() : Action("MoveMouse", DataTypes::VOID_DATA_TYPE, {Parameter("x",DataTypes::INTEGER_DATA_TYPE),
											                                 Parameter("y",DataTypes::INTEGER_DATA_TYPE)}, "Moves mouse cursor to (x,y)",CATEGORY_MOUSE) {

}

std::shared_ptr<DataType> ActionMoveMouse::execute(std::vector<std::shared_ptr<DataType>>& parameters) {
	int x = parameters[0]->getData<DataTypeInteger>()->value;
	int y = parameters[1]->getData<DataTypeInteger>()->value;
	SetCursorPos(x, y);
	return std::make_shared<DataTypeVoid>(DataTypeVoid());
}

