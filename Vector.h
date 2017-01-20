#pragma once

#include <string>
#include <algorithm>
#include "ArrayPointer.h"

template <class T>
class Vector
{
	ArrayPointer<T> internalArray;
	size_t internalSize = 0;
	size_t maxSize = 0;
	

public:
	T& operator[](size_t i);
	T at(size_t i);
	T front();
	T back();
	size_t capacity();
	void push_back(T data);
	void pop_back();
	//void insert(typename Vector<T>::iterator it, T data);
	//void erase(typename Vector<T>::iterator it);
	void resize(size_t newSize);
	void reserve(size_t reserveSize);
	void shrink_to_fit();
	void print();

	// Default Contructor
	Vector<T>() {}

	// C++ Rule of Five
	// Destructor
	~Vector<T>() {}

	// Copy Constructor
	Vector<T>(const Vector<T>& other);
	// Move Contructor
	Vector<T>(Vector<T>&& other);

	// Copy Assignment operator
	Vector<T>& operator=(const Vector<T>& other);
	// Move Assignment operator
	Vector<T>& operator=(Vector<T>&& other);
};

template <class T>
Vector<T>::Vector(const Vector<T>& other) 
{
	if (this == &other)
		return;

	internalSize = other.internalSize;
	maxSize = other.maxSize;

	internalArray = new T[maxSize];
	for (size_t i = 0; i < internalSize; i++)
		internalArray[i] = other.internalArray[i];
}

template <class T>
Vector<T>::Vector(Vector<T>&& other) 
{
	if (this == &other)
		return;

	*this = std::move(other);
	return *this;
}

template <class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this == &other)
		return;

	Vector<T> temporary(other);
	*this = std::move(temporary);
	return *this;
}

template <class T>
Vector<T>& Vector<T>::operator=(Vector<T>&& other) 
{
	if (this == &other)
		return;

	internalSize = other.internalSize;
	maxSize = other.maxSize;

	internalArray.pointer = other.internalArray.pointer;

	other.internalSize = 0;
	other.maxSize = 0;
	other.internalArray = nullptr;

	return *this;
}

template <class T>
T& Vector<T>::operator[](size_t i)
{
	return internalArray[i];
}

template <class T>
T Vector<T>::at(size_t i)
{
	if (i > internalSize - 1) throw std::out_of_range("Out of range error");
	return internalArray[i];
}

template <class T>
T Vector<T>::front()
{
		if(internalSize > 0) return internalArray[0];
}

template <class T>
T Vector<T>::back()
{
	if (internalSize > 0) return internalArray[internalSize-1];

}

template <class T>
size_t Vector<T>::capacity()
{
	return maxSize;
}

template <class T>

void Vector<T>::push_back(T data)
{
	if (internalSize == maxSize)
		reserve(maxSize * 2 + 1);

	internalArray[internalSize] = data;
	internalSize++;
}

template <class T>
void Vector<T>::pop_back()
{
	if(internalSize > 0) internalSize--;
}

template <class T>
void Vector<T>::print()
{
	std::cout << '{';
	for (size_t i = 0; i < internalSize; ++i)
	{
		std::cout << internalArray[i];

		if (i != internalSize - 1)
			std::cout << ", ";
	}
	std::cout << '}' << std::endl;
}

/*template <class T>
void Vector<T>::insert(Vector<T>::iterator it, T data)
{

}

template <class T>
void Vector<T>::erase(typename Vector<T>::iterator it)
{

}*/

template <class T>
void Vector<T>::resize(size_t size)
{
	T *newArray = new T[size];
	auto copySize = std::min(size, internalSize);

	for (size_t i = 0; i < copySize; i++)
		newArray[i] = internalArray[i];

	if (size > maxSize)
	{
		for (size_t i = copySize; i < size; i++)
			newArray[i] = T();
	}

	maxSize = internalSize = size;
    internalArray = newArray;
}

template <class T>
void Vector<T>::reserve(size_t reserveSize)
{
	if (reserveSize < maxSize)
		return;

	internalSize = std::min(reserveSize, internalSize);
	T *newArray = new T[reserveSize];

	for (size_t i = 0; i < internalSize; ++i)
		newArray[i] = internalArray[i];

	maxSize = reserveSize;
	internalArray = newArray;
}

template <class T>
void Vector<T>::shrink_to_fit()
{
	resize(internalSize);
}