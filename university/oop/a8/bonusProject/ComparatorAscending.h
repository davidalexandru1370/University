#pragma once
#include "Comparator.h"
template<class T>
class ComparatorAscending : public Comparator<T> 
{
public:
	bool compare(T elem1, T elem2) override;
};

template<class T>
inline bool ComparatorAscending<T>::compare(T elem1, T elem2)
{
	return elem1 > elem2;
}
