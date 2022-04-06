#pragma once
#include <exception>
#include "Trench.h"
template <typename TElem>
class Vector
{
public:
	Vector(int _size);
	Vector(const Vector& v);
	~Vector();
	int get_length();
	int get_size();
	//TElem get_element(int index);
	void push_back(TElem element);
	void remove_at(int index);
	//TElem& operator[](int);
	Vector& operator= (const Vector& rhs_vector);
	TElem& operator[](const int position);
private:
	TElem* elements;
	int length;
	int size;

	void resize();
	bool check_index(int index);
};

template<typename TElem>
Vector<TElem>::Vector(int _size)
{
	this->size = _size;
	this->length = 0;
	this->elements = new TElem[_size];
}

template<typename TElem>
inline Vector<TElem>::Vector(const Vector& v)
{
	this->elements = new TElem[v.size];
	this->size = v.size;
	this->length = v.length;
	for (size_t index = 0; index < length; index++)
	{
		this->elements[index] = v.elements[index];
	}
}

template<typename TElem>
inline Vector<TElem>::~Vector()
{
	delete[] this->elements;
}

template<typename TElem>
inline int Vector<TElem>::get_length()
{
	return length;
}

template<typename TElem>
inline int Vector<TElem>::get_size()
{
	return size;
}

template<typename TElem>
inline void Vector<TElem>::push_back(TElem element)
{
	if (this->size == this->length)
	{
		this->resize();
	}
	this->elements[this->length] = element;
	this->length++;
}

template<typename TElem>
inline void Vector<TElem>::remove_at(int index)
{
	if (check_index(index))
	{
		for (size_t i = index; i < this->length - 1; i++)
		{
			this->elements[i] = this->elements[i + 1];
		}
		this->length--;
	}
}

template<typename TElem>
inline Vector<TElem>& Vector<TElem>::operator=(const Vector& rhs_vector)
{
	this->size = rhs_vector.size;
	this->length = rhs_vector.length;
	delete[]this->elements;

	this->elements = new TElem[rhs_vector.size];
	for (size_t index = 0; index < rhs_vector.length; index++)
	{
		this->elements[index] = rhs_vector.elements[index];
	}

	return *this;
	// TODO: insert return statement here
}

template<typename TElem>
inline TElem& Vector<TElem>::operator[](const int position)
{
	// TODO: insert return statement here
	if (check_index(position))
	{
		return this->elements[position];
	}
	throw std::exception();
}

template<typename TElem>
inline void Vector<TElem>::resize()
{
	this->size *= 2;
	TElem* new_elements = new TElem[this->size];
	for (size_t index = 0; index < this->length; index++)
	{
		new_elements[index] = this->elements[index];
	}
	delete[] this->elements;
	this->elements = new_elements;
}

template<typename TElem>
inline bool Vector<TElem>::check_index(int index)
{
	return (index >= 0 && index < this->length);
}
