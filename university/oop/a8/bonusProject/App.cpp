#include "genericSort.h"
#include "ComparatorAscending.h"
#include "ComparatorDesceding.h"
#include "Comparator.h"
#include <assert.h>
#include <vector>
#include <iostream>
using namespace std;

int main() {
	vector<int>v;
	v.push_back(5);
	v.push_back(9);
	v.push_back(7);
	v.push_back(6);
	v.push_back(10);
	genericSort<int> g;
	ComparatorAscending<int> asc;
	ComparatorDesceding<int> desc;
	g.sort(v, asc);
	
	assert(v[0] == 5);
	assert(v[1] == 6);
	assert(v[2] == 7);
	assert(v[3] == 9);
	assert(v[4] == 10);

	g.sort(v, desc);
	
	assert(v[0] == 10);
	assert(v[1] == 9);
	assert(v[2] == 7);
	assert(v[3] == 6);
	assert(v[4] == 5);

	/*for (size_t i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}*/


	return 0;
}