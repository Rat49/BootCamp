#pragma once
#include "Audio.h"
#include "Picture.h"
#include "Resourse.h"
#include <string>
#include <map>
class ResourseManager
{
public:
	ResourseManager();

	Resourse* GetGeneralResourse(std::string key);
	template <typename T> 
	T* GetResourse(std::string key)
	{
		Resourse* resourse = ResourseManager::GetGeneralResourse(key);
		if (resourse == nullptr)
			return nullptr;
		
		return dynamic_cast<T*>(resourse);
	}

	void ReleaseResourse(std::string key);
	void ReleaseMemory();
	~ResourseManager();

private:
	std::map<std::string, Resourse*> resourses;
	
};

