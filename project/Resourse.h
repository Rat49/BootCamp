#pragma once
class Resourse
{
public:
	Resourse(std::string id, std::string full_name);
	void incRc();
	void decRc();
	int getRc();
	virtual void load();
	virtual void unload();
	virtual ~Resourse();
	std::string full_name;
private:
	unsigned int ref_counter;	
	std::string ID;
};
