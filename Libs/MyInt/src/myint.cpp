#include <iostream>
#include "../includes/myint.h"


// Friend inserter and extractor operators
std::ostream& operator<<(std::ostream& os, const MyInt& myint)
{
    return os << myint.mval;
}

std::istream& operator>>(std::istream& is, MyInt& myint)
{
    return is >> myint.mval;
}


// Member logical operators
bool MyInt::operator>(const MyInt& other)const
{
    return (mval > other.mval);
}

bool MyInt::operator==(const MyInt& other)const
{
    return (mval == other.mval);
}


// Member sign operators
MyInt MyInt::operator+()
{
    return *this;
}

MyInt MyInt::operator-()
{
    mval *= -1;
    return *this;
}


// Member Assignment Operators
MyInt& MyInt::operator+=(const MyInt& other)
{
    mval += other.mval;
    return *this;
}

MyInt& MyInt::operator-=(const MyInt& other)
{
    mval -= other.mval;
    return *this;
}

MyInt& MyInt::operator*=(const MyInt& other)
{
    mval *= other.mval;
    return *this;
}

MyInt& MyInt::operator/=(const MyInt& other)
{
    mval = other.mval !=0 ? mval/other.mval : mval;
    return *this;
}

MyInt& MyInt::operator%=(const MyInt& other)
{
    mval = other.mval !=0 ? mval%other.mval : mval;
    return *this;
}


// Member Increment and Decrement Operators
MyInt& MyInt::operator++()
{
    ++mval;
    return *this;
}

MyInt  MyInt::operator++(int)
{
    MyInt temp{*this};
    ++*this;
    return temp;
}

MyInt& MyInt::operator--()
{
    --mval;
    return *this;
}

MyInt  MyInt::operator--(int)
{
    MyInt temp{*this};
    --*this;
    return temp;
}

MyInt::operator int ()const
{
    return mval;
}