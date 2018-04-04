#include "stdafx.h"
#include "Resourse.h"


Resourse::Resourse()
{
}

void Resourse::incRc()
{
	ref_counter++;
}

void Resourse::decRc()
{
	ref_counter--;
}


Resourse::~Resourse()
{
}
