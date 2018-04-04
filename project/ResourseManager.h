#pragma once
#include <vector>
#include "Resourse.h"
#include <SFML\Audio.hpp>
#include <SFML\Graphics.hpp>
template<class T>
class ResourseManager
{
public:
	ResourseManager();
	void addResourse(Resourse res);
	void removeResourse(int id);
	Resourse getResourse();
	int ReleaseResourse();
	~ResourseManager();

private:
	std::vector<T> res;	//Массив всех имеющихся ресурсов
	std::vector::iterator it;
};

