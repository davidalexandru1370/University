#pragma once
#include "Service.h"
class Console
{
public:
	void run_console();
	Console(Service* _service);
	
private:
	Service* service;
	void show_menu();
	void ui_remove();
	void list_all_sorted();
	void task_3();
};

