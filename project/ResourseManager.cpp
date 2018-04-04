#include "stdafx.h"
#include "ResourseManager.h"




ResourseManager::ResourseManager()
{
	all_res.reserve(100);
	paths.emplace_back("/images/picture1.bmp");
	paths.emplace_back("/images/picture2.bmp");
	paths.emplace_back("/audio/piupiu.wav");

	extentToType = { { "bmp", Picture_type },
	{ "wav", Audio_type } };

}

//inline void ResourseManager::addResourse(Resourse res)
//{
//	all_res.emplace_back(res);
//	all_res.back();
//
//}

ResourseManager::res_type ResourseManager::getTypeByFilename(std::string name)
{
	int exlength = 0;
	std::string::reverse_iterator it = name.rbegin();
	while (*it != '.') {//бесконечный цикл если нет точки!!!!!
		exlength++;
		it++;
	}
	std::string extent = name.substr(name.length() - exlength, exlength);
	auto t = extentToType.find(extent);
	if (t == extentToType.end()) return ResourseManager::res_type::Unknown_type;
		return t->second;
}

//Resourse ResourseManager::getResourse(int id)
//{
//	if (all_res[id]->getRc == 0) {
//	}
//	all_res[id]->incRc();
//	return *all_res[id];
//}
//
//void ResourseManager::ReleaseResourse(int id)
//{
//	if(all_res[id]->getRc != 0)	all_res[id]->decRc();
//}

ResourseManager::~ResourseManager()
{
}