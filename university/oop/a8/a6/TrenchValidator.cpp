#include "TrenchValidator.h"

bool TrenchValidator::validate(int size, char colour[], int price, int quantity, char photograph[])
{
	if (size <= 0)
	{
		return false;
	}
	if (strcmp(colour, "") == 0)
	{
		return false;
	}
	if (price < 0)
	{
		return false;
	}
	if (quantity < 0)
	{
		return false;
	}
	if (strcmp(photograph, "") == 0)
	{
		return false;
	}
	return true;
}

bool TrenchValidator::validate(Trench* trench)
{
	if (trench->get_size() <= 0)
	{
		return false;
	}
	if (strcmp(trench->get_color(), "") == 0)
	{
		return false;
	}
	if (trench->get_price() < 0)
	{
		return false;
	}
	if (trench->get_quantity() < 0)
	{
		return false;
	}
	if (strcmp(trench->get_photograph(), "") == 0)
	{
		return false;
	}
	return true;
}
