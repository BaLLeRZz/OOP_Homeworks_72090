#pragma once
#include "Vector.h"
template<class T>
struct SmartFunc
{
	T (*mapPtr)(T element) = nullptr;
	bool (*filterPtr)(T element) = nullptr;
	T(*reducePtr)(Vector<T> vec) = nullptr;

	void setMap(T map(T element));
	void setFilter(bool filter(T element));
	void setReduce(T reduce(Vector<T> vec));

	void useMap(Vector<T>& vec);
	void useFilter(Vector<T>& vec);
	void useReduce(Vector<T>& vec);

	void useFilterWithMap(Vector<T>& vec);
	void useFilterWithReduce(Vector<T>& vec);
	void useMapWithReduce(Vector<T>& vec);
};

template<class T>
void SmartFunc<T>::setMap(T map(T element))
{
	this->mapPtr = map;
}

template<class T>
void SmartFunc<T>::setFilter(bool filter(T element))
{
	this->filterPtr = filter;
}

template<class T>
void SmartFunc<T>::setReduce(T reduce(Vector<T> vec))
{
	this->reducePtr = reduce;
}

template<class T>
void SmartFunc<T>::useMap(Vector<T>& vec)
{
	if (!this->mapPtr)
		return;

	for (size_t i = 0; i < vec.getSize(); i++) 
		vec[i] = this->mapPtr(vec[i]);
}

template<class T>
void SmartFunc<T>::useFilter(Vector<T>& vec)
{
	if (!this->filterPtr)
		return;

	for (size_t i = 0; i < vec.getSize(); i++)
		if (!this->filterPtr(vec[i]))
		{
			vec.remove(i);
			i--;
		}
}

template<class T>
void SmartFunc<T>::useReduce(Vector<T>& vec)
{
	if (!this->reducePtr)
		return;

	std::cout << this->reducePtr(vec) << std::endl;
}

template<class T>
void SmartFunc<T>::useFilterWithMap(Vector<T>& vec)
{
	if (!this->filterPtr || !this->mapPtr)
		return;

	this->useFilter(vec);
	this->useMap(vec);
}

template<class T>
void SmartFunc<T>::useFilterWithReduce(Vector<T>& vec)
{
	if (!this->filterPtr || !this->reducePtr)
		return;

	this->useFilter(vec);
	this->useReduce(vec);
}

template<class T>
void SmartFunc<T>::useMapWithReduce(Vector<T>& vec)
{
	if (!this->mapPtr || !this->reducePtr)
		return;

	this->useMap(vec);
	this->useReduce(vec);
}