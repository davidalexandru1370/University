#include "Utils.h"
#include <stdio.h>
int Utils::convert_char_to_integer(const char _string[])
{
	/// <summary>
	/// Convert a char to integer 
	/// </summary>
	/// <param name="_string">char array</param>
	/// <returns></returns>
	int minus = 1;
	if (strlen(_string) == 0)
	{
		return 0;
	}
	int number = 0;
	int index = 0;
	if (_string[0] == '-')
	{
		if (!isdigit(_string[1]))
		{
			throw std::exception();
		}
		minus = -1;
		index = 1;
	}
	for (; index < strlen(_string)-1; index++)
	{
		
		if (_string[index] < '0' || _string[index]>'9')
		{
			throw std::exception();
		}
		number = number * 10 + (int)_string[index] - '0';
	}
	return number * minus;


}
