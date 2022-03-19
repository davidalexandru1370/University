#include "Repository.h"
#pragma once
typedef struct
{
	Repository* repository;
}Service;

Service* create_service(Repository* repo);

void destroy_service(Service* service);

int add_element_in_service(Service* service, int population, char* name, char* continent);

int update_element_in_service(Service* service, char* name, int new_population);

int remove_element_in_service(Service* service, char* name);

vector* service_get_all(Service* service);

int get_service_length(Service* service);

int find_element_with_name(Service* service, char* name);

vector* get_countries_on_a_continent(Service* service, char* continent);

void sort_vector_ascending_by_population(vector* my_vector);

void generate_random_countries(Service* service, int number);

TEelem get_service_element(Service* service, int index);

vector* get_countries_on_continent_and_population(Service* service, char* continent, int population);

int undo(Service* service);

int redo(Service* service);

int migrate_population_from_one_country_to_another(Service* service, char* from_country, char* to_country, int amount);