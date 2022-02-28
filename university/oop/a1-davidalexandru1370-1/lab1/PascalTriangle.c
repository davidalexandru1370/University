#include "PascalTriangle.h"
#include <stdio.h>
PascalTriangle createPascalTriangle(int dimension)
{
	PascalTriangle p;
	p.dimension = dimension;
	return p;
}

void printPascalTriangle(PascalTriangle triangle)
{
	int line[100];
	int previous_line[100];
	for (int counter = 0; counter < triangle.dimension; counter++)
	{
		for (int index = 0; index <= counter; index++)
		{
			if (index == 0 || index == counter)
			{
				line[index] = 1;
			}
			else
			{
				line[index] = previous_line[index - 1] + previous_line[index];
			}
			printf("%d ", line[index]);
		}
		printf("%s", "\n");
		for (int index = 0; index <= counter; index++)
		{
			previous_line[index] = line[index];
		}

	}
}