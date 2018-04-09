#pragma once

#include<fstream>
#include<iostream>
#include<map>
#include<string>
#include<sstream>


class LogCategory {

private:

	std::map<const char*, const char*> params;


public:
	LogCategory() {}
	const char* getValue(const char* configValue);
};


/*
---------------------------------------------
*/

class ConfigManager {

private:

	std::ifstream in_file;
	std::map<const char*, LogCategory> logCategories;

public:

	void readInputFile(std::string file_name);
	void createCategories();
	std::pair<const char*, const char*>& createParameter(std::string line);
	LogCategory& getCategory(const char* categoryName);

};