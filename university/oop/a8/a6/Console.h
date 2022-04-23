#include "TrenchService.h"
#include "Vector.h"
#include "Trench.h"
#include <string>
#pragma once
class Console
{
public:
	Console(TrenchService* _service);
	TrenchService* service;
	void run_console();
private:
	std::string output_extension;
	void print_administrator_menu();
	void print_user_menu();
	int type_of_user;
	void print_trenches(int size);
	void add_trench();
	void update_trench();
	void delete_trench();
	void user_buy_trench_ui(int size);
	void print_shopping_basket();
};