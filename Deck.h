#pragma once
#include"String.h"
#include<cassert>

template<class T>
class Deck
{
private:
	T cards[30];
	size_t size;
public:
	Deck();
	void isValid();
	void shuffle();
	T drawCard();
	void addCard(const T& other);
	Deck operator+(const T& other);
	Deck& operator+=(const T& other);
};

template<class T>
Deck<T>::Deck()
{
	this->size = 0
	this->cards[this->size] = nullptr;
}

template<class T>
void Deck<T>::isValid()
{
	for (size_t i = 0; i < this->size; i++)
	{
		for (size_t j = i; j < this->size; j++)
		{
			assert(this->cards[i].name != this->cards[j].name);
		}
	}
}

template<class T>
T Deck<T>::drawCard()
{
	T temp = this->cards[0];
	for (size_t i = 0; i < this->size; i++)
		this->cards[i] = this->cards[i + 1];
	this->cards[this->size] = temp;
	return temp;
}

template<class T>
void Deck<T>::addCard(const T& other)
{
	if (this->size == 30)
		return;

	this->cards[this->size++] = other;
}

template<class T>
Deck<T> Deck<T>::operator+(const T& other)
{
	Deck<T> d[this->size + 1];
	for (size_t i = 0; i < this->size; i++)
		d[i] = this->cards[i];
	d[size++] = other;
	return d;
}

template<class T>
Deck& Deck<T>::operator+=(const T& other)
{
	if (this->size == 30)
		return;
	this->cards[this->size++] = other;
	return *this;
}
