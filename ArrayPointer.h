#pragma once

template <class T>
class ArrayPointer
{

	T* pointer = nullptr;

public:

	ArrayPointer<T>() {}

	// C++ Rule of Five
	ArrayPointer<T>(T* newPointer) { pointer = newPointer; }
	// Destructor
	~ArrayPointer<T>() { delete[] pointer; }

	// Copy Constructor
	ArrayPointer<T>(const ArrayPointer<T>& other) = delete;
	// Move Contructor
	ArrayPointer<T>(ArrayPointer<T>&& other);

	// Copy Assignment operator
	ArrayPointer<T>& operator=(const ArrayPointer& other) = delete;
	// Move Assignment operator
	void operator=(ArrayPointer&& other);

	T& ArrayPointer<T>::operator[](int i);

	T* get();
	T* release();
	void reset();

};

template <class T>
T& ArrayPointer<T>::operator[](int i)
{
	return pointer[i];
}

template <class T>
ArrayPointer<T>::ArrayPointer(ArrayPointer<T>&& other) 
{
	if (this == &other)
		return;

	*this = std::move(other);
	return *this;
}

template <class T>
void ArrayPointer<T>::operator=(ArrayPointer&& other)
{
	if (this == &other)
		return;

	delete[] pointer;
	pointer = other.pointer;
	other.pointer = nullptr;
}

template <class T>
T* ArrayPointer<T>::get()
{
	return pointer;
}

template <class T>
T* ArrayPointer<T>::release()
{
	T* temp = pointer;
	pointer = nullptr;
	return temp;
}

template <class T>
void ArrayPointer<T>::reset()
{
	delete[] pointer;
	pointer = nullptr;
}