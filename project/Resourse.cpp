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

void Resourse::load()
{
	
}

void Resourse::unload()
{
	
}


Resourse::~Resourse()
{
}
