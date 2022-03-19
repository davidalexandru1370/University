#include "Repository.h"
#include "Operation.h"
#include <stdlib.h>
#include <string.h>
#include "Service.h"
int find_element_with_name_repository(Repository* repository, char* name);

Repository* create_repository(int size, destroy_function destroy_funct)
{
	Repository* my_repo = malloc(sizeof(Repository));
	vector* country_repo = create_vector(size, destroy_funct);
	vector* undo_repo = create_vector(1, &destroy_operation);
	vector* redo_repo = create_vector(1, &destroy_operation);
	my_repo->data = country_repo;
	my_repo->undo_vector = undo_repo;
	my_repo->redo_vector = redo_repo;
	return my_repo;
}

void destroy_repository(Repository* repository)
{
	destroy_vector(repository->data);
	destroy_vector(repository->undo_vector);
	destroy_vector(repository->redo_vector);
	free(repository);
}

void add_element_in_undo(Repository* repository, TEelem element, char command[])
{
	if (strcmp("add", command) == 0)
	{
		//undo the add operation => delete 
		Country* undo_country = create_country(
			get_country_population(element),
			get_country_name(element),
			get_continent_name(element)
		);
		Operation* undo_operation = create_operation("add", undo_country);
		add_element_in_vector(repository->undo_vector, undo_operation);
	}
	else if (strcmp("delete", command) == 0) {
		//undo the delete operation => add
		Country* country = create_country(
			get_country_population(element),
			get_country_name(element),
			get_continent_name(element)
		);
		Operation* operation = create_operation("delete", country);
		add_element_in_vector(repository->undo_vector, operation);
		//redo the delete operation => delete 
	}
	else if (strcmp("update", command) == 0 || strcmp("migrate", command) == 0) {
		Country* country = create_country(
			get_country_population(element),
			get_country_name(element),
			get_continent_name(element)
		);
		Operation* operation = create_operation(command, country);
		add_element_in_vector(repository->undo_vector, operation);
	}
}

void add_element_in_redo(Repository* repository, TEelem element, char command[]) {
	if (strcmp(command, "add") == 0)
	{
		//redo the add operation => add
		Country* redo_country = create_country(
			get_country_population(element),
			get_country_name(element),
			get_continent_name(element)
		);
		Operation* redo_operation = create_operation("add", redo_country);
		add_element_in_vector(repository->redo_vector, redo_operation);
	}
	else if (strcmp(command, "delete") == 0) {
		Country* redo_country = create_country(
			get_country_population(element),
			get_country_name(element),
			get_continent_name(element)
		);
		Operation* redo_operation = create_operation("delete", redo_country);
		add_element_in_vector(repository->redo_vector, redo_operation);
	}
}

void add_element_in_repository(Repository* repository, TEelem element)
{
	clear_vector(repository->redo_vector);
	add_element_in_undo(repository, element, "add");
	add_element_in_vector(repository->data, element);
}

int update_element_in_repository(Repository* repository, int index, TEelem element)
{
	Country* country_at_index = get_element_at_position_in_vector(repository->data, index);
	if (country_at_index != NULL)
	{
		clear_vector(repository->redo_vector);
		add_element_in_undo(repository, country_at_index, "update");
	}
	return update_at_position_in_vector(repository->data, index, element);
}

int remove_element_in_repository(Repository* repository, int index)
{
	Country* country_at_index = get_element_at_position_in_vector(repository->data, index);
	if (country_at_index != NULL)
	{

		clear_vector(repository->redo_vector);
		add_element_in_undo(repository, country_at_index, "delete");
		destroy_country(country_at_index);
	}

	return delete_at_position_in_vector(repository->data, index);
	//return delete_at_position_in_vector(repository->data, index);
}

TEelem get_element_in_repository(Repository* repository, int index) {
	return get_element_at_position_in_vector(repository->data, index);
}

vector* get_all(Repository* repository)
{
	return repository->data;
}

int get_repository_length(Repository* repository)
{
	return get_length(repository->data);
}

