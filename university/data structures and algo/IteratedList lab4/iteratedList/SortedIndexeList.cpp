#include "ListIterator.h"
#include "SortedIndexedList.h"
#include <iostream>
using namespace std;
#include <exception>

SortedIndexedList::SortedIndexedList(Relation r) {
	//TODO - Implementation
	length = 0;
	relation = r;
	head = nullptr;
	//head = new SLLNode();
}

int SortedIndexedList::size() const {
	//TODO - Implementation
	return length;
}

bool SortedIndexedList::isEmpty() const {
	//TODO - Implementation
	return length == 0;
}

TComp SortedIndexedList::getElement(int i) const {
	//TODO - Implementation
	if (i >= length)
	{
		throw std::exception();
	}
	SLLNode* result = head;

	while (i--)
	{
		result = result->get_next();
	}

	return result->get_value();
}

TComp SortedIndexedList::remove(int i) {
	//TODO - Implementation
	//return NULL_TCOMP;
	if (i >= length)
	{
		throw exception();
	}
	
	int index = 0;
	SLLNode* previous = head;
	while (index < (i - 1))
	{
		previous = previous->get_next();
	}
	this->length--;
	TComp saved;
	if (previous->get_next() == nullptr)
	{//last element
		previous->set_next(nullptr);
		saved = previous->get_value(); // ?
	}//first element
	if (previous==head)
	{
		saved = previous->get_value();
		previous->set_next(previous->get_next());
	}//between elements
	else {
		saved = previous->get_next()->get_value();
		previous->get_next()->set_next(nullptr);
		previous->set_next(previous->get_next()->get_next());
	}
	return saved;

	
}

int SortedIndexedList::search(TComp e) const {
	//TODO - Implementation
	int index = 0;
	SLLNode* result = head;
	while (result != nullptr)
	{
		if (result->get_value() == e)
		{
			return index;
		}
		result = result->get_next();
		index++;
	}
	return -1;
}

void SortedIndexedList::add(TComp e) {
	//TODO - Implementation
	SLLNode* position = head;
	SLLNode* prev = nullptr;
	this->length++;

	if (position!=nullptr && relation(position->get_value(),e)==false)
	{
		SLLNode* new_node = new SLLNode(e, position);
		head = new_node;
		return;
	}

	while (position != nullptr && relation(position->get_value(), e))
	{
		prev = position;
		position = position->get_next();
	}
	if (position == nullptr)
	{
		//beginning of the list
		if (prev == nullptr)
		{
			SLLNode* new_node = new SLLNode(e, position);
			head = new_node;
		}
		else 
		{   //final of the list
			SLLNode* new_node = new SLLNode(e, nullptr);
			prev->set_next(new_node);
		}
	}
	else { //between elements of the list
		SLLNode* new_node = new SLLNode(e, position);
		prev->set_next(new_node);
	}
}

ListIterator SortedIndexedList::iterator() {
	return ListIterator(*this);
}

//destructor
SortedIndexedList::~SortedIndexedList() {
	//TODO - Implementation
}
