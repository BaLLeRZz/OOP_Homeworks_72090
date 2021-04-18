#pragma once
#include"String.h"
#include"Water.h"
#include"Fire.h"
#include"Earth.h"
#include"Wind.h"

template<class T>
class Deck
{
private:
	T cards[30];
	size_t size;
public:
	Deck();
	void shuffle();
	T drawCard();
	void addCard(const T& other);
	Deck operator+(const T& other);
	Deck& operator+=(const T& other);
	T operator[](size_t index) const;
	friend std::ostream& operator<<(std::ostream& out, const Deck& deck)
	{
		for (size_t i = 0; i < deck.size; i++)
			out << deck.cards[i] << std::endl;
		return out;
	}
};

template<class T>
Deck<T>::Deck()
{
	this->size = 0;
}

template<class T>
void Deck<T>::shuffle() // Мое собствено измислено разбъркване.. С повече елементи го разбърква по-добре (изпробвано)
{        
	if (this->size % 2 == 0)
	{
		T temp = this->cards[this->size - 2];
		T temp2 = this->cards[1];
		for (size_t i = 0; i < this->size; i += 2)
		{
			this->cards[this->size - i - 2] = this->cards[this->size - i - 4];
			this->cards[i + 1] = this->cards[i + 3];
		}
		this->cards[0] = temp;
		this->cards[this->size - 1] = temp2;
	}
	else
	{
		T temp = this->cards[this->size - 1];
		T temp2 = this->cards[1];
		for (size_t i = 0; i < this->size; i += 2)
		{
			if (i + 2 < this->size)
			{
				this->cards[this->size - i - 1] = this->cards[this->size - i - 3];
				this->cards[i + 1] = this->cards[i + 3];
			}
		}
		this->cards[0] = temp;
		this->cards[size - 2] = temp2;
	}
}

template<class T>
T Deck<T>::drawCard()
{
	T temp = this->cards[0];
	for (size_t i = 0; i < this->size - 1; i++)
		this->cards[i] = this->cards[i + 1];
	this->cards[this->size - 1] = temp;
	return temp;
}

template<class T>
void Deck<T>::addCard(const T& other)
{
	if (this->size == 30)
		return;

	for (size_t i = 0; i < this->size; i++)
		if (this->cards[i].getName() == other.getName())
			return;

	this->cards[this->size++] = other;
}

template<class T>
Deck<T> Deck<T>::operator+(const T& other)
{
	Deck<T> result;
	for (size_t i = 0; i < this->size; i++)
		result.addCard(this->cards[i]);
	result.addCard(other);
	return result;
}

template<class T>
Deck<T>& Deck<T>::operator+=(const T& other)
{
	if (this->size == 30)
		return *this;
	this->cards[this->size++] = other;
	return *this;
}

template<class T>
T Deck<T>::operator[](size_t index) const
{
	return this->cards[index];
}
