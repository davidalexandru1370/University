#pragma once
#include <stdlib.h>
typedef void* TEelem;
typedef void (*destroy_function)(void*);
typedef struct 
{
	int length;
	int size;
	TEelem* list;
	destroy_function destroy_func;
}vector;

vector* create_vector(int capacity,destroy_function destroy_funct);

void destroy_vector(vector* my_vector);

vector* get_copy(vector* my_vector);

int get_size(vector* my_vector);

void resize(vector* my_vector);

int is_full(vector* my_vector);

void add_element_in_vector(vector* my_vector,TEelem element);

int delete_at_position_in_vector(vector* my_vector, int index);

int update_at_position_in_vector(vector* my_vector, int index, TEelem new_element);

TEelem get_element_at_position_in_vector(vector* my_vector, int index);

int get_length(vector* my_vector);

void clear_vector(vector* my_vector);
