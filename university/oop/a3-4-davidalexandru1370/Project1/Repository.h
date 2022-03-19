#include "Vector.h"
#include "Country.h"
#pragma once
typedef struct
{
	vector* data;
	vector* undo_vector;
	vector* redo_vector;
}Repository;

Repository* create_repository(int size, destroy_function destroy_funct);

void destroy_repository(Repository* repository);

void add_element_in_repository(Repository* repository, TEelem element);

int update_element_in_repository(Repository* repository, int index, TEelem element);

int remove_element_in_repository(Repository* repository, int index);

vector* get_all(Repository* repository);

int get_repository_length(Repository* repository);

TEelem get_element_in_repository(Repository* repository, int index);

void add_element_in_undo(Repository* repository, TEelem element, char command[]);

void add_element_in_redo(Repository* repository, TEelem element, char command[]);

int repo_undo(Repository* repository);

int repo_redo(Repository* repository);


