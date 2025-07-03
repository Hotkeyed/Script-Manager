#pragma once
#include <iostream>
#include "../Action.h"
class ActionPrint : public Action{
public:
	ActionPrint();
	virtual std::shared_ptr<Data> execute(std::vector<std::shared_ptr<Data>>& parameters) override;
};

