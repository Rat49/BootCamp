#include "stdafx.h"
#include "Resourse.h"


Resourse::Resourse(std::string id, std::string full_name):ID(id), full_name(full_name), ref_counter(0) 
{
}

void Resourse::incRc()
{
	++ref_counter;
}

void Resourse::decRc()
{
	--ref_counter;
}

int Resourse::getRc()
{
	return ref_counter;
}

void Resourse::load()
{
	
}

void Resourse::unload()
{
	
}


Resourse::~Resourse()
{
}
