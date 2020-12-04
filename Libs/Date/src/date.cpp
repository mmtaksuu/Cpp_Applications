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
#include <random>


Date::Date ()
{
    set(first_day, first_month, year_base);
}

Date::Date (const char * p_date)
{
    str2date(p_date);
}

Date::Date (const std::string & date)
{
    str2date(date.c_str());
}

Date::Date (time_t timer)
{
    auto tm = localtime(&timer);
    set(tm->tm_mday, tm->tm_mon+1, tm->tm_year+year_base);
}

Date::Date (int day, int mon, int year)
{
    set(day, mon, year);
}

Date& Date::str2date (const char * p)
{
    if (std::strlen(p) > 10 || std::strlen(p) < 8)
        throw bad_date{};

    char str[10]{};
    std::strcpy(str, p);

    auto num_of_token = 0;
    for (auto token = strtok(str, "/-."); token != nullptr; token = strtok(nullptr, "/-."))
    {
        ++num_of_token;
        switch (num_of_token)
        {
            case DAY:
            {
                set_month_day(std::atoi(token));
                break;
            }
            case MONTH:
            {
                set_month(std::atoi(token));
                break;
            }
            case YEAR:
            {
                set_year(std::atoi(token));
                break;
            }
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
    return m_day;
}

int Date::get_month () const
{
    return m_mon;
}

int Date::get_year_day () const
{
    auto days_of_until_now = m_day;

    for (auto i = first_month; i < m_mon; ++i)
        days_of_until_now += days_of_months[is_leap(m_year)][i];

    return days_of_until_now;
}

int Date::get_year () const
{
    return m_year;
}

Date::WeekDay Date::get_weekday () const
{
    constexpr int m_tabs[] = { 0, 3, 2, 5, 0, 3, 5, 1, 4, 6, 2, 4 };

    auto day  = m_day;
    auto mon  = m_mon;
    auto year = m_year;

    year = mon < 3 ? year-1 : year;

    WeekDay wd{((year + year/4 - year/100 + year/400 + m_tabs[mon - 1] + day) % 7)};

    return wd;
}

Date& Date::set_month_day(int day)
{
    m_day = day >= first_day && day <= last_day ? day : throw bad_date{};
    return *this;
}

Date& Date::set_month(int mon)
{
    m_mon = mon >= first_month && mon <= last_month ? mon : throw bad_date{};
    return *this;
}

Date& Date::set_year(int year)
{
    m_year = year >= year_base && year <= std::numeric_limits<int>::max() ? year : throw bad_date{};
    return *this;
}

Date& Date::set(int day, int mon, int year)
{
    set_month_day(day).set_month(mon).set_year(year);
    return *this;
}

Date & Date::operator++ ()
{
    if (++m_day > days_of_months[is_leap(m_year)][m_mon])
    {
        m_day = first_day;

        if (++m_mon > last_month) {
            m_mon = first_month;
            ++m_year;
        }
    }

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
    if (--m_day < first_day)
    {
        if (--m_mon < first_month) {
            m_mon = last_month;
            --m_year;
        }
        m_day = days_of_months[is_leap(m_year)][m_mon];
    }

    return *this;
}

Date Date::operator-- (int)
{
    Date temp{*this};
    --*this;
    return temp;
}

//Date Date::operator+ (int day) const
//{
//    Date date{*this};
//    for (auto i = 0; i < day; ++i)
//        date++;
//    return date;
//}

Date Date::operator- (int day) const
{
    Date date{*this};
    for (auto i = 0; i < day; ++i)
        date--;
    return date;
}

Date & Date::operator+= (int day)
{
    for (auto i = 0; i < day; ++i)
        ++*this;

    return *this;
}

Date & Date::operator-= (int day)
{
    for (auto i = 0; i < day; ++i)
        --*this;

    return *this;
}

bool Date::operator== (const Date & other)const
{
    return ((m_day == other.m_day) && (m_mon == other.m_mon) && (m_year == other.m_year));
}

bool Date::operator< (const Date & other) const
{
    if ((m_year   < other.m_year) ||
        ((m_year == other.m_year) && (m_mon  < other.m_mon)) ||
        ((m_year == other.m_year) && (m_mon == other.m_mon)  && (m_day < other.m_day)))
    {
        return true;
    }

    return false;
}

std::ostream& operator<< (std::ostream & os, const Date & date)
{
    static const char * const p_days[] = { "Pazar", "Pazartesi", "Sali", "Carsamba", "Persembe", "Cuma", "Cumartesi" };
    static const char * const p_mons[] = { "", "Ocak", "Subat", "Mart", "Nisan", "Mayis", "Haziran", "Temmuz", "Agustos", "Eylul", "Ekim", "Kasim", "Aralik" };

    char buff[25]{};
    std::sprintf(buff, "%2d %-7s %-4d %-6s", date.m_day, p_mons[date.m_mon], date.m_year, p_days[static_cast<int>(date.get_weekday())]);
    return os << buff;
}

std::istream & operator>> (std::istream & is, Date & date)
{
    std::string buffer{};
    std::getline(is, buffer);
    date.str2date(buffer.c_str());
    return is;
}

Date Date::random_date ()
{
    Date date{};
    static std::mt19937 eng { std::random_device{}() };

    static std::uniform_int_distribution<int>year_dist( min_rand_year, max_rand_year );
    auto year = year_dist(eng);

    static std::uniform_int_distribution<int>mon_dist ( first_month, last_month );
    auto mon  = mon_dist(eng);

    static std::uniform_int_distribution<int>day_dist ( first_day, days_of_months[is_leap(year)][mon] );
    auto day  = day_dist(eng);

    date.set(day, mon, year);
    return date;
}

int Date::get_total_days(const Date& date)
{
    int num_of_day = 0;

    for (auto i = year_base; i < date.get_year(); ++i)
        for (auto j = first_month; j <= last_month ; ++j)
            num_of_day += days_of_months[is_leap(i)][j];

    for (auto i = first_month; i < date.get_month(); ++i)
        num_of_day += days_of_months[is_leap(date.get_year())][i];

    num_of_day += date.get_month_day();

    return num_of_day;
}

int operator- (const Date& date1, const Date& date2)
{
    return Date::get_total_days(date1) - Date::get_total_days(date2);
}

Date operator+ (const Date &date, int n_day)
{
    Date temp{date};
    temp += n_day;
    return temp;
}

Date operator+ (int n_day, const Date& date)
{
    return operator+(date, n_day);
}

Date::WeekDay& operator-- (Date::WeekDay &wd)
{
    using WeekDay = Date::WeekDay;
    return wd = static_cast<int>(wd)-1 < 1 ? WeekDay::Monday : static_cast<WeekDay>(static_cast<int>(wd)-1);
}

Date::WeekDay  operator-- (Date::WeekDay &wd, int)
{
    Date::WeekDay temp{wd};
    --wd;
    return temp;
}


















