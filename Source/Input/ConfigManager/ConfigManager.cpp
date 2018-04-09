#include "ConfigManager.h"


const char* LogCategory::getValue(const char* configValue) {

	//std::cout << params[configValue] << std::endl;
	//system("PAUSE");
	return params[configValue];
}

void LogCategory::addNewParam(std::pair < const char*, const char*> param) {

	params.insert(param);
}

/*
----------------------------------------------------------------------------
*/

void ConfigManager::readInputFile(std::string file_name) {

	in_file.exceptions(std::ifstream::failbit | std::ifstream::badbit);

	try {
		in_file.open(file_name);

		createCategories();

		in_file.close();
	}
	catch (const std::ifstream::failure&) {
		std::cerr << "Cannon open/read file!" << std::endl;
	}

}

void ConfigManager::createCategories() {

	std::string line = "";
	
	while (!in_file.eof()) {

		if (line == "") {
			std::getline(in_file, line);
		}
		if (line[0] == '[') {

			std::ostringstream oss;

			for (int i = 1; i < line.size() - 1, line[i] != ']'; ++i) {
				oss << line[i];
			}

			std::string categoryName = oss.str();

			//std::cout << categoryName << std::endl;
			//system("PAUSE");
			
			LogCategory lc;

			while (std::getline(in_file, line) && (line[0] != '[')) {

				std::pair<const char*, const char*> p = createParameter(line);
				lc.addNewParam(p);
				
			}

			logCategories.insert(std::pair<const char*, LogCategory>(categoryName.c_str(), lc));
		}
		
	}
}

std::pair<const char*, const char*>& ConfigManager::createParameter(std::string line) {

	std::pair<const char*, const char*> p;

	std::string key;
	std::string value;

	std::istringstream iss(line);

	for (int i=0; i<3; ++i){
		std::string substr;
		iss >> substr;

		if (i == 0)
			key = substr;
		if (i == 2)
			value = substr;
	}

	p.first = key.c_str();
	p.second = value.c_str();
	
	return p;
}

LogCategory& ConfigManager::getCategory(const char* categoryName) {
	
	return logCategories[categoryName];
}