#pragma once
#include <string>
#include <map>

class Resource
{
public:
	Resource(const std::string& id, const std::string& fullName);
	Resource(const std::string& id, const std::string& fullName, const std::multimap<std::string,std::string>& settings);
	virtual ~Resource() {}

	void IncRefCounter();
	void DecRefCounter();
	unsigned int GetRefCounter() const;

	virtual void Load() = 0;
	virtual void Unload() = 0;

protected:
	std::string _fullName;

private:
	unsigned int _refCounter;
	std::string _ID;
	std::multimap<std::string, std::string> _settings;
};
