#pragma once

#include<fstream>
#include<iostream>
#include<map>
#include<string>
#include<sstream>


class LogCategory {

private:

	std::map<const char*, const char*> params;

	bool IfElementExists(const char* value);

public:
	LogCategory() {}
	void addNewParam(std::pair < const char*, const char*>);
	const char* getValue(const char* configValue);
};


/*
---------------------------------------------
*/

class ConfigManager {

private:

	std::ifstream in_file;
	std::map<const char*, LogCategory> logCategories;

	void createCategories();
	std::pair<const char*, const char*>& createParameter(std::string line);

public:

	void readInputFile(std::string file_name);
	LogCategory& getCategory(const char* categoryName);

};