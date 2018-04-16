#include "ConfigManager.h"


bool LogCategory::IfElementExists(const std::string& keyValue) const {

	if (params.find(keyValue) != params.end()) {
		return true;
	}

	return false;
}

std::string LogCategory::GetValue(const std::string& keyValue) {


	if (IfElementExists(keyValue)) {

		return params[keyValue];
	}

	std::cerr << "Key value not found" << std::endl;

	return "invalid";
}

void LogCategory::AddNewParam(std::pair <std::string, std::string>& param) {

	params.insert(param);
}

std::map<const std::string, const std::string> LogCategory::getParams()
{
	return params;
}

/*
----------------------------------------------------------------------------
*/

ConfigManager* ConfigManager::Create(const std::string& fileName) {
	ConfigManager* cm = new ConfigManager();
	cm->ReadInputFile(fileName);

	return cm;
}

void ConfigManager::ReadInputFile(const std::string& fileName) {

	inFile.open(fileName);

	if (inFile.is_open()) {
		std::cerr << "File opened" << std::endl;
		CreateCategories();
		inFile.close();
		std::cerr << "File closed" << std::endl;
	}
	else {
		std::cerr << "Cannot open file" << std::endl;
	}

}

void ConfigManager::CreateCategories() {

	std::string line;
	std::string currentCategory = "";

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
		else {
			CreateParameter(currentCategory, line);
		}

	}

	logCategories["Invalid_category"] = LogCategory();
}

void ConfigManager::CreateParameter(const std::string& categoryName, const std::string& line) {

	std::string key;
	std::string value;
	std::string equalSign;

	std::istringstream iss(line);

	iss >> key;
	iss >> equalSign;
	iss >> value;

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

LogCategory& ConfigManager::GetCategory(const std::string& categoryName) {

	if (IfCategoryExists(categoryName)) {

		return logCategories[categoryName];
	}

	std::cerr << "Category value not found" << std::endl;

	return logCategories["Invalid_category"];
}
