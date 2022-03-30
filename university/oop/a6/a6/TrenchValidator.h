#pragma once
#include <string>
#include "Trench.h"
class TrenchValidator
{
public:
	static bool validate(int size, char colour[], int price, int quantity, char photograph[]);
	static bool validate(Trench* trench);
};

