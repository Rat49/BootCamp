#include "stdafx.h"
#include "ResourseManager.h"
ResourseManager::ResourseManager()
{
	all_res.reserve(100);
	paths.emplace_back("/images/picture1.bmp");
	paths.emplace_back("/images/picture2.bmp");
	paths.emplace_back("/audio/piupiu.wav");

	extentToType = { { "bmp", Picture_type },
					 { "wav", Audio_type   } };

}
//
//void ResourseManager::addResourse(Resourse * res)
//{
//	all_res.emplace_back(res);
//}

ResourseManager::res_type ResourseManager::getTypeByFilename(std::string name)
{
	std::string::reverse_iterator it = name.rbegin();
	while (*it != '.' && it != name.rend()) 
	{
		it++;	
	}
	auto d1 = std::distance(name.rend(), it);
	auto d2 = std::distance(name.rbegin(), it);
	std::string extent = name.substr(abs(std::distance(name.rend(), it)), abs(std::distance(name.rbegin(), it)));
	auto t = extentToType.find(extent);
	if (t == extentToType.end())
	{
		return ResourseManager::res_type::Unknown_type;
	}
	else 
	{
		return t->second;
	}
		
}
//
//Resourse ResourseManager::getResourse(int id)
//{
//	if (all_res[id]->getRc == 0) 
//	{
//		all_res[id]->load();
//		all_res[id]->incRc();
//	}
//	all_res[id]->incRc();
//	return *all_res[id];
//}
//
//void ResourseManager::ReleaseResourse(int id)
//{
//	if (all_res[id]->getRc == 0)
//	{
//		return;
//	}
//	all_res[id]->decRc();
//	
//}

ResourseManager::~ResourseManager()
{
}
//
//void ResourseManager::ReleaseMemory()
//{
//	for (auto i : all_res) 
//	{
//		if (i->getRc == 0)
//		{
//			i->unload();
//		}
//	}
//}
