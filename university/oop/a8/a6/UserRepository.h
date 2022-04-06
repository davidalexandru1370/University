#pragma once
#include "Repository.h"
#include "Trench.h"
#include <string>

class UserRepository : public  Repository
{
private:
	int check_if_element_exists(Trench &element) override;

public:
	UserRepository();
	~UserRepository();
	void add_element(Trench element) override;
	void remove_by_name(char* name);
};

