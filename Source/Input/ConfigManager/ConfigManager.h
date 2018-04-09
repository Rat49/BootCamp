#pragma once
//#include<exception>
#include<fstream>
#include<iostream>
#include<map>
#include<regex>
#include<string>


class LogCategory {

private:

	std::map<const char*, const char*> params;


public:
	LogCategory(std::map<const char*, const char*> params){/*...*/}
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
	std::map<const char*, const char*>& createParameters(std::string categoryName);
	LogCategory& getCategory(const char* categoryName);

};