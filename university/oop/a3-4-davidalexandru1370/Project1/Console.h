#pragma once
#include "Service.h"
typedef struct
{
	Service* service;
}Console;

Console* create_console(Service* service);

void print_menu();

void run_console(Console* console);

void destroy_console(Console* console);
