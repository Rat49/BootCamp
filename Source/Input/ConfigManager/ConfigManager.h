#pragma once

#include<fstream>
#include<iostream>
#include<map>
#include<string>
#include<sstream>


class LogCategory {

private:

	std::map<std::string, std::string> params;

	bool IfElementExists(const std::string& keyValue) const;

public:
	void AddNewParam(std::pair < std::string, std::string>);
	std::string GetValue(std::string configValue);
};


/*
---------------------------------------------
*/

class ConfigManager final {

private:

	std::ifstream inFile;
	std::map<std::string, LogCategory> logCategories;

	ConfigManager() {}
	void ReadInputFile(std::string fileName);
	void CreateCategories();
	void CreateParameter(std::string categoryName, std::string line);
	bool IfCategoryExists(const std::string &keyValue) const;

public:

	static ConfigManager* Create(std::string fileName);
	LogCategory& GetCategory(std::string categoryName);

};
