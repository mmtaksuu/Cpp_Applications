#include <iostream>
#include "../includes/mint.h"


// Friend inserter and extractor operators
std::ostream& operator<<(std::ostream& os, const Mint& mint)
{
    return os << mint.mval;
}

std::istream& operator>>(std::istream& is,       Mint& mint)
{
    return is >> mint.mval;
}


// Member logical operators
bool Mint::operator>(const Mint& other)const
{
    return (mval > other.mval);
}

bool Mint::operator==(const Mint& other)const
{
    return (mval == other.mval);
}


// Member sign operators
Mint Mint::operator+()
{
    return *this;
}

Mint Mint::operator-()
{
    mval *= -1;
    return *this;
}


// Member Assignment Operators
Mint& Mint::operator+=(const Mint& other)
{
    mval += other.mval;
    return *this;
}

Mint& Mint::operator-=(const Mint& other)
{
    mval -= other.mval;
    return *this;
}

Mint& Mint::operator*=(const Mint& other)
{
    mval *= other.mval;
    return *this;
}

Mint& Mint::operator/=(const Mint& other)
{
    mval = other.mval !=0 ? mval/other.mval : mval;
    return *this;
}

Mint& Mint::operator%=(const Mint& other)
{
    mval = other.mval !=0 ? mval%other.mval : mval;
    return *this;
}


// Member Increment and Decrement Operators
Mint& Mint::operator++()
{
    ++mval;
    return *this;
}

Mint  Mint::operator++(int)
{
    Mint temp{*this};
    ++*this;
    return temp;
}

Mint& Mint::operator--()
{
    --mval;
    return *this;
}

Mint  Mint::operator--(int)
{
    Mint temp{*this};
    --*this;
    return temp;
}

Mint::operator int ()const
{
    return mval;
}