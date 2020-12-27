/**
 * @file    : Fraction project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 22 / December / 2020
 * @code    : fraction.h file
 * @details :
 */


#ifndef FRACTION_H
#define FRACTION_H

#include <iosfwd>
#include <numeric>
#include <limits>
#include <exception>


class bad_fraction : public std::exception {
public:
    [[nodiscard]] const char * what()const noexcept override
    {
        return "Gecersiz Kesirli Sayi!";
    }
};


class Fraction {
private:
    int m_numerator{};
    int m_denominator{};

    Fraction& decimal2fraction (double decimal);
    Fraction& percent2fraction (int percent);
    Fraction& str2fraction (const std::string& s);
    Fraction& simplify ();

public:

    static constexpr int min_rand_numarator   = std::numeric_limits<char>::min();
    static constexpr int max_rand_numarator   = std::numeric_limits<char>::max();
    static constexpr int min_rand_denominator = std::integral_constant<int, 1>::value;
    static constexpr int max_rand_denominator = std::numeric_limits<char>::max();

    explicit Fraction(int num = 0, int denum = 1);
    explicit Fraction(double decimal);
    explicit Fraction(const std::string& s);

    Fraction& operator+= (const Fraction& other);
    Fraction& operator-= (const Fraction& other);
    Fraction& operator*= (const Fraction& other);
    Fraction& operator/= (const Fraction& other);

    Fraction& operator++ ();
    Fraction  operator++ (int);
    Fraction& operator-- ();
    Fraction  operator-- (int);

    bool operator== (const Fraction& other)const;
    bool operator<  (const Fraction& other)const;

    explicit operator bool()const;
    bool operator !()const;
    [[nodiscard]] double to_double()const;
    [[nodiscard]] std::string to_string()const;

    [[nodiscard]] int get_num()const;
    [[nodiscard]] int get_denom()const;

    static Fraction random_fraction();

    friend std::ostream& operator<< (std::ostream& os, const Fraction& f);
    friend std::istream& operator<< (std::istream& is, Fraction& f);

};

inline Fraction operator+ (const Fraction& f1, const Fraction &f2)
{
    return Fraction(f1) += f2;
}

inline Fraction operator- (const Fraction& f1, const Fraction &f2)
{
    return Fraction(f1) -= f2;
}

inline Fraction operator* (const Fraction& f1, const Fraction &f2)
{
    return Fraction(f1) *= f2;
}

inline Fraction operator/ (const Fraction& f1, const Fraction &f2)
{
    return Fraction(f1) /= f2;
}


inline bool operator!= (const Fraction& f1, const Fraction& f2)
{
    return !(f1 == f2);
}

inline bool operator<= (const Fraction& f1, const Fraction& f2)
{
    return !(f2 < f1);
}

inline bool operator>  (const Fraction& f1, const Fraction& f2)
{
    return (f2 < f1);
}

inline bool operator>= (const Fraction& f1, const Fraction& f2)
{
    return !(f1 < f2);
}




#endif /* FRACTION_H */