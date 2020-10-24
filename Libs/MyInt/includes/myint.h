#ifndef MINT_H
#define MINT_H

#include <iosfwd>

class MyInt {
private:
    int mval{};
public:
    MyInt() = default;
    explicit MyInt(int val) : mval(val) {}
    MyInt& operator=(const MyInt& other)
    {
        mval = other.mval;
        return *this;
    }

    // Member logical operators
    bool operator>(const MyInt& other)const;
    bool operator==(const MyInt& other)const;

    // Member sign operators
    MyInt operator+();
    MyInt operator-();

    // Member Assignment Operators
    MyInt& operator+=(const MyInt& other);
    MyInt& operator-=(const MyInt& other);
    MyInt& operator*=(const MyInt& other);
    MyInt& operator/=(const MyInt& other);
    MyInt& operator%=(const MyInt& other);

    // Member Increment and Decrement Operators
    MyInt& operator++();
    MyInt  operator++(int);
    MyInt& operator--();
    MyInt  operator--(int);

    // Type cast operator functions
    explicit operator int ()const;
    explicit operator bool ()const;

    // Friend inserter and extractor operators
    friend std::ostream& operator<<(std::ostream& os, const MyInt& mint);
    friend std::istream& operator>>(std::istream& is, MyInt& mint);
};


// inline Arithmetic Operators
inline MyInt operator+(const MyInt& x, const MyInt& y)
{
    return MyInt(x) += y;
}

inline MyInt operator-(const MyInt& x, const MyInt& y)
{
    return MyInt(x) -= y;
}

inline MyInt operator*(const MyInt& x, const MyInt& y)
{
    return MyInt(x) *= y;
}

inline MyInt operator/(const MyInt& x, const MyInt& y)
{
    return MyInt(x) /= y;
}

inline MyInt operator%(const MyInt& x, const MyInt& y)
{
    return MyInt(x) %= y;
}


// inline Logical Operators
inline bool operator<(const MyInt& x, const MyInt& y)
{
    return (y > x);
}

inline bool operator<=(const MyInt& x, const MyInt& y)
{
    return !(x > y);
}

inline bool operator>=(const MyInt& x, const MyInt& y)
{
    return !(y > x);
}

inline bool operator!=(const MyInt& x, const MyInt& y)
{
    return !(y == x);
}


#endif //MINT_H
