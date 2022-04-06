#include "UserRepository.h"
#include "Vector.h"

UserRepository::UserRepository(int size) : Repository{ size } {}

UserRepository::~UserRepository(){}

int UserRepository::check_if_element_exists(Trench& element)
{
	//Trench* trench = (Trench*)element;
	for (size_t index = 0; index < data.get_length(); index++)
	{
		if (element == data[index])
		{
			//element.set_quantity(element.get_quantity() + 1);
			return index;
		}
	}
	return -1;
}

void UserRepository::add_element(Trench element)
{
	int element_index = check_if_element_exists(element);
	if (element_index == -1) {
		element.set_quantity(1);
		data.push_back(element);
	}
	else {
		data[element_index].set_quantity(data[element_index].get_quantity() + 1);
	}
}

void UserRepository::remove_by_name(char* name)
{
	for (size_t index = 0; index < data.get_length(); index++)
	{
		Trench element = data[index];
		if (strcmp(element.get_color(), name) == 0)
		{
			remove_at(index);
			index--;
		}
	}
}
