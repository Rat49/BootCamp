#pragma once
#include <string>
#include <vector>

class Parser
{
public:
	void Trim(std::string& s);
	std::vector<std::string> Split(const std::string& input, const std::string& regex);
};
