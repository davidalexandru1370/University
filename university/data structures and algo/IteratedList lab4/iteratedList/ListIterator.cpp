#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>

using namespace std;

ListIterator::ListIterator(const SortedIndexedList& list) : list(list) {
	pos = 0;
	//TODO - Implementation
}

void ListIterator::first(){
	pos = 0;
	//TODO - Implementation
}

void ListIterator::next(){
	if (valid()==false)
	{
		throw exception();
	}
	pos++;
	//TODO - Implementation
}

bool ListIterator::valid() const{
	//TODO - Implementation
	return pos >= list.length ? false : true;
}

TComp ListIterator::getCurrent() const{
	//TODO - Implementation
	//return NULL_TCOMP;
	if (pos>=list.length)
	{
		throw std::exception();
	}
	return list.getElement(pos);
}


