#pragma once
#include "Repository.h"
#include "UserRepository.h"
#include <string>
class UserFileRepository: public UserRepository	
{
private:
	char* file_name;
	std::string output_extension;
public:
	UserFileRepository(const char* file);
	void add_element(Trench element) override;
	void write_to_file();
	void read_from_file();
	void set_output_extension(std::string extension);
};

