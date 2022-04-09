#pragma once
#include "TrenchRepository.h"
class TrenchFileRepository :public  TrenchRepository
{
private:
	char* file_name;
public:
	TrenchFileRepository();
	TrenchFileRepository(const char* _file_name);
	~TrenchFileRepository();
	void write_to_file();
	void read_from_file();
};

