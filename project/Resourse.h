#pragma once
class Resourse
{
public:
	Resourse(int id, char * full_name) :ID(id),full_name(full_name),ref_counter(1) {
	};
	void incRc();
	void decRc();
	int getRc();
	virtual bool load();
	virtual bool unload();
	virtual ~Resourse();
private:
	unsigned int ref_counter = 0;
	char * full_name;
	unsigned int ID;
};

