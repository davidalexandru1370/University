#include "SortedSetIterator.h"
#include <exception>

using namespace std;

SortedSetIterator::SortedSetIterator(const SortedSet& m) : multime(m)
{
	current_index = 0;
	//TODO - Implementation
}


void SortedSetIterator::first() {
	current_index = 0;
	//TODO - Implementation
}


void SortedSetIterator::next() {
	if (current_index >= multime.number_of_elements)
	{
		throw std::exception();
	}
	current_index++;
	//TODO - Implementation
}


TElem SortedSetIterator::getCurrent()
{
	//TODO - Implementation
	if (current_index >= multime.number_of_elements)
	{
		throw std::exception();
	}
	return multime.elements[current_index];
	//return NULL_TELEM;
}

bool SortedSetIterator::valid() const {
	//TODO - Implementation
	if (current_index >= 0 && current_index < multime.number_of_elements)
	{
		return true;
	}
	return false;
}

