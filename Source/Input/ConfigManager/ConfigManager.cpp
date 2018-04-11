#include "ConfigManager.h"


bool LogCategory::IfElementExists(const std::string& keyValue) const {

	if (params.find(keyValue) != params.end()) {
		return true;
	}

	return false;
}

std::string LogCategory::GetValue(std::string keyValue) {


	if (IfElementExists(keyValue)) {

		return params[keyValue];
	}

	std::cerr << "Key value not found" << std::endl;
	system("PAUSE");

	return "invalid";
}

void LogCategory::AddNewParam(std::pair <std::string, std::string> param) {

	params.insert(param);
}

/*
----------------------------------------------------------------------------
*/

ConfigManager* ConfigManager::Create(std::string fileName) {
	ConfigManager* cm = new ConfigManager();
	cm->ReadInputFile(fileName);

	return cm;
}

void ConfigManager::ReadInputFile(std::string fileName) {

	inFile.open(fileName);

	if (inFile.is_open()) {
		std::cerr << "File opened" << std::endl;
		CreateCategories();
		inFile.close();
		std::cerr << "File closed" << std::endl;
	}
	else {
		std::cerr << "Cannot open file" << std::endl;
		system("PAUSE");
	}

}

void ConfigManager::CreateCategories() {

	std::string line;
	std::string currentCategory;

	while (!inFile.eof()) {

		std::getline(inFile, line);

		if (line[0] == '[') {
			std::ostringstream oss;

			for (int i = 1; i < line.size() - 1; ++i) {
				if (line[i] != ']')
					oss << line[i];
			}
			currentCategory = oss.str();

			logCategories[currentCategory] = LogCategory();
		}

		if (line[0] != '[') {
			CreateParameter(currentCategory, line);
		}

	}

	logCategories["Invalid_category"] = LogCategory();
}

void ConfigManager::CreateParameter(std::string categoryName, std::string line) {

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

		p.first = key;
		p.second = value;

		logCategories[categoryName].AddNewParam(p);
	}
}

bool ConfigManager::IfCategoryExists(const std::string &keyValue) const {

	if (logCategories.find(keyValue) != logCategories.end()) {
		return true;
	}

	return false;
}

LogCategory& ConfigManager::GetCategory(std::string categoryName) {

	if (IfCategoryExists(categoryName)) {

		return logCategories[categoryName];
	}

	std::cerr << "Category value not found" << std::endl;
	system("PAUSE");

	return logCategories["Invalid_category"];
}