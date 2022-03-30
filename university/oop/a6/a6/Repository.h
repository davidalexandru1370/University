#pragma once
#include "Vector.h"
#include "Trench.h"

class Repository
{
protected:
	Vector<Trench> data{ 1 };
	virtual int check_if_element_exists(Trench &element) = 0;
private:
	bool check_if_index_belongs(int index);
public:
	Repository(int);
	virtual void add_element(Trench element);
	void remove_at(int index);
	void update_at(int index, Trench new_element);
	Vector<Trench> get_all();
};

