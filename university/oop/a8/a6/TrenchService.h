#pragma once
#include "Vector.h"
#include "Repository.h"
#include "Trench.h"
#include "UserRepository.h"
#include "TrenchRepository.h"
#include "TrenchFileRepository.h"
#include "UserFileRepository.h"
class TrenchService
{
private:
	TrenchFileRepository* repository;
	UserFileRepository* user_repository;
public:
	TrenchService(TrenchFileRepository* _repository, UserFileRepository* _user_repository);
	//TrenchService(TrenchRepository* _repository, UserRepository* _user_repository);
	~TrenchService();
	void add_element(int size, char colour[], int price, int quantity, char photograph[]);
	void delete_element(int index);
	void update_element(int index, int new_quantity);
	std::vector<Trench> get_all();
	int search_trench(int size, char colour[], int price);
	void generate_random_trenches(int count);
	void add_element_in_shopping_basket(Trench &element);
	std::vector<Trench> get_elements_in_shopping_basket();
};

