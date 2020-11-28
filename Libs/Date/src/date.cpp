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

Date::Date () : m_day(01), m_mon(01), m_year(year_base)
{

}

Date::Date (const char * p_date)
{
    std::cout << "Date (const char * p_date)\n";
    if (std::strlen(p_date) > 10 || std::strlen(p_date) < 8)
        throw bad_date{};

    char str[10]{0};
    std::strcpy(str, p_date);

    auto num_token = 0;
    for (auto token = strtok(str, "/"); token != nullptr; token = strtok(nullptr, "/"))
    {
        ++num_token;
        switch (num_token)
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

    if (num_token != 3)
        throw bad_date{};

}

Date::Date (const std::string & date)
{
    std::cout << "Date (const std::string & date)\n";
    if (date.size() > 10 || date.size() < 8)
        throw bad_date{};

    char str[10]{0};
    std::strcpy(str, date.c_str());

    auto num_token = 0;
    for (auto token = strtok(str, "/"); token != nullptr; token = strtok(nullptr, "/"))
    {
        ++num_token;
        switch (num_token)
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

    if (num_token != 3)
        throw bad_date{};
}

Date::Date (int day, int mon, int year)
{
    std::cout << "Date (int day, int mon, int year)\n";
    m_day  = day > 0 && day <= 31 ? day : throw bad_date{};
    m_mon  = mon > 0 && mon <= 12 ? mon : throw bad_date{};
    m_year = year > min_rand_year && year <= max_rand_year ? year : throw bad_date{};
}

Date::Date (time_t timer)
{
    auto tm   = localtime(&timer);
    m_day  = tm->tm_mday;
    m_mon  = tm->tm_mon + 1;
    m_year = tm->tm_year + year_base;
}

std::ostream & operator<< (std::ostream & os, const Date & date)
{
    return os << date.m_day << "/" << date.m_mon << "/" << date.m_year;
}


