#include "Console.h"
#include <stdio.h>
#include <string.h>
#include "PascalTriangle.h"
#include "Utils.h"

void start_console()
{
	while (1)
	{
		print_menu();
		char choice[10];
		fseek(stdin, 0, SEEK_END);
		printf("Your choose = ");
		gets_s(choice, 10);
		char option_one[] = "1";
		char option_two[] = "2";
		if (strcmp(choice, option_one) == 0 || strcmp(choice, option_two) == 0)
		{
			int option = (int)choice[0] - '0';
			if (option == 1)
			{
				int pascal_triangle_dimension;
				printf("Pascal triangle dimension = ");
				scanf("%d", &pascal_triangle_dimension);
				PascalTriangle p = createPascalTriangle(pascal_triangle_dimension);
				printPascalTriangle(p);
				printf("\n");
			}
			else if (option == 2)
			{
				int dimension = 100;
				int vector[100];
				//memset(*vector, *vector + dimension, 0);
				int vector_length;
				printf("Enter array dimension=");
				scanf("%d", &vector_length);
				for (int index = 0; index < vector_length; index++)
				{
					scanf("%d", &vector[index]);
				}
				//Util result = getLongestContigousPrimeSubsequence(vector, sizeof(vector) / sizeof(vector[0]));
				Util result = getLongestContigousPrimeSubsequence(vector, vector_length);
				for (int index = result.result[0]; index <= result.result[1]; index++)
				{
					printf("%d ", vector[index]);
				}
				printf("\n");
			}
		}
		else
		{
			printf("Invalid menu!\n");
		}
	}
}

void print_menu()
{
	printf("Press 1 to get the pascal triangle of dimension n\n");
	printf("Press 2 to get the longest contigous subsequence of prime numbersn\n");
}

Console createConsole()
{
	Console console;
	console.a = 0;
	return console;
}