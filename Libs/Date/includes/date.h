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

#define     DAY       1
#define     MONTH     2
#define     YEAR      3


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
    static constexpr int first_month   = 1;
    static constexpr int last_month    = 12;
    static constexpr int min_day       = 1;
    static constexpr int max_day       = 31;
public:

    enum class WeekDay;

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
    [[nodiscard]] WeekDay get_weekday () const;

    Date& set_month_day(int day);
    Date& set_month(int mon);
    Date& set_year(int year);
    Date& set(int day, int mon, int year);

    static Date random_date ();

    Date& operator++ ();
    Date  operator++ (int);
    Date& operator-- ();
    Date  operator-- (int);

    Date operator+ (int day) const;
    Date operator- (int day) const;

    Date& operator+= (int day);
    Date& operator-= (int day);

    bool operator== (const Date& other)const;
    bool operator<  (const Date& other)const;

    friend std::ostream& operator<< (std::ostream& os, const Date& date);
    friend std::istream& operator>> (std::istream& is, Date& date);

};

inline bool operator!= (const Date& date1, const Date& date2)
{
    return !(date1 == date2);
}

inline bool operator<= (const Date& date1, const Date& date2)
{
    return !(date2 < date1);
}

inline bool operator>  (const Date& date1, const Date& date2)
{
    return (date2 < date1);
}

inline bool operator>= (const Date& date1, const Date& date2)
{
    return !(date1 < date2);
}


#endif /* DATE_H */