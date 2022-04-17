#include "TrenchValidator.h"
#include <exception>
#include <string>



bool TrenchValidator::validate(int size, char colour[], int price, int quantity, char photograph[])
{
	string message;
	if (size <= 0)
	{
		throw TrenchValidatorException("Invalid size\n");
	}
	if (strcmp(colour, "") == 0)
	{
		throw TrenchValidatorException("Invalid color\n");
	}
	if (price < 0)
	{
		throw TrenchValidatorException("Invalid price\n");
	}
	if (quantity < 0)
	{
		throw TrenchValidatorException("Invalid quantity\n");
	}
	if (strcmp(photograph, "") == 0)
	{
		throw TrenchValidatorException("Invalid photograph");
	}
	return true;
}

bool TrenchValidator::validate(Trench* trench)
{
	if (trench->get_size() <= 0)
	{
		throw TrenchValidatorException("Invalid size\n");
	}
	if (strcmp(trench->get_color(), "") == 0)
	{
		throw TrenchValidatorException("Invalid color\n");
	}
	if (trench->get_price() < 0)
	{
		throw TrenchValidatorException("Invalid price!\n");
	}
	if (trench->get_quantity() < 0)
	{
		throw TrenchValidatorException("Invalid quantity\n");
	}
	if (strcmp(trench->get_photograph(), "") == 0)
	{
		throw TrenchValidatorException("Invalid photograph!\n");
	}
	return true;
}

TrenchValidatorException::TrenchValidatorException(std::string error) : message{ error } {}

const char* TrenchValidatorException::what() const noexcept
{
	return message.c_str();
}
