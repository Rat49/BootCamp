#include "ConfigManager.h"


bool LogCategory::IfElementExists(std::string keyValue) {

	if (params.find(keyValue) != params.end()) {
		return true;
	}

	return false;
}

std::string LogCategory::getValue(std::string keyValue) {


	if (IfElementExists(keyValue)) {
		std::cout << params[keyValue] << std::endl;
		system("PAUSE");

		return params[keyValue];
	}


	std::cerr << "No key value" << std::endl;
	system("PAUSE");
	exit(1);
}

void LogCategory::addNewParam(std::pair <std::string, std::string> param) {

	params.insert(param);
}

/*
----------------------------------------------------------------------------
*/

void ConfigManager::readInputFile(std::string file_name) {

	in_file.open(file_name);

	if (in_file.is_open()) {
		createCategories();
		in_file.close();
	}
	else {
		std::cerr << "Cannot open file" << std::endl;
		system("PAUSE");
		exit(1);
	}

}

void ConfigManager::createCategories() {

	std::string line;
	std::string currentCategory = "";
	std::string previousCategory;

	while (!in_file.eof()) {

		std::getline(in_file, line);

		if (line[0] == '[') {
			std::ostringstream oss;

			for (int i = 1; i < line.size() - 1, line[i] != ']'; ++i) {
				oss << line[i];
			}

			//previousCategory = currentCategory;
			currentCategory = oss.str();

			LogCategory lc;
			logCategories.insert(std::pair<std::string, LogCategory>(currentCategory, lc));

		}
		
		if (line[0] != '[' || !isspace(line[0])) {
			std::pair<std::string, std::string> p = createParameter(line);
			logCategories[currentCategory].addNewParam(p);
		}
		
	}

}

std::pair<std::string, std::string>& ConfigManager::createParameter(std::string line) {

	std::pair<std::string, std::string> p;

	std::string key;
	std::string value;

	std::istringstream iss(line);

	for (int i = 0; i<3; ++i) {
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

bool ConfigManager::IfCategoryExists(std::string keyValue) {

	if (logCategories.find(keyValue) != logCategories.end()) {
		return true;
	}

	return false;
}

LogCategory& ConfigManager::getCategory(std::string categoryName) {

	if (IfCategoryExists(categoryName)) {

		return logCategories[categoryName];
	}


	std::cerr << "No category value" << std::endl;
	system("PAUSE");
	exit(1);

}