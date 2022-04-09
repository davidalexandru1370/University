#include "Console.h"
#include "Utils.h"
#include <iostream>
#include <string>
#define clear_buffer() fseek(stdin, 0, SEEK_END)
Console::Console(TrenchService* _service)
{
	service = _service;
	type_of_user = -1;
}

void Console::run_console()
{
	int running = 1;

	//service->generate_random_trenches(10);
	while (running)
	{
		while (type_of_user != 1 && type_of_user != 2 && type_of_user != 3)
		{
			printf("Press 1 for user mode\n");
			printf("Press 2 for admin mode\n");
			printf("Press 3 to exit!\n");
			printf("your choose=");
			clear_buffer();
			scanf("%d", &type_of_user);
		}
		int option = 0;
		if (type_of_user == 2)
		{
			print_administrator_menu();
			printf("your choose=");
			clear_buffer();

			scanf("%d", &option);
			if (option == 1)
			{
				add_trench();
			}
			else if (option == 2) {
				delete_trench();
			}
			else if (option == 3)
			{
				update_trench();
			}
			else if (option == 4)
			{
				print_trenches(0);
			}
			else if (option == 5) {
				type_of_user = 0;
			}
			else {
				printf("Invalid menu\n");
			}
		}
		else if (type_of_user == 1) {
			print_user_menu();
			printf("your choose=");
			clear_buffer();
			scanf("%d", &option);
			if (option == 1)
			{
				printf("size=");
				char size[25];
				int trench_size = 0;
				clear_buffer();
				try
				{
					fgets(size, 25, stdin);
					if (strlen(size) == 0)
					{
						trench_size = 0;
					}
					else
					{
						trench_size = Utils().convert_char_to_integer(size);
					}
				}
				catch (const std::exception&)
				{
					printf("Invalid size\n");
					continue;
				}

				if (trench_size < 0)
				{
					printf("Invalid size\n");
					continue;
				}
				user_buy_trench_ui(trench_size);
			}
			else if (option == 2) {
				print_shopping_basket();
			}
			else if (option == 3)
			{
				type_of_user = 0;
			}
			else {
				printf("Invalid menu!\n");
			}
		}
		else if (type_of_user == 3) {
			running = 0;
		}
	}
}

void Console::print_administrator_menu()
{
	printf("Administrator menu:\n");
	printf("Press 1 to add a new trench coat\n");
	printf("Press 2 to delete a trench coat\n");
	printf("Press 3 to update a trench coat\n");
	printf("Press 4 to list all trench coats\n");
	printf("Press 5 to change menu\n");
}

void Console::print_user_menu()
{
	printf("User menu:\n");
	printf("Press 1 to see the trench coats by size\n");
	printf("Press 2 to see the shopping basket\n");
	printf("Press 3 to change menu\n");
}

void Console::print_trenches(int size = 0)
{
	//Vector* list = service->get_all();
	std::vector<Trench> list = service->get_all();
	for (size_t index = 0; index < list.size(); index++)
	{
		Trench trench = list[index];
		if (size == 0)
		{
			/*printf("size = %d colour = %s price = %d quantity = %d photograph = %s\n",
				trench.get_size(),
				trench.get_color(),
				trench.get_price(),
				trench.get_quantity(),
				trench.get_photograph()
			);*/
			cout << trench<<"\n";
		}
		else if (trench.get_size() == size)
		{
			/*printf("size = %d colour = %s price = %d quantity = %d photograph = %s\n",
				trench.get_size(),
				trench.get_color(),
				trench.get_price(),
				trench.get_quantity(),
				trench.get_photograph()
			);*/
			cout << trench << "\n";
			
		}
		
	}
}

void Console::add_trench()
{
	int size, quantity, price;
	char color[50];
	char photograph[50];
	clear_buffer();
	printf("size=");
	scanf("%d", &size);
	printf("quantity=");
	scanf("%d", &quantity);
	printf("price=");
	scanf("%d", &price);
	clear_buffer();
	printf("color=");
	scanf("%s", color);
	printf("photograph=");
	scanf("%s", photograph);
	try
	{
		service->add_element(size, color, price, quantity, photograph);
	}
	catch (const std::exception&)
	{
		printf("Element already exists in the repository!\n");
	}
}

void Console::update_trench()
{
	int index, quantity;
	clear_buffer();
	printf("index=");
	scanf("%d", &index);
	printf("new quantity=");
	scanf("%d", &quantity);
	service->update_element(index, quantity);
}

void Console::delete_trench()
{
	int index;
	clear_buffer();
	printf("index=");
	scanf("%d", &index);
	try
	{
		service->delete_element(index);
	}
	catch (const std::exception& except)
	{
		std::cout << except.what();
	}
}

void Console::user_buy_trench_ui(int size)
{
	std::vector<Trench> list = service->get_all();
	for (size_t index = 0; index < list.size(); index++)
	{
		if (list[index].get_size() == size || size == 0)
		{
			int user_buy_option = 0;
			if (list[index].get_quantity() > 0)
			{
				/*printf("size = %d colour = %s price = %d quantity = %d photograph = %s\n",
					list[index].get_size(),
					list[index].get_color(),
					list[index].get_price(),
					list[index].get_quantity(),
					list[index].get_photograph()
				);*/
				cout << list[index]<<"\n";
				printf("Press 1 to buy or press 0 to skip or press 2 to exit.\n your choose=");
				scanf("%d", &user_buy_option);
				if (user_buy_option == 1)
				{
					if (list[index].get_quantity() >= 1)
					{
						service->add_element_in_shopping_basket(list[index]);
						index--;
					}
				}
				if (user_buy_option == 2)
				{
					return;
				}
				if ((index + 1) == list.size())
				{
					index = 0;
				}
			}
		}
	}
}

void Console::print_shopping_basket()
{
	std::vector<Trench> list = service->get_elements_in_shopping_basket();
	int sum = 0;
	for (size_t index = 0; index < list.size(); index++)
	{
		Trench trench = list[index];
		/*printf("size = %d colour = %s price = %d quantity = %d photograph = %s\n",
			trench.get_size(),
			trench.get_color(),
			trench.get_price(),
			trench.get_quantity(),
			trench.get_photograph()
		);*/
		cout << trench;
		sum += trench.get_price() * trench.get_quantity();
	}
	printf("Total sum=%d\n", sum);
}


