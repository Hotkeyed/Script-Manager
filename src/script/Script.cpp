#include "Script.h"


Script::Script(const std::string& filename) : filename(filename) {
	std::ifstream file(filename);
	std::string line;
	while (std::getline(file, line)) {
		//ignore lines that start with "//" because that signifies a comment
		if (!line.starts_with("//")) {
			script += line + "\n";
		}
	}
}
