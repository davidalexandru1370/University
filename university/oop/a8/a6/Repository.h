#pragma once
#include "Vector.h"
#include "Trench.h"
#include <vector>
#include <exception>
#include <string>

class RepositoryException : std::exception 
{
public:
	RepositoryException(std::string error);
	const char* what() const noexcept override;
private:
	std::string message;
};

class Repository
{
protected:
	std::vector<Trench> data;
	virtual int check_if_element_exists(Trench& element) = 0;
	char* file_name;
private:
	bool check_if_index_belongs(int index);
public:
	Repository();
	virtual void add_element(Trench element) = 0;
	void remove_at(int index);
	void update_at(int index, Trench new_element);
	std::vector<Trench> get_all();

};

