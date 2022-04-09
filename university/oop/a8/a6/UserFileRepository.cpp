#include "UserFileRepository.h"
#include <string>
#include <fstream>
UserFileRepository::UserFileRepository(const char* file)
{
	file_name = new char[strlen(file)];
	strcpy(file_name, file);
	read_from_file();
}

void UserFileRepository::write_to_file()
{
	std::ofstream f(file_name);
	for (auto& element : data)
	{
		f << element << "\n";
	}
}

void UserFileRepository::read_from_file()
{
	std::ifstream f(file_name);
	Trench element;
	//check if file is empty
	if (f.peek() == std::ifstream::traits_type::eof())
	{
		return;
	}
	while (f >> element)
	{
		add_element(element);
	}
}
