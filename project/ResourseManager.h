#pragma once
#include "Resourse.h"
#include "Picture.h"
class ResourseManager
{
public:
	ResourseManager();
	Resourse getResourse(int id);
	void ReleaseResourse(int id);
	~ResourseManager();

//private:
	void addResourse(Resourse * res);
	void ReleaseMemory();
	std::vector<Resourse*> all_res;	//Массив всех имеющихся ресурсов
	std::vector<std::string> paths;	//

	enum res_type {Picture_type, Audio_type, Unknown_type};
	std::map<std::string, res_type> extentToType;
	res_type getTypeByFilename(std::string name);
};

