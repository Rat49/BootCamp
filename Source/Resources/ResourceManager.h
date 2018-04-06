#pragma once
#include "Audio.h"
#include "Picture.h"
#include "Resource.h"
#include <string>
#include <map>
class ResourceManager
{
public:
	ResourceManager();

	Resource* GetGeneralResource(std::string key);
	template <typename T> 
	T* GetResource(std::string key)
	{
		Resource* resource = ResourceManager::GetGeneralResource(key);
		if (resource == nullptr)
			return nullptr;
		
		return dynamic_cast<T*>(resource);
	}

	void ReleaseResource(std::string key);
	void ReleaseMemory();
	~ResourceManager();

private:
	std::map<std::string, Resource*> resources;
	
};

