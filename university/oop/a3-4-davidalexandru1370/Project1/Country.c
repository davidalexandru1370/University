#include "Country.h"
#include <stdlib.h>
#include <string.h>
Country* create_country(int _population, char _name[], char _continent[])
{
	Country* country = (Country*)malloc(sizeof(Country));
	if (country == NULL)
	{
		return NULL;
	}
	country->population = _population;
	country->name = (char*)malloc(sizeof(char) * (strlen(_name) + 1));
	strcpy(country->name, _name);
	country->continent = (char*)malloc(sizeof(char) * (strlen(_continent) + 1));
	strcpy(country->continent, _continent);
	return country;
}

int get_country_population(Country* _country)
{
	return _country->population;
}

char* get_country_name(Country* _country)
{
	return _country->name;
}

char* get_continent_name(Country* _country)
{
	return _country->continent;
}

void set_country_population(Country* _country, int _value) {
	_country->population = _value;
}

int destroy_country(Country* _country) {
	if (_country==NULL)
	{
		return 0;
	}
	free(_country->name);
	free(_country->continent);
	free(_country);
	return 1;
}

