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
	LogCategory() {}
	void addNewParam(std::pair < std::string, std::string>);
	std::string getValue(std::string configValue);
};


/*
---------------------------------------------
*/

class ConfigManager {

private:

	std::ifstream in_file;
	std::map<std::string, LogCategory> logCategories;

	void createCategories();
	std::pair<std::string, std::string>& createParameter(std::string line);
	bool IfCategoryExists(std::string keyValue);

public:

	void readInputFile(std::string file_name);
	LogCategory& getCategory(std::string categoryName);

};