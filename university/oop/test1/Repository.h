#pragma once
#include "School.h"
#include <vector>
class Repository
{
private:
	std::vector<School> data;

public:
	void add(School school);
	void remove(char* name, float latitude, float longitude);
	std::vector<School> get_all();
};

