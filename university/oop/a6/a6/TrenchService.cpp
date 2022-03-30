#include "TrenchService.h"
#include "TrenchValidator.h"
#include "UserRepository.h"
#include "TrenchRepository.h"
#include <exception>
#include <iostream>
#include <stdlib.h>

TrenchService::TrenchService(TrenchRepository* _repository, UserRepository* _user_repository)
{
	/// <summary>
	/// Constructor for trench service
	/// </summary>
	/// <param name="_repository">trench repository</param>
	/// <param name="_user_repository">user repository</param>
	/// <returns></returns>
	repository = _repository;
	user_repository = _user_repository;
}

TrenchService::~TrenchService()
{
	/// <summary>
	/// Trench destructor deletes  repositories
	/// </summary>
	/// <returns></returns>
	delete repository;
	delete user_repository;
}

void TrenchService::add_element(int size, char colour[], int price, int quantity, char photograph[])
{
	/// <summary>
	/// Validate the trench element build using parameters and add it into repository
	/// </summary>
	/// <param name="size">integer strictly positive</param>
	/// <param name="colour">char array not empty</param>
	/// <param name="price">integer strictly positive</param>
	/// <param name="quantity">integer strictly positive</param>
	/// <param name="photograph">char array not empty</param>
	if (TrenchValidator().validate(size, colour, price, quantity, photograph) == false)
	{
		throw std::exception();
	}
	Trench* new_trench = new Trench(size, quantity, colour, price, photograph);
	repository->add_element(*new_trench);
}

void TrenchService::delete_element(int index)
{
	/// <summary>
	/// Delete element at given index
	/// </summary>
	/// <param name="index">integer strictly positive</param>
	//Trench* copy = (Trench*)repository->get_all()->get_element(index);
	Trench copy = repository->get_all()[index];
	//copy = new Trench(copy.get_size(), copyget_quantity(), copy->get_color(), copy->get_price(), copy->get_photograph());
	repository->remove_at(index);
	user_repository->remove_by_name(copy.get_color());
}

void TrenchService::update_element(int index, int new_quantity)
{
	/// <summary>
	/// Update element at given index with new quantity
	/// </summary>
	/// <param name="index">integer strictly positive </param>
	/// <param name="new_quantity">integer strictly positive</param>
	//Trench* new_trench = new Trench(*(Trench*)get_all()->get_element(index));
	Trench* new_trench = new Trench(get_all()[index]);
	new_trench->set_quantity(new_quantity);
	if (TrenchValidator().validate(new_trench) == false)
	{
		throw std::exception();
	}
	repository->update_at(index, *new_trench);
}

Vector<Trench> TrenchService::get_all()
{
	return repository->get_all();
}

int TrenchService::search_trench(int size, char colour[], int price)
{
	/// <summary>
	/// Search a trench using given parameters
	/// </summary>
	/// <param name="size"></param>
	/// <param name="colour"></param>
	/// <param name="price"></param>
	/// <returns></returns>
	Vector<Trench> trenches = repository->get_all();
	for (size_t index = 0; index < trenches.get_length(); index++)
	{
		Trench trench = trenches[index];
		if (strcmp(trench.get_color(), colour) == 0 && trench.get_size() == size && trench.get_price() == price)
		{
			return index;
		}
	}
	return -1;
}

void TrenchService::generate_random_trenches(int count)
{
	/// <summary>
	/// Generate random trenches
	/// </summary>
	/// <param name="count">Integer strictly positive</param>
	for (int index = 1; index <= count; index++)
	{
		char color[25];
		char photograph[25];
		sprintf(color, "color%d", index);
		sprintf(photograph, "photograph%d", index);
		//Trench* trench = new Trench(index, index, color, rand() % 30 + 70, photograph);
		Trench trench{ index,index,color,rand() % 30 + 70,photograph };
		repository->add_element(trench);
	}
}

void TrenchService::add_element_in_shopping_basket(Trench &element)
{
	/// <summary>
	/// Add element in shopping basket
	/// </summary>
	/// <param name="element"></param>
	/*Trench* copy = new Trench(element->get_size(), element->get_quantity(), element->get_color(), element->get_price(), element->get_photograph());
	element->set_quantity(element->get_quantity() - 1);*/
	element.set_quantity(element.get_quantity()-1);
	user_repository->add_element(element);
}

Vector<Trench> TrenchService::get_elements_in_shopping_basket()
{
	/// <summary>
	/// Return the elements from shopping basket
	/// </summary>
	/// <returns></returns>
	return user_repository->get_all();
}

