#include "Country.h"
#pragma once
typedef struct 
{
	char* name;
	Country* country;
}Operation;

Operation* create_operation(char name[], Country* country);

void destroy_operation(Operation* operation);