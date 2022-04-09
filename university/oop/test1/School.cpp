#include "School.h"
#include <string>
School::School(const char* _name, double _longitude, double _latitude, const char* _date_of_visit, bool _visited)
{
	name = new char[strlen(_name) + 1];
	date_of_visit = new char[strlen(_date_of_visit) + 1];
	strcpy(name, _name);
	strcpy(date_of_visit, _date_of_visit);
	latitude = _latitude;
	longitude = _longitude;
	visited = _visited;
}

School::~School()
{
}

School::School(const School& school) : latitude{ school.latitude }, longitude{ school.longitude }, visited{ school.visited }
{
	this->date_of_visit = new char[strlen(school.date_of_visit)];
	this->name = new char[strlen(school.name)];
	strcpy(this->date_of_visit, school.date_of_visit);
	strcpy(this->name, school.name);
}

char* School::get_name()
{
	return this->name;
}

float School::get_longitude()
{
	return this->longitude;
}

float School::get_latitude()
{
	return this->latitude;
}

char* School::get_date_of_visit()
{
	return this->date_of_visit;
}

bool School::get_visited()
{
	return visited;
}

void School::set_name(char* new_name)
{
	name = new char[strlen(new_name) + 1];
	strcpy(name, new_name);
}

void School::set_longitude(float new_longitude)
{
	longitude = new_longitude;
}

void School::set_latitude(float new_latitude)
{
	latitude = new_latitude;
}

void School::set_date_of_visit(char* new_date_of_visit)
{
	date_of_visit = new char[strlen(new_date_of_visit) + 1];
	strcpy(date_of_visit, new_date_of_visit);
}

void School::set_visited(bool new_value)
{
	visited = new_value;
}
