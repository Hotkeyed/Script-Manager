#pragma once
#include <Windows.h>
#include "../Action.h"
class ActionMoveMouse : public Action {
public:
	ActionMoveMouse();
	virtual std::shared_ptr<Data> execute(std::vector<std::shared_ptr<Data>>& parameters) override;
};

