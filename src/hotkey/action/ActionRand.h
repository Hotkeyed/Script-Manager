#pragma once
#include <iostream>
#include <random>
#include "../Action.h"
class ActionRand : public Action {
public:
	ActionRand();
	virtual std::shared_ptr<Data> execute(std::vector<std::shared_ptr<Data>>& parameters) override;
};

