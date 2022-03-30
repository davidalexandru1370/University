#include "SortedSet.h"
#include "SortedSetIterator.h"

SortedSet::SortedSet(Relation r) {
	capacity = 1;
	elements = new TComp[capacity];
	number_of_elements = 0;
	relation = r;
	//TODO - Implementation
}

bool SortedSet::add(TComp elem) {
	//TODO - Implementation
	if (search(elem) == true)
	{
		return false;
	}
	//1 2 3 
	//4
	//resize
	if (capacity == number_of_elements)
	{
		capacity *= 2;
		TComp* new_elements = new TComp[capacity];
		for (size_t index = 0; index < number_of_elements; index++)
		{
			new_elements[index] = elements[index];
		}
		delete[] elements;
		elements = new_elements;
	}

	int position = 0;

	for (size_t index = 0; index < number_of_elements; index++)
	{
		if (relation(elements[index], elem))
		{
			position=index+1;
		}
		else {
			break;
		}
	}

	for (int index = number_of_elements; index > position; index--)
	{
		elements[index] = elements[index - 1];
	}
	elements[position] = elem;
	number_of_elements++;
	return true;
}

bool SortedSet::remove(TComp elem) {
	//TODO - Implementation
	if (search(elem) == false)
	{
		return false;
	}
	bool found_element = false;

	for (size_t index = 0; index < number_of_elements; index++)
	{
		if (elements[index] == elem)
		{
			found_element = true;
		}
		if (found_element == true)
		{
			elements[index] = elements[index + 1];
		}
	}
	if (found_element == true)
	{
		number_of_elements--;
	}
	return true;
}

bool SortedSet::search(TComp elem) const {
	int left = 0;
	int right = number_of_elements;
	int middle;
	while (left <= right)
	{
		middle = (left + right) / 2;
		if (elements[middle] == elem)
		{
			return true;
		}
		 if (relation(elements[middle], elem))
		{
			left = middle+1;
		}
		else {
			right = middle-1;
		}
	}
	return false;
}

int SortedSet::size() const {
	//TODO - Implementation
	return number_of_elements;
}

bool SortedSet::isEmpty() const {
	return number_of_elements == 0;
}

SortedSetIterator SortedSet::iterator() const {
	return SortedSetIterator(*this);
}

void SortedSet::merge(const SortedSet& s)
{
	//Worst Case O(n*m), n the size of s
	//1 3 5
	//2 4
	//Best case - Theta(N*M) 
	//Average case - Theta(n)
	//Total case - Theta(n)
	//naive sol - iterate through s items and add item into 
	//
	SortedSetIterator it1 = s.iterator();
	it1.first();
	while (it1.valid())
	{
		TComp e = it1.getCurrent();
		add(e);
		it1.next();
	}
}

SortedSet::~SortedSet() {
	//TODO - Implementation
	delete[] elements;
}


