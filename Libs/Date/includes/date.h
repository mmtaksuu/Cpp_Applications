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
    [[nodiscard]] const char * what () const noexcept override
    {
        return "Gecersiz Tarih!";
    }
};


class Date {
private:
    int m_day  {};
    int m_mon  {};
    int m_year {};

    Date & str2date (const char * p);

    static constexpr int days_of_months[][13] = {
            { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
            { 0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 },
    };

    static constexpr int year_base     = 1900;
    static constexpr int min_rand_year = 1940;
    static constexpr int max_rand_year = 2020;
public:

    enum class WeekDay {
        Sunday,
        Monday,
        Tuesday,
        Wednesday,
        Thursday,
        Friday,
        Saturday
    };

    Date ();
    explicit Date (int day, int mon, int year);
    explicit Date (const char * p_date);
    explicit Date (const std::string & date);
    explicit Date (time_t timer);

    [[nodiscard]] static constexpr bool is_leap (int year);

    [[nodiscard]] int get_month_day () const;
    [[nodiscard]] int get_month () const;
    [[nodiscard]] int get_year_day () const;
    [[nodiscard]] int get_year () const;
    [[nodiscard]] int get_week_day () const;

    Date& set_month_day(int day);
    Date& set_month(int mon);
    Date& set_year(int year);
    Date& set(int day, int mon, int year);

    Date operator+ (int day) const;
    Date operator- (int day) const;
    Date& operator+= (int day);
    Date& operator-= (int day);

    Date& operator++ ();
    Date  operator++ (int);
    Date& operator-- ();
    Date  operator-- (int);

    friend std::ostream& operator<< (std::ostream& os, const Date& date);
    friend std::istream& operator>> (std::istream& is, Date& date);

};

#endif /* DATE_H */