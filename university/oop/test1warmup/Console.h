#pragma once
#include "Service.h"
class Console
{
public:
	void run_console();
	Service* service;
private:
	Console(Service* _service);
	void print_menu();
	void add_player();
	void print_all();
	void print_all_in_a_team_sorted();
};

