#pragma once
#include <vector>
#include "Resourse.h"
template<class T>
class ResourseManager
{
public:
	ResourseManager():res(std::vector<T>(100));
	void addResourse(char * path);
	void removeResourse(int id);
	Resourse getResourse();
	int ReleaseResourse();
	~ResourseManager();

private:
	std::vector<T> res;	//Массив всех имеющихся ресурсов
};

