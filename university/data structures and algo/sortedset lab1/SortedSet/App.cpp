#include "ShortTest.h"
#include "ExtendedTest.h"
#include "SortedSet.h"
#include "SortedSetIterator.h"
#include <iostream>
#include <crtdbg.h>

using namespace std;

int main() {
	testAll();
	test_merge();
	testAllExtended();

	cout << "Test end" << endl;
	cout <<_CrtDumpMemoryLeaks()<<"\n";
	system("pause");
	return 0;
}