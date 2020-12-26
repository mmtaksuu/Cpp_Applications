/**
 * @file    : Fraction project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 22 / December / 2020
 * @code    : fraction.cpp file
 * @details : 
 */

#include "fraction.h"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <random>

Fraction::Fraction (int num, int denum) : m_numerator(num), m_denominator(denum)
{
    if (m_denominator == 0)
        throw bad_fraction{};
    simplify();
}

Fraction::Fraction (double decimal)
{
    decimal2fraction(decimal).simplify();
}

Fraction::Fraction (const std::string& s)
{
    str2fraction(s).simplify();
}


std::ostream& operator<< (std::ostream& os, const Fraction & f)
{
    int num   = f.m_denominator < 0 ? -f.m_numerator   : f.m_numerator  ;
    int denum = f.m_denominator < 0 ? -f.m_denominator : f.m_denominator;

    if (denum == 1)
        return os << "(" << num << ")";

    return os << "(" << num << "/" << denum << ")";
}

std::istream & operator<< (std::istream & is, Fraction & f)
{
    return is >> f.m_numerator >> f.m_denominator;
}

Fraction& Fraction::operator+= (const Fraction& other)
{
    if (m_denominator == other.m_denominator)
    {
        m_numerator += other.m_numerator;
    }
    else
    {
        auto lcm = std::lcm(m_denominator, other.m_denominator);
        m_numerator   *= (lcm / m_denominator);
        m_denominator *= (lcm / m_denominator);

        Fraction temp{other};
        temp.m_numerator   *= (lcm / other.m_denominator);
        temp.m_denominator *= (lcm / other.m_denominator);

        m_numerator += temp.m_numerator;
    }

    simplify();

    return *this;
}

Fraction& Fraction::operator-= (const Fraction& other)
{
    if (m_denominator == other.m_denominator)
    {
        m_numerator -= other.m_numerator;
    }
    else
    {
        auto lcm = std::lcm(m_denominator, other.m_denominator);
        m_numerator   *= (lcm / m_denominator);
        m_denominator *= (lcm / m_denominator);

        Fraction temp{other};
        temp.m_numerator   *= (lcm / other.m_denominator);
        temp.m_denominator *= (lcm / other.m_denominator);

        m_numerator -= temp.m_numerator;
    }

    simplify();

    return *this;
}

Fraction& Fraction::operator*= (const Fraction& other)
{
    m_numerator   *= other.m_numerator;
    m_denominator *= other.m_denominator;
    simplify();
    return *this;
}

Fraction& Fraction::operator/= (const Fraction& other)
{
    m_numerator   *= other.m_denominator;
    m_denominator *= other.m_numerator;

    if (m_numerator > 0 && m_denominator < 0)
    {
        m_numerator   *= -1;
        m_denominator *= -1;
    }

    simplify();
    return *this;
}

Fraction& Fraction::operator++ ()
{
    m_numerator += m_denominator * 1;
    simplify();
    return *this;
}

Fraction  Fraction::operator++ (int)
{
    Fraction temp{*this};
    ++*this;
    simplify();
    return temp;
}

Fraction& Fraction::operator-- ()
{
    m_numerator = m_denominator * 1 - m_numerator;
    simplify();
    return *this;
}

Fraction  Fraction::operator-- (int)
{
    Fraction temp{*this};
    m_numerator -= m_denominator * 1;
    simplify();
    return temp;
}

bool Fraction::operator== (const Fraction& other)const
{
    return (m_numerator == other.m_numerator) && (m_denominator == other.m_denominator);
}

bool Fraction::operator<  (const Fraction& other)const
{
    return (to_double() < other.to_double());
}


Fraction& Fraction::decimal2fraction (double decimal)
{
    std::stringstream out{};
    out << decimal;
    std::string s = out.str();

    if (auto pos = s.find('.'); pos != std::string::npos)
    {
        auto dec_digits = s.substr(pos+1).size();

        m_denominator = 1;
        while (dec_digits--)
            m_denominator *= 10;

        s.erase(std::find(s.begin(), s.end(), '.'));
        m_numerator = std::atoi(s.c_str());
    }
    else
    {
        m_numerator   = static_cast<int>(decimal);
        m_denominator = 1;
    }

    return *this;
}

Fraction& Fraction::percent2fraction (int percent)
{
    m_numerator   = percent;
    m_denominator = 100;
    return *this;
}

Fraction & Fraction::str2fraction (const std::string & s)
{
    if (*std::prev(s.end()) == '%')
    {
        if (auto pos = s.find('%'); pos != std::string::npos)
            percent2fraction(std::atoi(s.substr(0, pos).c_str()));
    }
    else
    {
        const char delimiter = '/';

        if (auto n = std::count_if(s.begin(), s.end(), [](char c){return c == delimiter;}); n != 1)
            throw bad_fraction{};

        if (auto pos = s.find(delimiter); pos != std::string::npos)
        {
            m_numerator   = std::atoi(s.substr(0, pos).c_str());
            m_denominator = std::atoi(s.substr(pos + 1).c_str());
        }
    }

    return *this;
}


void Fraction::simplify ()
{
    int gcd = std::gcd(m_numerator, m_denominator);
    m_numerator   /= gcd;
    m_denominator /= gcd;

    if (m_numerator < 0 && m_denominator < 0)
    {
        m_numerator   *= -1;
        m_denominator *= -1;
    }
}

int Fraction::get_num () const
{
    return m_numerator;
}

int Fraction::get_denom () const
{
    return m_denominator;
}

Fraction::operator bool () const
{
    return m_numerator != 0;
}

bool Fraction::operator! () const
{
    return m_numerator == 0;
}

double Fraction::to_double () const
{
    return m_numerator/static_cast<double>(m_denominator);
}

std::string Fraction::to_string () const
{
    return std::string{std::to_string(m_numerator) + '/' + std::to_string(m_denominator)};
}

Fraction Fraction::random_fraction ()
{
    static std::mt19937 eng { std::random_device{}() };
    static std::uniform_int_distribution<int>dist( min_rand_number, max_rand_number );

    Fraction fraction{dist(eng), dist(eng)};
    fraction.simplify();

    return fraction;
}
