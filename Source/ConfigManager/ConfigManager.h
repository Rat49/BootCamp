#pragma once

#include "Parser.h"
#include<fstream>
#include<iostream>
#include<map>
#include<string>
#include<sstream>


class LogCategory {

private:

	std::multimap<const std::string, const std::string> params;

	bool IfElementExists(const std::string& keyValue) const;

public:
	void AddNewParam(const std::pair<std::string, std::string>& param);
	const std::vector<std::pair<const std::string, const std::string>>  GetValues(const std::string& configValue) const;
	std::multimap<const std::string, const std::string> getParams();
	int size();
};


/*
---------------------------------------------
*/

class ConfigManager final {

private:

	Parser parser;
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
