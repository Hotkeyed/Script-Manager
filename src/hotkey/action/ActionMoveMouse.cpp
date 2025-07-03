#include "ActionMoveMouse.h"

ActionMoveMouse::ActionMoveMouse() : Action("MoveMouse", DataTypes::dataTypeVoid, {Parameter("x",Data(DataTypes::dataTypeInteger)),
											                                 Parameter("y",Data(DataTypes::dataTypeInteger))}, "Moves mouse cursor to (x,y)",CATEGORY_MOUSE) {

}

std::shared_ptr<Data> ActionMoveMouse::execute(std::vector<std::shared_ptr<Data>>& parameters) {
	int x = parameters[0]->getData<long long int>();
	int y = parameters[1]->getData<long long int>();
	SetCursorPos(x, y);
	return Data::EMPTY;
}

