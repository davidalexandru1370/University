#include "Tests.h"
#include "Vector.h"
#include "Trench.h"
#include "TrenchRepository.h"
#include "TrenchService.h"
#include "TrenchValidator.h"
#include <cassert>
#include <string>

void Tests::run_all_tests()
{
	test_vector_constructor();
	test_vector_push_back();
	test_trench();
	test_trench_add_repository();
	test_delete_repository();
	test_update_repository();
	test_service_add();
	test_trench_getters_and_setters();
	test_trench_validator();
}

void Tests::test_vector_constructor()
{
	Vector<int> v{ 1 };
	assert(v.get_length() == 0);
	assert(v.get_size() == 1);
}

void Tests::test_vector_push_back()
{
	int a = 1;
	int b = 2;
	int c = 3;
	Vector<int>v{ 1 };
	Vector<int>v2{ 1 };
	v.push_back(a);
	assert(v.get_length() == 1);
	assert(v[0] == 1);
	v.push_back(b);
	assert(v.get_length() == 2);
	assert(v[1] == 2);
	v.push_back(c);
	assert(v.get_length() == 3);
	assert(v[2] == 3);
	int test = 0;

	try
	{
		int test = v[10];
	}
	catch (const std::exception& except)
	{
		if (test != 0)
		{
			assert(false);
		}
	}
	v2 = v;
	assert(v2.get_length() == 3);
}

void Tests::test_trench()
{
	char color[] = "color";
	char photograph[] = "photograph";
	Trench* trench = new Trench(5, 5, color, 5, photograph);
	assert(strcmp(trench->get_color(), color) == 0);
	assert(trench->get_price() == 5);
	assert(trench->get_quantity() == 5);
	assert(trench->get_size() == 5);
}

void Tests::test_trench_getters_and_setters()
{
	char color[] = "color";
	char photograph[] = "photograph";
	Trench trench;
	trench.set_size(5);
	assert(trench.get_size() == 5);
	trench.set_quantity(7);
	assert(trench.get_quantity() == 7);
	trench.set_color(color);
	assert(strcmp(trench.get_color(), color) == 0);
	trench.set_price(10);
	assert(trench.get_price() == 10);
	trench.set_photograph(photograph);
	assert(strcmp(trench.get_photograph(), photograph) == 0);
	Trench* equal_trench = new Trench(5, 5, color, 5, photograph);
	assert(trench == *equal_trench);
	char color2[] = "color2";
	equal_trench->set_color(color2);
	assert((trench == *equal_trench) == false);
	trench = trench + *equal_trench;
	assert(trench.get_quantity() == 12);
}

void Tests::test_trench_add_repository()
{
	TrenchRepository* repository = new TrenchRepository(1);
	char color[] = "color";
	char photograph[] = "photograph";
	Trench trench{ 5, 5, color, 5, photograph };
	repository->add_element(trench);
	assert(repository->get_all().get_length() == 1);
	Trench trench2 = repository->get_all()[0];
	assert(strcmp(trench2.get_color(), trench.get_color()) == 0);
	assert(trench2 == trench);
	Trench same_trench{ 5,5,color,5,photograph };
	repository->add_element(same_trench);
	assert(repository->get_all().get_length() == 1);
	//repository->~TrenchRepository();
}

void Tests::test_delete_repository()
{
	TrenchRepository* repository = new TrenchRepository(1);
	char color[] = "color";
	char photograph[] = "photograph";
	Trench trench{ 5, 5, color, 5, photograph };
	repository->add_element(trench);
	assert(repository->get_all().get_length() == 1);
	repository->remove_at(0);
	assert(repository->get_all().get_length() == 0);
}

void Tests::test_update_repository()
{
	TrenchRepository* repository = new TrenchRepository(1);
	char color[] = "color";
	char photograph[] = "photograph";
	Trench trench{ 5, 5, color, 5, photograph };
	char color2[] = "update_color";
	char photograph2[] = "update_photograph";
	Trench trench2 = { 10, 10, color2, 10, photograph2 };
	repository->add_element(trench);
	repository->update_at(0, trench2);
	assert(repository->check_if_element_exists(trench2) != -1);
}

void Tests::test_service_add()
{
	TrenchRepository* repository = new TrenchRepository(1);
	UserRepository* user_repository = new UserRepository(1);
	TrenchService* service = new TrenchService(repository, user_repository);
	char color[] = "color";
	char photograph[] = "photograph";
	service->add_element(5, color, 5, 5, photograph);
	assert(service->get_all().get_length() == 1);
	try
	{
		service->add_element(-1, color, 5, 5, photograph);
	}
	catch (const std::exception&)
	{

	}
}

void Tests::test_trench_validator()
{
	char color[] = "color";
	char photograph[] = "photograph";
	char empty_color[] = "";
	char empty_photograph[] = "";
	Trench* trench = new Trench(-1, 1, color, 5, photograph);
	assert(TrenchValidator().validate(0,color,5,5,photograph) == false);
	assert(TrenchValidator().validate(5,color,-1,5,photograph) == false);
	assert(TrenchValidator().validate(5,color,5,-1,photograph) == false);
	assert(TrenchValidator().validate(5, empty_color, 5, 5, photograph)==false);
	assert(TrenchValidator().validate(5, color, 5, 5, empty_photograph)==false);
	assert(TrenchValidator().validate(trench) == false);
	trench = new Trench(1, -1, color, 5, photograph);
	assert(TrenchValidator().validate(trench) == false);
	trench = new Trench(1, 1, empty_color, 5, photograph);
	assert(TrenchValidator().validate(trench) == false);
	trench = new Trench(1, 1, color, -5, photograph);
	assert(TrenchValidator().validate(trench) == false);
	trench = new Trench(1, 1, color, 5, empty_photograph);
	assert(TrenchValidator().validate(trench) == false);
	trench = new Trench(1, 1, color, 5, photograph);
	assert(TrenchValidator().validate(trench) == true);
}


