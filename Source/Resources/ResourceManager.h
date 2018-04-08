#pragma once
#include "AudioResource.h"
#include "PictureResource.h"
#include "Resource.h"
#include <cassert>
#include <map>
#include <string>

class ResourceManager final
{
public:
	ResourceManager();
	
	template <typename T> 
	T& GetResource(const std::string& key)
	{
		Resource* resource = GetGeneralResource(key);

		assert(resource != nullptr && "Resource not found");

		return dynamic_cast<T>(resource);
	}

	void ReleaseResource(const std::string& key);
	void ReleaseAllResources();
	~ResourceManager();

private:
	std::map<std::string, Resource*> resources;
	Resource * GetGeneralResource(const std::string& key);

};

