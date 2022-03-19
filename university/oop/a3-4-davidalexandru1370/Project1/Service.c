#include "Service.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define population_minimum 1000000

Service* create_service(Repository* repo)
{
	Service* service = malloc(sizeof(Service));
	service->repository = repo;
	return service;
}

void destroy_service(Service* service)
{
	destroy_repository(service->repository);
	free(service);
}

int add_element_in_service(Service* service, int population, char* name, char* continent)
{
	if (population < population_minimum)
	{
		return 0;
	}
	if (strlen(name) == 0)
	{
		return 0;
	}
	if (strlen(continent) == 0)
	{
		return 0;
	}
	if (find_element_with_name(service, name) != -1)
	{
		return 0;
	}
	Country* country = create_country(population, name, continent);
	add_element_in_repository(service->repository, country);
	return 1;
}

int update_element_in_service(Service* service, char* name, int new_population)
{
	int index = find_element_with_name(service, name);
	if (index == -1)
	{
		return 0;
	}
	char* continent = get_continent_name(get_element_in_repository(service->repository, index));
	Country* new_country = create_country(new_population, name, continent);
	update_element_in_repository(service->repository, index, new_country);
	return 1;
}

int remove_element_in_service(Service* service, char* name)
{
	int index = find_element_with_name(service, name);
	/*if (index == -1)
	{
		return 0;
	}
	TEelem* elem = get_element_in_repository(service->repository, index);
	destroy_country(elem);*/
	return remove_element_in_repository(service->repository, index);
}

vector* service_get_all(Service* service)
{
	return get_all(service->repository);
}

int get_service_length(Service* service)
{
	return get_repository_length(service->repository);
}

int find_element_with_name(Service* service, char* name) {
	for (int index = 0; index < get_repository_length(service->repository); index++)
	{
		Country* country = get_element_in_repository(service->repository, index);
		if (strcmp(get_country_name(country), name) == 0)
		{
			return index;
		}
	}
	return -1;
}

vector* get_countries_on_a_continent(Service* service, char* continent)
{
	//useless
	vector* countries_on_a_continent = create_vector(1, &destroy_country);
	for (int index = 0; index < get_repository_length(service->repository); index++)
	{
		Country* country = get_element_in_repository(service->repository, index);
		if (strcmp(get_continent_name(country), continent) == 0)
		{
			Country* copy = create_country(country->population, country->name, country->continent);
			add_element_in_vector(countries_on_a_continent, copy);
		}
	}
	return countries_on_a_continent;
}

vector* get_countries_on_continent_and_population(Service* service, char* continent, int population) {
	vector* countries_on_a_continent = create_vector(1, &destroy_country);
	for (int index = 0; index < get_repository_length(service->repository); index++)
	{
		Country* country = get_element_in_repository(service->repository, index);
		if (strlen(continent) == 0)
		{
			if (get_country_population(country) >= population)
			{
				Country* copy = create_country(country->population, country->name, country->continent);
				add_element_in_vector(countries_on_a_continent, copy);
			}
		}
		else if (strcmp(get_continent_name(country), continent) == 0)
		{
			if (get_country_population(country) >= population)
			{
				Country* copy = create_country(country->population, country->name, country->continent);
				add_element_in_vector(countries_on_a_continent, copy);
			}
		}
	}
	return countries_on_a_continent;
}

int undo(Service* service)
{
	return repo_undo(service->repository);
}

int redo(Service* service)
{
	return repo_redo(service->repository);
}

void sort_vector_ascending_by_population(vector* my_vector)
{
	for (int left_pointer = 0; left_pointer < get_length(my_vector); left_pointer++)
	{
		for (int right_pointer = left_pointer + 1; right_pointer < get_length(my_vector); right_pointer++)
		{
			Country* left_country = get_element_at_position_in_vector(my_vector, left_pointer);
			Country* right_country = get_element_at_position_in_vector(my_vector, right_pointer);
			if (get_country_population(left_country) > get_country_population(right_country))
			{
				my_vector->list[left_pointer] = right_country;
				my_vector->list[right_pointer] = left_country;
			}
		}
	}
}

void generate_random_countries(Service* service, int number)
{
	for (int index = 1; index <= number; index++)
	{
		char name[25];
		char country[25] = "Country";
		//strcpy(name,country);
		sprintf(name, "Country%d", index);
		char continent[25];
		if (index <= number / 2)
		{
			strcpy(continent, "Europa");
		}
		else {
			strcpy(continent, "Asia");
		}
		int population = (int)1e7 + index;
		//Country* country = create_country(population, name, continent);
		add_element_in_service(service, population, name, continent);
	}
}

TEelem get_service_element(Service* service, int index)
{
	return get_element_in_repository(service->repository, index);
}

int migrate_population_from_one_country_to_another(Service* service, char* from_country, char* to_country, int amount) {
	Country* migrate_from_country = get_element_in_repository(
		service->repository,
		find_element_with_name(service, from_country)
	);

	Country* migrate_to_country = get_element_in_repository(
		service->repository,
		find_element_with_name(service, to_country)
	);

	if (migrate_from_country == NULL || migrate_to_country == NULL || amount > get_country_population(migrate_from_country))
	{
		return 0;
	}

	/*Country* copy_migrate_from_country = create_country(
		get_country_population(migrate_from_country),
		get_country_name(migrate_from_country),
		get_continent_name(migrate_from_country)
	);

	Country* copy_migrate_to_country = create_country(
		get_country_population(migrate_to_country),
		get_country_name(migrate_to_country),
		get_continent_name(migrate_to_country)
	);*/

	add_element_in_undo(service->repository, migrate_from_country, "migrate");
	add_element_in_undo(service->repository, migrate_to_country, "migrate");

	set_country_population(migrate_from_country, get_country_population(migrate_from_country) - amount);
	set_country_population(migrate_to_country, get_country_population(migrate_to_country) + amount);
	return 1;
}