/**
 * @file    : Cpp_Applications project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 28 / November / 2020
 * @code    : date.h file
 * @details : 
 */

#ifndef DATE_H
#define DATE_H

#include <iosfwd>
#include <exception>


class bad_date : public std::exception {
public:
    [[nodiscard]] const char * what()const noexcept override
    {
        return "Gecersiz Tarih!";
    }
};

class Date {
private:
    int m_day{};
    int m_mon{};
    int m_year{};
public:
    static constexpr int year_base      = 1900;
    static constexpr int min_rand_year  = 1940;
    static constexpr int max_rand_year  = 2020;

    enum class Weekday {
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    };


    Date();
    explicit Date(int day, int mon, int year);
    explicit Date(const char *p_date);
    explicit Date(const std::string& date);
    explicit Date(time_t timer);

    friend std::ostream& operator<< (std::ostream& os, const Date& date);

};

#endif /* DATE_H */