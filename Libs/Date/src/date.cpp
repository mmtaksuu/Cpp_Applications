/**
 * @file    : Cpp_Applications project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 28 / November / 2020
 * @code    : date.cpp file
 * @details : 
 */


#include "date.h"
#include <ctime>
#include <cstring>
#include <iostream>
#include <iomanip>

Date::Date () : m_day(01), m_mon(01), m_year(year_base)
{

}

Date::Date (const char * p_date)
{
    str2date(p_date);
}

Date::Date (const std::string & date)
{
    str2date(date.c_str());
}

Date::Date (int day, int mon, int year)
{
    m_day  = day > 0 && day <= 31 ? day : throw bad_date{};
    m_mon  = mon > 0 && mon <= 12 ? mon : throw bad_date{};
    m_year = year > min_rand_year && year <= max_rand_year ? year : throw bad_date{};
}

Date::Date (time_t timer)
{
    auto tm = localtime(&timer);
    m_day   = tm->tm_mday;
    m_mon   = tm->tm_mon  + 1;
    m_year  = tm->tm_year + year_base;
}

Date& Date::str2date (const char * p)
{
    if (std::strlen(p) > 10 || std::strlen(p) < 8)
        throw bad_date{};

    char str[10]{0};
    std::strcpy(str, p);

    auto num_of_token = 0;
    for (auto token = strtok(str, "/-."); token != nullptr; token = strtok(nullptr, "/-."))
    {
        ++num_of_token;
        switch (num_of_token)
        {
            case 1:
                m_day  = std::atoi(token) > 0 && std::atoi(token) <= 31 ? std::atoi(token) : throw bad_date{};
                break;
            case 2:
                m_mon  = std::atoi(token) > 0 && std::atoi(token) <= 12 ? std::atoi(token) : throw bad_date{};
                break;
            case 3:
                m_year = std::atoi(token) > min_rand_year && std::atoi(token) <= max_rand_year ? std::atoi(token) : throw bad_date{};
                break;
            default:
                break;
        }
    }

    if (num_of_token != 3)
        throw bad_date{};

    return *this;
}

constexpr bool Date::is_leap (int year)
{
    return ((year % 4 == 0) && (year % 100 != 0 || year % 400 == 0));
}

int Date::get_month_day () const
{
    return days_of_months[is_leap(m_year)][m_mon];
}

int Date::get_month () const
{
    return m_mon;
}

int Date::get_year_day () const
{
    return is_leap(m_year) ? 366 : 365;
}

int Date::get_year () const
{
    return m_year;
}

int Date::get_week_day () const
{
    constexpr int m_tabs[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

    int day  = m_day;
    int mon  = m_mon;
    int year = m_year;

    year = mon < 3 ? year-1 : year;

    return ((year + year / 4 - year / 100 + year / 400 + m_tabs[mon - 1] + day) % 7);
}

Date& Date::set_month_day(int day)
{
    m_day = day > 0 && day <= 31 ? day : throw bad_date{};
    return *this;
}

Date& Date::set_month(int mon)
{
    m_mon = mon > 0 && mon <= 12 ? mon : throw bad_date{};
    return *this;
}

Date& Date::set_year(int year)
{
    m_year = year > min_rand_year && year <= max_rand_year ? year : throw bad_date{};
    return *this;
}

Date& Date::set(int day, int mon, int year)
{
    Date(day, mon, year);
    return *this;
}

Date Date::operator- (int day) const
{
    Date temp{*this};
    for (int i = 0; i < day; ++i)
        temp--;
    return temp;
}

Date Date::operator+ (int day) const
{
    Date temp{*this};
    for (int i = 0; i < day; ++i)
        temp++;
    return temp;
}

Date & Date::operator+= (int day)
{
    m_day += day;

    if (m_day == days_of_months[is_leap(m_year)][m_mon] + 1)
    {
        m_day = 1;

        if (m_mon == 12)
        {
            m_mon = 1;
            ++m_year;
        }
        else
            ++m_mon;
    }

    return *this;
}

Date & Date::operator-= (int day)
{
    if (m_day == 1) {
        if (m_mon == 1) {
            m_mon = 12;
            --m_year;
        }
        else
            --m_mon;

        m_day = days_of_months[is_leap(m_year)][m_mon];
    }
    else
        m_day -= day;

    return *this;
}

Date & Date::operator++ ()
{
    Date::operator+=(1);
    return *this;
}

Date Date::operator++ (int)
{
    Date temp{*this};
    ++*this;
    return temp;
}

Date & Date::operator-- ()
{
    Date::operator-=(1);
    return *this;
}

Date Date::operator-- (int)
{
    Date temp{*this};
    --*this;
    return temp;
}


std::ostream& operator<< (std::ostream & os, const Date & date)
{
    static const char * const p_mons[] = {
                                           "",
                                           "Ocak",
                                           "Subat",
                                           "Mart",
                                           "Nisan",
                                           "Mayis",
                                           "Haziran",
                                           "Temmuz",
                                           "Agustos",
                                           "Eylul",
                                           "Ekim",
                                           "Kasim",
                                           "Aralik"
    };

    static const char * const p_days[] = {
                                           "Pazar",
                                           "Pazartesi",
                                           "Sali",
                                           "Carsamba",
                                           "Persembe",
                                           "Cuma",
                                           "Cumartesi"
    };

    char buff[25]{};
    std::sprintf(buff, "%2d %-6s %-4d %-6s", date.m_day, p_mons[date.m_mon], date.m_year, p_days[date.get_week_day()]);
    return os << buff;
}

std::istream & operator>> (std::istream & is, Date & date)
{
    std::string buffer{};
    std::getline(is, buffer);
    date.str2date(buffer.c_str());
    return is;
}












