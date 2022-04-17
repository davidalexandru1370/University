#include "TrenchRepository.h"
#include "Trench.h"
#include <string>
TrenchRepository::TrenchRepository() {
	file_name = new char[15];
	strcpy(file_name, "input.txt");
}

TrenchRepository::~TrenchRepository() = default;

int TrenchRepository::check_if_element_exists(Trench & element)
{
	/*for (size_t index = 0; index < data.size(); index++)
	{
		if (element == data[index])
		{
			return index;
		}
	}*/
	auto index = std::find_if(data.begin(), data.end(), [element](Trench& trench)  {return trench == element; });
	if (data.end() != index)
	{
		throw RepositoryException("Element already exists\n");
	}
	return 1;
}

void TrenchRepository::add_element(Trench element)
{
	/*
	int index = check_if_element_exists(element);
	if (index != -1)
	{
		/*Trench new_one = *(Trench*)data->get_element(index) + *(Trench*)element;
		Trench* a = new Trench(new_one.get_size(), new_one.get_quantity(), new_one.get_color(), new_one.get_price(), new_one.get_photograph());
		data->set_element(index, a);
}
	else {
	}
	*/
	check_if_element_exists(element);
	data.push_back(element);
}
