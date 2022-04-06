#pragma once
#include "Vector.h"
#include "Trench.h"
#include <vector>

class Repository
{
protected:
	std::vector<Trench> data;
	virtual int check_if_element_exists(Trench& element) = 0;
	char* input_file_name;
	char* output_file_name;
private:
	bool check_if_index_belongs(int index);
public:
	Repository();
	virtual void add_element(Trench element) = 0;
	void remove_at(int index);
	void update_at(int index, Trench new_element);
	std::vector<Trench> get_all();
	void write_to_file();
	void read_from_file();
};

