#include <stdlib.h>
#include "Vector.h"

vector* create_vector(int capacity, destroy_function destroy_funct)
{
	vector* dynamic_vector = (vector*)malloc(sizeof(vector));
	dynamic_vector->length = 0;
	dynamic_vector->size = capacity;
	dynamic_vector->list = malloc(sizeof(TEelem) * capacity);
	dynamic_vector->destroy_func = destroy_funct;
	return dynamic_vector;
}

void destroy_vector(vector* my_vector)
{
	for (int index = 0; index < my_vector->length; index++)
	{
		my_vector->destroy_func(my_vector->list[index]);
	}
	free(my_vector->list);
	free(my_vector);
}

vector* get_copy(vector* my_vector)
{
	vector* copy_of_my_vector = create_vector(my_vector->size, my_vector->destroy_func);
	copy_of_my_vector->length = my_vector->length;
	for (int i = 0; i < my_vector->length; i++)
	{
		copy_of_my_vector[i] = my_vector[i];
	}
	return copy_of_my_vector;
}

int get_size(vector* my_vector)
{
	return my_vector->size;
}

void set_vector_length(vector* my_vector, int new_length) {
	my_vector->length = 0;
}

void resize(vector* my_vector)
{
	int factor = 2;
	TEelem* new_list = (TEelem*)malloc(sizeof(TEelem) * my_vector->size * factor);
	for (int i = 0; i < my_vector->length; i++)
	{
		new_list[i] = my_vector->list[i];
	}
	free(my_vector->list);
	my_vector->size *= 2;
	my_vector->list = new_list;
}

int is_full(vector* my_vector)
{
	return my_vector->length == my_vector->size ? 1 : 0;
}

void add_element_in_vector(vector* my_vector, TEelem element)
{
	if (is_full(my_vector) == 1)
	{
		resize(my_vector);
	}
	my_vector->list[my_vector->length] = element;
	my_vector->length += 1;
}

int delete_at_position_in_vector(vector* my_vector, int index)
{
	if (check_if_index_belongs(my_vector, index) == 0)
	{
		return 0;
	}

	for (size_t vector_index = index; vector_index < my_vector->length; vector_index++)
	{
		my_vector->list[vector_index] = my_vector->list[vector_index + 1];
	}
	my_vector->length -= 1;
	return 1;
}

int update_at_position_in_vector(vector* my_vector, int index, TEelem new_element)
{
	if (check_if_index_belongs(my_vector, index) == 0)
	{
		return 0;
	}
	my_vector->destroy_func(my_vector->list[index]);
	my_vector->list[index] = new_element;
	return 1;

}

TEelem get_element_at_position_in_vector(vector* my_vector, int index)
{
	if (check_if_index_belongs(my_vector, index) == 0) {
		return NULL;
	}
	return my_vector->list[index];
}

int check_if_index_belongs(vector* my_vector, int index) {
	return !(index < 0 || index >= my_vector->length || my_vector->length == 0);
}

int get_length(vector* my_vector) {
	return my_vector->length;
}

void clear_vector(vector* my_vector) {
	for (int index = 0; index < my_vector->length; index++)
	{
		my_vector->destroy_func(my_vector->list[index]);
	}
	set_vector_length(my_vector, 0);
}