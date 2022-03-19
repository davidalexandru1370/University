#pragma once
typedef struct
{
	int population;
	char* name;
	char* continent;
}Country;

Country* create_country(int _population, char _name[], char _continent[]);

int get_country_population(Country* _country);

char* get_country_name(Country* _country);

char* get_continent_name(Country* _country);

void set_country_population(Country* _country, int _value);

int destroy_country(Country* _country);