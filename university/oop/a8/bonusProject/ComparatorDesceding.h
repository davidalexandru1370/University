#pragma once
#include "Comparator.h"
template <class T>
class ComparatorDesceding : public Comparator<T>
{
public:
	bool compare(T elem1, T elem2) override;
};

template<class T>
inline bool ComparatorDesceding<T>::compare(T elem1, T elem2)
{
	return elem1 < elem2;
}
