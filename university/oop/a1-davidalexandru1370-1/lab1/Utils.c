#include "Utils.h"
#include <assert.h>
int is_prime(int number)
{
	if (number <= 1)
	{
		return 0;
	}
	if (number == 2 || number == 3)
	{
		return 1;
	}
	if (number % 2 == 0 || number % 3 == 0)
	{
		return 0;
	}
	for (int index = 5; index * index <= number; index += 2)
	{
		if (number % index == 0)
		{
			return 0;
		}
	}
	return 1;
}

Util getLongestContigousPrimeSubsequence(int* vector, int size)
{
	int start, stop;
	start = stop = -1;
	int max_length = -1;
	Util result;
	int exists = 0;
	for (int index = 0; index < size; index++)
	{
		if (is_prime(vector[index]) == 1)
		{
			start = index;
			while (index < size && is_prime(vector[index]) == 1)
			{
				index += 1;
			}
			stop = index;

			if ((stop - start) > max_length)
			{
				result.result[0] = start;
				result.result[1] = stop-1;
				exists = 1;
				max_length = stop - start;
			}

			if ((stop - start) > 1)
			{
				index--;
			}

		}
	}

	if (exists == 1)
	{
		return result;
	}

	result.result[0] = -1;
	result.result[1] = -1;
	return result;
}

void testUtils()
{
	assert(is_prime(2) == 1);
	assert(is_prime(3) == 1);
	assert(is_prime(4) == 0);
	assert(is_prime(-2) == 0);
	assert(is_prime(25) == 0);
	assert(is_prime(36) == 0);
	assert(is_prime(0) == 0);
	assert(is_prime(7) == 1);
	assert(is_prime(5) == 1);
	int v[] = { 1,3,11,7,5,2,4,6,7,2,-2,9,8,3,5,7 };
	assert(getLongestContigousPrimeSubsequence(v,sizeof(v)/sizeof(v[0])).result[0]==1);
	assert(getLongestContigousPrimeSubsequence(v,sizeof(v)/sizeof(v[0])).result[1]==5);
	int v2[] = { 4,6,8 };
	assert(getLongestContigousPrimeSubsequence(v2, sizeof(v2) / sizeof(v2[0])).result[0] == -1);
	assert(getLongestContigousPrimeSubsequence(v2, sizeof(v2) / sizeof(v2[0])).result[1] == -1);
}