#ifndef MINT_H
#define MINT_H

#include <iosfwd>

class Mint {
private:
    int mval{};
public:
    Mint() = default;
    explicit Mint(int val) : mval(val) {}
    Mint& operator=(const Mint& other)
    {
        mval = other.mval;
        return *this;
    }

    // Member logical operators
    bool operator>(const Mint& other)const;
    bool operator==(const Mint& other)const;

    // Member sign operators
    Mint operator+();
    Mint operator-();

    // Member Assignment Operators
    Mint& operator+=(const Mint& other);
    Mint& operator-=(const Mint& other);
    Mint& operator*=(const Mint& other);
    Mint& operator/=(const Mint& other);
    Mint& operator%=(const Mint& other);

    // Member Increment and Decrement Operators
    Mint& operator++();
    Mint  operator++(int);
    Mint& operator--();
    Mint  operator--(int);

    // Type cast operator func.
    operator int ()const;

    // Friend inserter and extractor operators
    friend std::ostream& operator<<(std::ostream& os, const Mint& mint);
    friend std::istream& operator>>(std::istream& is,       Mint& mint);
};


// inline Arithmetic Operators
inline Mint operator+(const Mint& x, const Mint& y)
{
    return Mint(x) += y;
}

inline Mint operator-(const Mint& x, const Mint& y)
{
    return Mint(x) -= y;
}

inline Mint operator*(const Mint& x, const Mint& y)
{
    return Mint(x) *= y;
}

inline Mint operator/(const Mint& x, const Mint& y)
{
    return Mint(x) /= y;
}

inline Mint operator%(const Mint& x, const Mint& y)
{
    return Mint(x) %= y;
}


// inline Logical Operators
inline bool operator<(const Mint& x, const Mint& y)
{
    return (y > x);
}

inline bool operator<=(const Mint& x, const Mint& y)
{
    return !(x > y);
}

inline bool operator>=(const Mint& x, const Mint& y)
{
    return !(y > x);
}

inline bool operator!=(const Mint& x, const Mint& y)
{
    return !(y == x);
}


#endif //MINT_H
