#pragma once
#include <iostream>

template<class T>
class Vector
{
private:
	T* vector;
	size_t size;
	size_t capacity;
	void erase();
	void copy(const Vector<T>& other);
	void resize();
public:
	Vector();
	Vector(const Vector<T>& other);
	Vector<T>& operator=(const Vector<T>& other);
	~Vector();
	size_t getSize() const;
	void insert(const T& element, size_t index);
	void add(T element);
	void remove(size_t index);
	void print() const;
	T& operator[](size_t index) const;
	friend std::ostream& operator<<(std::ostream& out, const Vector<T>& vector)
	{
		for (size_t i = 0; i < vector.size; i++)
			out << vector.vector[i] << " ";
		return out;
	}
	friend std::istream& operator>>(std::istream& in, const Vector<T>& vector)
	{
		for (size_t i = 0; i < vector.size; i++)
			in >> vector.vector[i];
		return in;
	}
};

template<class T>
void Vector<T>::erase()
{
	delete[] this->vector;
}

template<class T>
void Vector<T>::copy(const Vector<T>& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->vector = new T[this->capacity];
	for (size_t i = 0; i < this->size; i++)
		this->vector[i] = other.vector[i];
}

template<class T>
void Vector<T>::resize()
{
	this->capacity *= 2;

	T* biggerVector = new T[this->capacity];
	for (size_t i = 0; i < this->size; i++)
		biggerVector[i] = this->vector[i];

	delete[] this->vector;
	this->vector = biggerVector;
}

template<class T>
Vector<T>::Vector()
{
	this->size = 0;
	this->capacity = 10;
	this->vector = new T[this->capacity];
}

template<class T>
Vector<T>::Vector(const Vector<T>& other)
{
	this->copy(other);
}

template<class T>
Vector<T>& Vector<T>::operator=(const Vector<T>& other)
{
	if (this != &other)
	{
		this->erase();
		this->copy(other);
	}
	return *this;
}

template<class T>
Vector<T>::~Vector()
{
	this->erase();
}

template<class T>
size_t Vector<T>::getSize() const
{
	return this->size;
}

template<class T>
void Vector<T>::insert(const T& element, size_t index)
{
	if (this->size >= this->capacity)
		this->resize();

	for (size_t i = this->size; i > index; i--)
		this->vector[i] = this->vector[i - 1];
	
	this->vector[index] = element;
	this->size++;
}

template<class T>
void Vector<T>::add(T element)
{
	if (this->size >= this->capacity)
		this->resize();

	this->vector[this->size++] = element;
}

template<class T>
void Vector<T>::remove(size_t index)
{
	if (index >= this->getSize())
		return;

	T* temp = new T[this->getSize() - 1];
	for (size_t i = index; i < this->getSize(); i++)
		this->vector[i] = this->vector[i + 1];

	for (size_t i = 0; i < this->getSize() - 1; i++)
		temp[i] = this->vector[i];

	delete[] this->vector;
	this->vector = temp;
	this->size--;
}

template<class T>
void Vector<T>::print() const
{
	for (size_t i = 0; i < this->size; ++i)
		std::cout << this->vector[i] << std::endl;
}

template<class T>
T& Vector<T>::operator[](size_t index) const
{
	if (index >= this->getSize())
		return this->vector[this->getSize() - 1];

	return this->vector[index];
}