#include "TrenchFileRepository.h"
#include <iostream>
#include <fstream>

TrenchFileRepository::TrenchFileRepository(const char* _file_name)
{
	file_name = new char[strlen(_file_name)];
	strcpy(file_name, _file_name);
	read_from_file();
}

TrenchFileRepository::~TrenchFileRepository()
{
}

void TrenchFileRepository::write_to_file()
{
	std::ofstream f(file_name);
	for (auto& element : data)
	{
		f << element << "\n";
	}
}

void TrenchFileRepository::read_from_file()
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