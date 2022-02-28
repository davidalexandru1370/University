#pragma once
typedef struct 
{
	int dimension;
}PascalTriangle;

PascalTriangle createPascalTriangle(int dimension);
/*
Constructor for struct PascalTriangle
params:
dimension-integer strictly positive representing the number of rows of triangle
return:
A valid pascal triangle if the input is correct
*/
void printPascalTriangle(PascalTriangle triangle);
/*
Calculate and print the pascal triangle given as parameter
params:
triangle - PascalTriangle struct with validated paremeter dimension(strictly positive than 0)
*/
void testPascalTriangle();
/*
Tests
*/
