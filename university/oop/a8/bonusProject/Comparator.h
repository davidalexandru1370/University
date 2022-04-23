#pragma once
template<class T>
class Comparator
{
public:
	virtual bool compare(T elem1, T elem2) = 0;
};


