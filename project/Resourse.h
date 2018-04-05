#pragma once
class Resourse
{
public:
	Resourse(std::string id, std::string full_name) :ID(id),full_name(full_name),ref_counter(0) {
	};
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
