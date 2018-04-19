#include "ConfigManager.h"


bool LogCategory::IfElementExists(const std::string& keyValue) const {

	if (params.find(keyValue) != params.end()) {
		return true;
	}

	return false;
}

std::multimap<const std::string, const std::string>::const_iterator LogCategory::GetValue(const std::string& keyValue) {


	if (IfElementExists(keyValue)) {

		return params.find(keyValue);
	}

	std::cerr << "Key value not found" << std::endl;

	return params.cend();
}

void LogCategory::AddNewParam(const std::pair<std::string, std::string>& param) {

	params.insert(param);
}

std::multimap<const std::string, const std::string> LogCategory::getParams()
{
	return params;
}
int LogCategory::size()
{
	return params.size();
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

	if (line.empty())
	{
		return;
	}

	std::vector<std::string> keyAndArgs = parser.Split(line, "=");
	std::string key = keyAndArgs[0];
	parser.Trim(key);

	std::vector<std::string> args = parser.Split(keyAndArgs[1], ",");

	if (!key.empty() && !args.empty()) {

		for (auto arg : args)
		{
			parser.Trim(arg);
			logCategories[categoryName].AddNewParam(std::pair<std::string, std::string>(key, arg));
		}
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
