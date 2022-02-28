#pragma once
typedef struct Utils
{
	int result[2];
}Util;

int is_prime(int number);
/*
Check if a number is prime in O(sqrt(n))
parameters:
number - integer strictly positive representing the number to find if is prime
return:
1 - if the number is prime
0 - if the number is not prime
*/
Util getLongestContigousPrimeSubsequence(int vector[], int size);
/*
Get the longest contigous prime subsequence;
parameters:
vector - the array of numbers not empty
size - the size of the array
return:
Util struct with result[0]= the starting position in vector of the longest contigous prime subsequence;
and result[1]= the end position in vector of the longest contigous prime subsequence if exists such an subsequence
else result[0]=result[1]=-1
*/
void testUtils();