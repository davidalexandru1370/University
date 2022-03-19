#include "Console.h"
#include "Service.h"
#include "Vector.h"
#include <stdlib.h>
#include <stdio.h>
#define country_minima_population 1000000
Console* create_console(Service* service)
{
	Console* console = (Console*)malloc(sizeof(Console));
	console->service = service;
	return console;
}

void list_all_countries(Console* console);
void print_on_given_continent_ascending_by_population(Console* console);
int ui_undo(Console* console);

void print_menu()
{
	printf("add\n");
	printf("delete\n");
	printf("update\n");
	printf("list\n");
	printf("sort\n");
	printf("undo\n");
	printf("redo\n");
	printf("exit\n");
}

void destroy_console(Console* console) {
	destroy_service(console->service);
	free(console);
}

void run_console(Console* console)
{
	int running = 1;
	generate_random_countries(console->service, 10);
	while (running)
	{
		print_menu();
		char input[50];
		scanf("%s", input);
		//printf("%s\n", input);
		if (strcmp(input, "add") == 0)
		{
			if (ui_add_country(console) == 0) {
				printf("Country was not added!\n");
			}
			else {
				printf("Country was added!\n");
			}
		}
		else if (strcmp(input, "delete") == 0) {
			if (ui_delete_country(console) == 0)
			{
				printf("Country was not deleted\n");
			}
			else {
				printf("Country deleted succesfully!\n");
			}
		}
		else if (strcmp(input, "update") == 0) {
			int result = ui_update_a_country(console);
			if (result == 0 || result == -1)
			{
				printf("Country not updated!\n");
			}
			else {
				printf("Country updated!\n");
			}
		}
		else if (strcmp(input, "list") == 0) {
			list_all_countries(console);
		}
		else if (strcmp(input, "exit") == 0) {
			running = 0;
		}
		else if (strcmp(input, "sort") == 0) {
			print_on_given_continent_ascending_by_population(console);
		}
		else if (strcmp(input, "undo") == 0) {
			int result = ui_undo(console);
			if (result == 0)
			{
				printf("Cannot undo!\n");
			}
		}
		else if (strcmp(input, "redo") == 0) {
			int result = ui_redo(console);
			if (result==0)
			{
				printf("Cannot redo!\n");
			}
		}
		else {
			printf("No command found!\n");
		}

	}
}

int ui_add_country(Console* console) {
	char population[15], name[20], continent[20];
	printf("population=");
	scanf("%s", population);
	printf("name=");
	scanf("%s", name);
	printf("continent=");
	scanf("%s", continent);
	int population_number = 0;
	for (int index = 0; index < strlen(population); index++)
	{
		if (population[index] < '0' || population[index]>'9')
		{
			return 0;
		}
		population_number = population_number * 10 + population[index] - '0';
	}
	return add_element_in_service(console->service, population_number, name, continent);
}

int ui_update_a_country(Console* console) {
	char type_of_update[10];
	printf("update\nmigrate\n");
	scanf("%s", type_of_update);
	if (strcmp(type_of_update, "update") == 0)
	{
		char from_country[25];
		int new_population;
		printf("from country=");
		scanf("%s", from_country);
		printf("new population=");
		scanf("%d", &new_population);
		if (new_population < country_minima_population)
		{
			return 0;
		}
		return update_element_in_service(console->service, from_country, new_population);
	}
	else if (strcmp(type_of_update, "migrate") == 0) {
		char from_country[25], to_country[25];
		printf("from country=");
		fseek(stdin, 0, SEEK_END);
		scanf("%s", from_country);
		printf("to country=");
		fseek(stdin, 0, SEEK_END);
		scanf("%s", to_country);
		int amount_of_people;
		printf("people=");
		fseek(stdin, 0, SEEK_END);
		scanf("%d", &amount_of_people);
		/*int index_from_country = find_element_with_name(console->service, from_country);
		int index_to_country = find_element_with_name(console->service, to_country);
		if (index_from_country == -1 || amount_of_people > get_country_population(get_service_element(console->service, index_from_country)))
		{
			return 0;
		}

		if (index_to_country == -1)
		{
			return 0;
		}

		set_country_population(get_service_element(console->service, index_from_country), get_country_population(get_service_element(console->service, index_from_country)) - amount_of_people);
		set_country_population(get_service_element(console->service, index_to_country), get_country_population(get_service_element(console->service, index_to_country)) + amount_of_people);
		*/
		return migrate_population_from_one_country_to_another(console->service, from_country, to_country, amount_of_people);
	}
	else {
		printf("Invalid update!");
	}
	return 0;
}

void print_on_given_continent_ascending_by_population(Console* console) {
	printf("continent=");
	char continent[25];
	int population;
	fseek(stdin, 0, SEEK_END);
	gets_s(continent, 25);
	printf("population greater >=");
	fseek(stdin, 0, SEEK_END);
	scanf("%d", &population);
	vector* result = get_countries_on_continent_and_population(console->service, continent, population);
	if (get_length(result) > 1)
	{
		sort_vector_ascending_by_population(result);
	}
	for (int index = 0; index < get_length(result); index++)
	{
		Country* country = get_element_at_position_in_vector(result, index);
		printf("Country name = %s continent = %s population = %d \n",
			get_country_name(country),
			get_continent_name(country),
			get_country_population(country)
		);
	}
	destroy_vector(result);
}

int ui_delete_country(Console* console) {
	char name[20];
	printf("name=");
	scanf("%s", name);

	return remove_element_in_service(console->service, name);
}

void list_all_countries(Console* console) {
	int index;
	char pattern[25];
	char empty[] = { "" };
	printf("pattern=");
	fseek(stdin, 0, SEEK_END);
	gets_s(pattern, 25);
	if (strcmp(pattern, empty) == 0)
	{
		for (index = 0; index < get_service_length(console->service); index++)
		{
			printf("Country name = %s population = %d continent = %s",
				get_country_name(get_service_element(console->service, index)),
				get_country_population(get_service_element(console->service, index)),
				get_continent_name(get_service_element(console->service, index)));
			printf("\n");
		}
	}
	else {
		for (index = 0; index < get_service_length(console->service); index++)
		{
			if (strstr(get_country_name(get_service_element(console->service, index)), pattern) != NULL)
			{
				printf("Country name = %s\n", get_country_name(get_service_element(console->service, index)));
			}
		}
	}
}

int ui_undo(Console* console) {
	return undo(console->service);
}

int ui_redo(Console* console) {
	return redo(console->service);
}