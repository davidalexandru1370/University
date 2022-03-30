#pragma once
#include <iterator>
#include <exception>
template <typename T>
class DynamicVector {
private:
	T* elems;
	int size;
	int capacity;
public:
	DynamicVector(int capacity = 10);
	DynamicVector(const DynamicVector<T>& v);
	~DynamicVector();
	DynamicVector& operator=(const DynamicVector& v);
	T& operator[](int index);
	void add(const T& elem);
	int getSize() const;
	void resize();
	T* begin();
	T* end();
public:
	class iterator {
	private:
		T* pointer;
	public:
		iterator(T* _pointer);
		void operator++();
		T& operator*();
		iterator& operator=(T* val);
	};
};

template<typename T>
DynamicVector<T>::DynamicVector(int capacity)
{
	this->elems = new T[capacity];
	this->capacity = capacity;
	this->size = 0;
}

template<typename T>
inline DynamicVector<T>::DynamicVector(const DynamicVector<T>& v)
{
	size = v.size;
	capacity = v.capacity;
	elems = new T[capacity];
	for (size_t i = 0; i < size; i++)
	{
		elems[i] = v.elems[i];
	}
}

template<typename T>
DynamicVector<T>::~DynamicVector()
{
	delete[]this->elems;
}

template<typename T>
DynamicVector<T>& DynamicVector<T>::operator=(const DynamicVector& v)
{
	size = v.size;
	capacity = v.capacity;
	for (int index = 0; index < v.size; index++)
	{
		elems[index] = v.elems[index];
	}
	return *this;
	// TODO: insert return statement here
}



template<typename T>
T& DynamicVector<T>::operator[](int index)
{
	// TODO: insert return statement here
	if (index < 0 || index >= size)
	{
		throw std::exception();
	}
	return elems[index];
}

template<typename T>
void DynamicVector<T>::add(const T& elem)
{
	if (this->size == this->capacity)
	{
		this->resize();
	}
	this->elems[this->size++] = elem;
}

template<typename T>
int DynamicVector<T>::getSize() const
{
	return this->size;
}

template<typename T>
void DynamicVector<T>::resize()
{
	this->capacity *= 2;

	T* elems = new T[this->capacity];
	for (int i = 0; i < this->size; i++)
	{
		elems[i] = this->elems[i];
	}

	delete[]this->elems;
	this->elems = elems;
}

template<typename T>
inline T* DynamicVector<T>::begin()
{
	if (size > 0)
	{
		throw std::exception();
	}
	return elems;
}

template<typename T>
inline T* DynamicVector<T>::end()
{
	return elems + size;
}

template<typename T>
inline DynamicVector<T>::iterator::iterator(T* _pointer)
{
	pointer = _pointer;
}

template<typename T>
void DynamicVector<T>::iterator::operator++()
{
	pointer++;
}

template<typename T>
inline T& DynamicVector<T>::iterator::operator*()
{
	return *pointer;
	// TODO: insert return statement here
}




