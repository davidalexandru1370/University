#include "Service.h"
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;
bool Service::sort_crt(School school1, School school2)
{
	if (strcmp(school1.get_name(), school2.get_name()) == 1) {
		return 0;
	}
	return 1;
}

void Service::task_3(char date[])
{
	
}

Service::Service(Repository* _repository)
{
	repository = _repository;
}

Service::~Service()
{
}

void Service::add(const char* name, float latitude, float longitude, const char* date_of_visit, bool visited)
{
	/// <summary>
	/// Add element into the repository through service
	/// </summary>
	/// <param name="name">char not empty representing the name of school</param>
	/// <param name="latitude">float not negative representing the latitude of school </param>
	/// <param name="longitude">float not negative representing the longitude of school</param>
	/// <param name="date_of_visit">char not empty representing the date of visit </param>
	School school{ name, longitude, latitude, date_of_visit ,visited };
	repository->add(school);
}

void Service::remove(char* name, float latitude, float longitude)
{
	/// <summary>
	/// Remove a shcool with given name and position
	/// </summary>
	/// <param name="name">char array not empty</param>
	/// <param name="latitude">float not negative</param>
	/// <param name="longitude">float not negative </param>
	repository->remove(name, latitude, longitude);
}

std::vector<School> Service::sort_by_name(std::vector<School> schools)
{
	//std::sort(schools.begin(), schools.end(), sort_crt);

	for (size_t i = 0; i < schools.size(); i++)
	{
		for (size_t j = i + 1; j < schools.size(); j++)
		{
			if (strcmp(schools[i].get_name(), schools[j].get_name()) == 1)
			{
				swap(schools[i], schools[j]);
			}
		}
	}
	return schools;
}

std::vector<School> Service::get_all()
{
	return repository->get_all();
}

void Service::generate_random()
{
	add("Avram_Iancu", 46.77, 23.60, "15.04.2022", true);
	add("George_Cosbuc", 46.77, 23.58, "18.04.2022", false);
	add("Alexandru_Vaida_Voievod", 46.77, 23.63, "23.04.2022", false);
	add("Romulus_Goga", 46.53, 24.57, "04.05.2022", false);
	add("Colegiul_Transilvania", 46.54, 24.57, "03.05.2022", false);
}