int repo_undo(Repository* repository) {
	if (get_length(repository->undo_vector) == 0)
	{
		return 0;
	}

	Operation* last_operation = get_element_at_position_in_vector
	(
		repository->undo_vector,
		get_length(repository->undo_vector) - 1
	);

	if (strcmp(last_operation->name, "add") == 0)
	{
		int index = find_element_with_name_repository(repository, get_country_name(last_operation->country));
		Country* country_from_repository = get_element_in_repository(repository, index);
		/*Country* copy = create_country(
			get_country_population(country_from_repository),
			get_country_name(country_from_repository),
			get_continent_name(country_from_repository)
		);*/
		//now push the add operation in redo repository
		add_element_in_redo(repository, country_from_repository, "add");
		//now delete b/c reverse of add is delete
		destroy_country(country_from_repository);
		delete_at_position_in_vector(repository->data, index);
		destroy_operation(last_operation);
		delete_at_position_in_vector(repository->undo_vector, get_length(repository->undo_vector) - 1);
		return 1;
	}
	else if (strcmp(last_operation->name, "delete") == 0) {
		Country* copy = create_country(
			get_country_population(last_operation->country),
			get_country_name(last_operation->country),
			get_continent_name(last_operation->country)
		);
		add_element_in_redo(repository, last_operation->country, "delete");
		add_element_in_vector(repository->data, copy);
		destroy_operation(last_operation);
		delete_at_position_in_vector(repository->undo_vector, get_length(repository->undo_vector) - 1);
		return 1;
	}
	else if (strcmp(last_operation->name, "update") == 0) {
		int index = find_element_with_name_repository(repository, get_country_name(last_operation->country));
		Country* copy = create_country(
			get_country_population(last_operation->country),
			get_country_name(last_operation->country),
			get_continent_name(last_operation->country)
		);
		//destroy_country(get_element_at_position_in_vector(repository->data, index));

		update_at_position_in_vector(repository->data, index, copy);
		destroy_operation(last_operation);
		delete_at_position_in_vector(repository->undo_vector, get_length(repository->undo_vector) - 1);
		return 1;
	}
	else if (strcmp(last_operation->name, "migrate") == 0) {
		Country* copy_migrate_to_country = create_country(
			get_country_population(last_operation->country),
			get_country_name(last_operation->country),
			get_continent_name(last_operation->country)
		);
		destroy_operation(last_operation);
		delete_at_position_in_vector(repository->undo_vector, get_length(repository->undo_vector) - 1);
		last_operation = get_element_at_position_in_vector(
			repository->undo_vector,
			get_length(repository->undo_vector) - 1
		);
		Country* copy_migrate_from_country = create_country(
			get_country_population(last_operation->country),
			get_country_name(last_operation->country),
			get_continent_name(last_operation->country)
		);
		int index_migrate_to_country = find_element_with_name_repository(repository, get_country_name(copy_migrate_to_country));
		int index_migrate_from_country = find_element_with_name_repository(repository, get_country_name(copy_migrate_from_country));
		update_at_position_in_vector(repository->data, index_migrate_to_country, copy_migrate_to_country);
		update_at_position_in_vector(repository->data, index_migrate_from_country, copy_migrate_from_country);
		destroy_operation(last_operation);
		delete_at_position_in_vector(repository->undo_vector, get_length(repository->undo_vector) - 1);
		return 1;
	}
	return 0;
}

int repo_redo(Repository* repository) {
	if (get_length(repository->redo_vector) == 0)
	{
		return 0;
	}

	Operation* last_operation = get_element_at_position_in_vector(repository->redo_vector, get_length(repository->redo_vector) - 1);
	if (strcmp(last_operation->name, "add") == 0)
	{
		//redo the add for a deleted item
		Country* copy = create_country(
			get_country_population(last_operation->country),
			get_country_name(last_operation->country),
			get_continent_name(last_operation->country)
		);
		add_element_in_vector(repository->data, copy);
		add_element_in_undo(repository, copy, "add");
		destroy_operation(last_operation);
		delete_at_position_in_vector(repository->redo_vector, get_length(repository->redo_vector) - 1);
		return 1;
	}
	else if (strcmp(last_operation->name, "delete") == 0) {
		Country* copy = create_country(
			get_country_population(last_operation->country),
			get_country_name(last_operation->country),
			get_continent_name(last_operation->country)
		);
		int index = find_element_with_name_repository(repository, get_country_name(copy));
		destroy_country(get_element_in_repository(repository, index));
		delete_at_position_in_vector(repository->data, index);
		add_element_in_undo(repository, copy, "delete");
		destroy_operation(last_operation);
		delete_at_position_in_vector(repository->redo_vector, get_length(repository->redo_vector) - 1);
		return 1;
	}
	return 0;
}

int find_element_with_name_repository(Repository* repository, char* name) {
	for (int index = 0; index < get_length(repository->data); index++)
	{
		Country* country = get_element_at_position_in_vector(repository->data, index);
		if (strcmp(get_country_name(country), name) == 0)
		{
			return index;
		}
	}
	return -1;
}