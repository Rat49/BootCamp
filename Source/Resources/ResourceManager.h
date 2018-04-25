#pragma once
#include "AudioResource.h"
#include "ImageSequenceResource.h"
#include "PictureResource.h"
#include "Resource.h"
#include "TextureResource.h"
#include <cassert>
#include <map>
#include <string>

class ResourceManager final
{
public:
	ResourceManager(const std::map<std::string, std::multimap<const std::string, const std::string>>& resourceConfig);
	ResourceManager();

	template <typename T> 
	T* GetResource(const std::string& key)
	{
		Resource* resource = GetGeneralResource(key);

		assert(resource != nullptr && "Resource not found");

		T* specificResource = dynamic_cast<T*>(resource);
		assert(specificResource != nullptr && "Incorrect resource type");

		return specificResource;
	}

	void ReleaseResource(const std::string& key);
	void ReleaseAllResources();
	~ResourceManager();

private:
	std::map<std::string, Resource*> _resources;
	Resource * GetGeneralResource(const std::string& key);

};

