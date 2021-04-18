#pragma once
#include"Deck.h"
#include<cstdlib>
#include<ctime>
#include<fstream>

template<class T, class U>
class Player
{
private:
	String playerName;
	size_t wins;
	size_t losses;
	Deck<T> deck1;
	Deck<U> deck2;
public:
	Player();
	Player(const String _playerName, size_t _wins, size_t losses, Deck<T> _deck1, Deck<U> _deck2);
	void setWins(size_t _wins);
	void setLosses(size_t _losses);
	String getPlayerName() const;
	size_t getWins() const;
	size_t getLosses() const;
	T drawCardDeck1();
	U drawCardDeck2();
	void savePlayer(std::ofstream& out) const;
	void loadPlayer(std::ifstream& in);
	friend std::ostream& operator<<(std::ostream& out, const Player& player)
	{
		out << "Player: " << player.playerName << std::endl;
		out << "Wins: " << player.wins << std::endl;
		out << "Losses: " << player.losses << std::endl << std::endl;
		out << "---First Deck---" << std::endl << player.deck1 << std::endl;
		out << "---Second Deck---" << std::endl << player.deck2 << std::endl;
		return out;
	}
	friend std::istream& operator>>(std::istream& in, const Player& player)
	{
		in >> player.playerName;
		in >> player.wins;
		in >> player.losses;
	}
};

template<class T, class U>
Player<T, U>::Player()
{
	this->wins = 0;
	this->losses = 0;
}

template<class T, class U>
Player<T, U>::Player(const String _playerName, size_t _wins, size_t _losses, Deck<T> _deck1, Deck<U> _deck2)
{
	this->playerName = _playerName;
	this->wins = _wins = 0;
	this->losses = _losses = 0;
	this->deck1 = _deck1;
	this->deck2 = _deck2;
}
template<class T, class U>
void Player<T, U>::setWins(size_t _wins)
{
	this->wins = _wins;
}
template<class T, class U>
void Player<T, U>::setLosses(size_t _losses)
{
	this->losses = _losses;
}
template<class T, class U>
inline String Player<T, U>::getPlayerName() const
{
	return this->playerName;
}
template<class T, class U>
size_t Player<T, U>::getWins() const
{
	return this->wins;
}
template<class T, class U>
inline size_t Player<T, U>::getLosses() const
{
	return this->losses;
}
template<class T, class U>
T Player<T, U>::drawCardDeck1()
{
	return this->deck1.drawCard();
}

template<class T, class U>
U Player<T, U>::drawCardDeck2()
{
	return this->deck2.drawCard();
}

template<class T, class U>
void Player<T, U>::savePlayer(std::ofstream& out) const
{
	out << this->playerName << std::endl;
	out << this->wins << std::endl;
	out << this->losses << std::endl << std::endl;
}

template<class T, class U>
void Player<T, U>::loadPlayer(std::ifstream& in)
{
	in >> this->playerName;
	in >> this->wins;
	in >> this->losses;
}
