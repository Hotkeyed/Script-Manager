#include <iostream>
#include <device/DeviceManager.h>
#include <windows/Interceptor.h>
#include "script/Script.h"
#include "engine/ScriptEngine.h"
#include "hotkey/parameter/Parameter.h"
#include "script/lexical_analyzer/Lexer.h"
int main() { 
    DeviceManager::getInstance().populate();
    Mapping mapping(std::filesystem::current_path().generic_string() + "/mapping.mapping");
    DeviceManager::getInstance().setMapping(mapping);
    
    ScriptEngine engine;
    //Script testScript("testScript.htky");
    //engine.addScript(testScript);
    //engine.start();

	std::ifstream scriptFile("testScript.htky");
	std::string scriptContent((std::istreambuf_iterator<char>(scriptFile)), std::istreambuf_iterator<char>());
	Lexer lexer(scriptContent);
	std::vector<Token> tokens = lexer.tokenize();
    for (const auto& token : tokens) {
        std::cout << "Token " << token.parser.type() << " (" << token.line << ", " << token.column << "): " << token.value  << std::endl;
	}
    return 0;

}
