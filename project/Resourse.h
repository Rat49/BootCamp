#pragma once
class Resourse
{
public:
	Resourse();
	void incRc();
	void decRc();
	virtual ~Resourse();
private:
	unsigned int ref_counter = 0;
	char * path;
	char * name;
};

