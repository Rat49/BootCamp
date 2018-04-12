#pragma once

#include<fstream>
#include<iostream>
#include<map>
#include<string>
#include<sstream>


class LogCategory {

private:

	std::map<const std::string, const std::string> params;

	bool IfElementExists(const std::string& keyValue) const;

public:
	void AddNewParam(std::pair <std::string, std::string>&);
	std::string GetValue(const std::string& configValue);
};


/*
---------------------------------------------
*/

class ConfigManager final {

private:

	std::ifstream inFile;
	std::map<std::string, LogCategory> logCategories;

	ConfigManager() {}
	void ReadInputFile(const std::string& fileName);
	void CreateCategories();
	void CreateParameter(const std::string& categoryName, const std::string& line);
	bool IfCategoryExists(const std::string &keyValue) const;

public:

	static ConfigManager* Create(const std::string& fileName);
	LogCategory& GetCategory(const std::string& categoryName);

};
