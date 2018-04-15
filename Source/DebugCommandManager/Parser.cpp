#include "Parser.h"

void Parser::lTrim(std::string& s) 
{
	s.erase(s.begin(), std::find_if(s.begin(), 
		s.end(), 
		[](char ch) 
		{
			return !std::isspace(ch);
		}));
}

void Parser::rTrim(std::string& s) 
{
	s.erase(std::find_if(s.rbegin(), 
		s.rend(), 
		[](char ch) 
		{
			return !std::isspace(ch);
		}).base(), s.end());
}

void Parser::Trim(std::string& s) 
{
	lTrim(s);
	rTrim(s);
}

std::vector<std::string> Parser::Split(const std::string& input, const std::string& regex)
{
	std::regex re(regex);
	std::sregex_token_iterator first{ input.begin(), input.end(), re, -1 };
	std::sregex_token_iterator last;

	return { first, last };
}