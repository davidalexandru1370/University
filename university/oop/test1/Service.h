#pragma once
#include "Repository.h"
class Service
{
private:
	Repository* repository;
	

public:
	Service(Repository* _repository);
	~Service();
	void add(const char* name, float latitude, float longitude, const char* date_of_visit,bool visited);
	void remove(char* name, float latitude, float longitude);
	std::vector<School>sort_by_name(std::vector<School>schools);
	std::vector<School> get_all();
	void generate_random();
	bool sort_crt(School school1, School school2);
	void task_3(char date[]);
};

