#pragma once
#include <vector>
#include <algorithm>
#include "Comparator.h"
#include "ComparatorAscending.h"
template <class T>
class genericSort
{
public:
	void sort(std::vector<T> &elements, Comparator<T> &c);
};

template<class T>
inline void genericSort<T>::sort(std::vector<T> &elements, Comparator<T> &c)
{
	for (size_t i = 0; i < elements.size(); i++)
	{
		for (size_t j = i+1; j < elements.size(); j++)
		{
			if (c.compare(elements[i],elements[j]))
			{
				std::swap(elements[i], elements[j]);
			}
		}
	}
}


