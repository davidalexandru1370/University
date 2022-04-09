#include "TrenchValidator.h"
#include <exception>
class TrenchValidatorException : public std::exception {
private:
	char* msg;

public:
	TrenchValidatorException(const char _msg[]) {
		msg = new char[strlen(_msg)];
		strcpy(msg, _msg);
	}
	const char* what() const throw ()
	{
		return msg;
	}
};


bool TrenchValidator::validate(int size, char colour[], int price, int quantity, char photograph[])
{
	if (size <= 0)
	{
		throw TrenchValidatorException("Invalid size");
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
