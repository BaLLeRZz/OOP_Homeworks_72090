#pragma once
#include<iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
enum Side
{
    HEAD,
    TAIL
};

class Coin
{
protected:
    Side side;
    char* nationality;
    size_t value;
    void copy(const Coin&);
    void erase();
public:
    Coin();
    Coin(const Coin&);
    Coin(const Side&, const char*, const size_t&);
    Coin& operator=(const Coin&);
    ~Coin();

    Side getSide() const;
    size_t getValue() const;
    const char* enumToString(const Side&);
    virtual void flip();
    void print();
    bool operator==(const Coin&);
    friend std::ostream& operator<<(std::ostream& out, const Coin& coin)
    {
        out << coin.value;
        return out;
    }
};