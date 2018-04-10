#pragma once

#include<fstream>
#include<iostream>
#include<map>
#include<string>
#include<sstream>


class LogCategory {

private:

	std::map<std::string, std::string> params;

	bool IfElementExists(std::string value);

public:
	void addNewParam(std::pair < std::string, std::string>);
	std::string getValue(std::string configValue);
};


/*
---------------------------------------------
*/

class ConfigManager {

private:

	std::ifstream inFile;
	std::map<std::string, LogCategory> logCategories;

	ConfigManager() {}
	void readInputFile(std::string fileName);
	void createCategories();
	void createParameter(std::string categoryName, std::string line);
	bool IfCategoryExists(std::string keyValue);

public:

	static ConfigManager* create(std::string fileName);
	LogCategory& getCategory(std::string categoryName);

};