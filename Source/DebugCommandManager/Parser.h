#pragma once
#include <cctype>
#include <regex>

class Parser
{
	void lTrim(std::string& s);
	void rTrim(std::string& s);

public:

	void Trim(std::string& s);
	std::vector<std::string> Split(const std::string& input, const std::string& regex);
};

