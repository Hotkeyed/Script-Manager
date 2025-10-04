#pragma once
//don't use windows.h definition of std::min
#define NOMINMAX
#include <iostream>
#include <string>
#include <stack>
#include <fstream>
#include <memory>
#include <algorithm>
#include <keyboard/DeviceKeys.h>
#include "../hotkey/Hotkey.h"
#include "../hotkey/Action.h"
#include "../hotkey/CallableAction.h"
#include "../hotkey/ActionManager.h"
#include <Util.h>
#include <utility>

//Characters/Strings that cannot be the start of functions and variables
class Script {
private:
	std::string script;
public:
	std::string filename;
	Script(const std::string& filename);
};

