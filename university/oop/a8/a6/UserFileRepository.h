#pragma once
#include "Repository.h"
#include "UserRepository.h"
class UserFileRepository: public UserRepository
{
private:
	char* file_name;

public:
	UserFileRepository(const char* file);
	void write_to_file();
	void read_from_file();
};

