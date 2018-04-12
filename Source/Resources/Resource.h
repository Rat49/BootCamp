#pragma once
#include <string>
#include <vector>

class Resource
{
public:
	
	Resource(const std::string& id, const std::string& fullName);
	Resource(const std::string& id, const std::string& fullName, std::vector<float>* settings);
	void IncRefCounter();
	void DecRefCounter();
	unsigned int GetRefCounter() const;
	virtual void Load() = 0;
	virtual void Unload() = 0;
	virtual ~Resource() = 0 {};

	std::string _fullName;

private:
	unsigned int _refCounter;	
	std::string _ID;
	std::vector<float>* _settings;
};
