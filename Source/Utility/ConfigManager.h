#pragma once

#include "Parser.h"
#include<fstream>
#include<iostream>
#include<map>
#include<string>
#include<sstream>

using Param = std::pair<const std::string, const std::string>;

class LogCategory
{
public:
	void AddNewParam(const Param& param);
	std::vector<Param> GetValues(const std::string& configValue) const;
	std::multimap<const std::string, const std::string> GetParams() const;
	size_t Size();

private:
	bool IfElementExists(const std::string& keyValue) const;

	std::multimap<const std::string, const std::string> _params;
};


class ConfigManager final
{
public:
	static ConfigManager* Create(const std::string& fileName);

	LogCategory& GetCategory(const std::string& categoryName);

private:
	Parser parser;
	std::ifstream inFile;
	std::map<std::string, LogCategory> logCategories;

	ConfigManager() {}
	void ReadInputFile(const std::string& fileName);
	void CreateCategories();
	void CreateParameter(const std::string& categoryName, const std::string& line);
	bool IfCategoryExists(const std::string &keyValue) const;
};
