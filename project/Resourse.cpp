#include "stdafx.h"
#include "Resourse.h"



void Resourse::incRc()
{
	ref_counter++;
}

void Resourse::decRc()
{
	ref_counter--;
}

int Resourse::getRc()
{
	
	return ref_counter;
}

bool Resourse::load()
{
	return false;
}

bool Resourse::unload()
{
	return false;
}


Resourse::~Resourse()
{
}
