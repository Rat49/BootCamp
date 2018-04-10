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

ConfigManager* ConfigManager::create(std::string fileName) {
	ConfigManager* cm = new ConfigManager();
	cm->readInputFile(fileName);

	return cm;
}

void ConfigManager::readInputFile(std::string fileName) {

	inFile.open(fileName);

	if (inFile.is_open()) {
		createCategories();
		inFile.close();
	}
	else {
		std::cerr << "Cannot open file" << std::endl;
		system("PAUSE");
		exit(1);
	}

}

void ConfigManager::createCategories() {

	std::string line;
	std::string currentCategory;

	while (!inFile.eof()) {

		std::getline(inFile, line);

		if (line[0] == '[') {
			std::ostringstream oss;

			for (int i = 1; i < line.size() - 1, line[i] != ']'; ++i) {
				oss << line[i];
			}

			currentCategory = oss.str();

			logCategories.insert(std::pair<std::string, LogCategory>(currentCategory, LogCategory()));
		}
		
		if (line[0] != '[') {
			createParameter(currentCategory, line);
		}
		
	}

}

void ConfigManager::createParameter(std::string categoryName, std::string line) {

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

	if (!key.empty() && !value.empty()) {

		std::pair<std::string, std::string> p;

		p.first = key.c_str();
		p.second = value.c_str();

		logCategories[categoryName].addNewParam(p);
	}
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