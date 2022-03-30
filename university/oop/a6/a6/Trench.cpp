#include "Trench.h"
#include <string>
#include <iostream>

Trench::Trench() = default;

Trench::Trench(int _size, int _quantity, char _color[], int _price, char _photograph[])
{
	/// <summary>
	/// Trench constructor
	/// </summary>
	/// <param name="_size">integer strictly positive </param>
	/// <param name="_quantity">integer strictly positive</param>
	/// <param name="_color">char not empty</param>
	/// <param name="_price">integer strictly positive </param>
	/// <param name="_photograph">char not empty</param>
	/// <returns></returns>
	size = _size;
	quantity = _quantity;
	price = _price;
	color = new char[strlen(_color) + 1];
	strcpy(color, _color);
	photograph = new char[strlen(_photograph) + 1];
	strcpy(photograph, _photograph);
}

Trench::Trench(const Trench& trench)
{
	/// <summary>
	/// Copy constructor for trench 
	/// </summary>
	/// <param name="trench">trench to be copied</param>
	/// <returns></returns>
	size = trench.size;
	quantity = trench.quantity;
	price = trench.price;
	color = new char[strlen(trench.color) + 1];
	strcpy(color, trench.color);
	photograph = new char[strlen(trench.photograph) + 1];
	strcpy(photograph, trench.photograph);
}

Trench::~Trench()
{

	/*delete[] photograph;
	delete[] color;*/
}

int Trench::get_size()
{
	/// <summary>
	/// Return the size of the trench
	/// </summary>
	/// <returns></returns>
	return size;
}

int Trench::get_quantity()
{
	/// <summary>
	/// Getter for trench quantity
	/// </summary>
	/// <returns></returns>
	return quantity;
}

char* Trench::get_color()
{
	/// <summary>
	/// Getter for trench color
	/// </summary>
	/// <returns></returns>
	return color;
}

int Trench::get_price()
{
	/// <summary>
	/// Getter for trench price
	/// </summary>
	/// <returns></returns>
	return price;
}

char* Trench::get_photograph()
{
	/// <summary>
	/// Getter for trench photograph
	/// </summary>
	/// <returns></returns>
	return photograph;
}

void Trench::set_size(int value)
{
	/// <summary>
	/// Setter for trench size
	/// </summary>
	/// <param name="value"></param>
	size = value;
}

void Trench::set_quantity(int value)
{
	/// <summary>
	/// Setter for trench quantity
	/// </summary>
	/// <param name="value"></param>
	quantity = value;
}

void Trench::set_color(char value[])
{
	/// <summary>
	/// Setter for trench color
	/// </summary>
	/// <param name="value"></param>
	color = new char[strlen(value) + 1];
	strcpy(color, value);
}

void Trench::set_price(int value)
{
	/// <summary>
	/// Setter for trench price
	/// </summary>
	/// <param name="value">integer strictly positive</param>
	price = value;
}

void Trench::set_photograph(char value[])
{
	/// <summary>
	/// Setter for trench photograph
	/// </summary>
	/// <param name="value">char array not empty</param>
	photograph = new char[strlen(value) + 1];
	strcpy(photograph, value);
}

bool Trench::operator==(const Trench& trench) const
{
	if (size == trench.size && strcmp(color, trench.color) == 0)
	{
		return true;
	}
	return false;
}

Trench Trench::operator=(const Trench& trench) 
{
	size = trench.size;
	quantity = trench.quantity;
	color = trench.color;
	price = trench.price;
	//strcpy(photograph, trench.photograph);
	photograph = trench.photograph;
	return Trench{ trench.size, trench.quantity, trench.color, trench.price, trench.photograph };
}

Trench Trench::operator+(const Trench& trench)
{
	quantity += trench.quantity;
	return *this;
}
