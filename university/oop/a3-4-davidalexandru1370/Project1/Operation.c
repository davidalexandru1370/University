#include <string.h>
#include <stdlib.h>
#include "Operation.h"
#include "Country.h"

Operation* create_operation(char name[], Country* country)
{
	Operation* operation = malloc(sizeof(Operation));
	operation->name = malloc(sizeof(char) * (strlen(name) + 1));
	strcpy(operation->name, name);
	operation->country = country;
	return operation;
}

void destroy_operation(Operation* operation)
{
	free(operation->name);
	destroy_country(operation->country);
	free(operation);
}
