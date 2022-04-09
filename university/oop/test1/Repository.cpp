#include "Repository.h"
#include <vector>
#define eps 0.1
void Repository::add(School school)
{
	/// <summary>
	/// Add element into repository.
	/// </summary>
	/// <param name="school">School entity valid</param>
	data.push_back(school);
}

void Repository::remove(char* name, float latitude, float longitude)
{
	/// <summary>
	/// Remove an element from repository by  name and its position
	/// </summary>
	/// <param name="name">char array not empty</param>
	/// <param name="latitude">float number not negative representing latitude position</param>
	/// <param name="longitude">float number strictly positive representing longitude positoon</param>
	for (std::vector<School>::iterator it = data.begin(); it < data.end(); it++)
	{
		if (strcmp((*it).get_name(), name) == 0 && abs((*it).get_latitude() - latitude) < eps && abs((*it).get_longitude() - longitude) < eps)
		{
			data.erase(it);
			return;
		}
	}
	throw std::exception("A school with that name at that coordinates does not exist!\n");
}

std::vector<School> Repository::get_all()
{
	return data;
}
