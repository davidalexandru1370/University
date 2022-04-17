#pragma once
#include <string>
#include "Trench.h"
class TrenchValidatorException : public std::exception {
private:
	std::string message;

public:
	TrenchValidatorException(std::string error);
	const char* what() const noexcept override;
	

};
class TrenchValidator
{
public:
	static bool validate(int size, char colour[], int price, int quantity, char photograph[]);
	static bool validate(Trench* trench);
};

