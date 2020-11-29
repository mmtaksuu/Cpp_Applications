/**
 * @file    : Cpp_Applications project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 28 / November / 2020
 * @code    : date_test.cpp file
 * @details : 
 */

#define CATCH_CONFIG_MAIN
#include "../includes/catch.hpp"

#include "date.h"

SCENARIO("const char * turunde formatli tarih bilgisi ile Date nesnesinin olusturulmasi", "[Date (const char * )]")
{
    WHEN("Gecersiz gun girilirse")
    {
        REQUIRE_THROWS(Date{"32/10/2020"}, throw bad_date{});
    }

    WHEN("Gecersiz ay girilirse")
    {
        REQUIRE_THROWS(Date{"12/17/2020"}, throw bad_date{});
    }

    WHEN("Gecersiz yil girilirse")
    {
        REQUIRE_THROWS(Date{"12/10/-20"}, throw bad_date{});
    }

    WHEN("Tarih Formati Hatali girilirse")
    {
        REQUIRE_THROWS(Date{"12/132020"}, throw bad_date{});
    }

    WHEN("Gecerli tarih girildiginde")
    {
        REQUIRE_NOTHROW(Date{"12/12/2020"});
    }
}

SCENARIO("std::string turunde formatli tarih bilgisi ile Date nesnesinin olusturulmasi", "[Date (std::string& date)]")
{
    WHEN("Gecersiz gun girilirse")
    {
        REQUIRE_THROWS(Date{std::string("32/10/2020")}, throw bad_date{});
    }

    WHEN("Gecersiz ay girilirse")
    {
        REQUIRE_THROWS(Date{std::string("12/17/2020")}, throw bad_date{});
    }

    WHEN("Gecersiz yil girilirse")
    {
        REQUIRE_THROWS(Date{std::string("12/10/-20")}, throw bad_date{});
    }

    WHEN("Tarih Formati Hatali girilirse")
    {
        REQUIRE_THROWS(Date{std::string("12/132020")}, throw bad_date{});
    }

    WHEN("Gecerli tarih girildiginde")
    {
        REQUIRE_NOTHROW(Date{std::string("12/12/2020")});
    }
}

SCENARIO("gg/aa/yy girisi ile Date nesnesinin olusturulmasi", "[Date (int d, int m, int y)]")
{
    WHEN("Gecersiz gun girilirse")
    {
        REQUIRE_THROWS(Date{32,10,2020}, throw bad_date{});
    }

    WHEN("Gecersiz ay girilirse")
    {
        REQUIRE_THROWS(Date{12,17,2020}, throw bad_date{});
    }

    WHEN("Gecersiz yil girilirse")
    {
        REQUIRE_THROWS(Date{12,10,-20}, throw bad_date{});
    }

    WHEN("Gecerli tarih girildiginde")
    {
        REQUIRE_NOTHROW(Date{12,12,2020});
    }
}

SCENARIO("calender time bilgisi ile Date nesnesinin olusturulmasi", "[Date (time_t timer)]")
{
    WHEN("Zaman bilgisi verildiginde")
    {
        time_t timer;
        REQUIRE_NOTHROW(Date{time(&timer)});
    }
}

SCENARIO("Girilen tarihten n gun sonrasinin hesaplanmasi", "[Date::operator+ ()]")
{
    GIVEN("Bugunun tarihi")
    {
        Date date1{"28/11/2020"};

        WHEN("20 gun sonra") {
            Date date2{date1+20};
            CHECK(date2 == Date{"18/12/2020"});
        }
    }
}

SCENARIO("Girilen tarihten n gun oncesinin hesaplanmasi", "[Date::operator- ()]")
{
    GIVEN("Bugunun tarihi")
    {
        Date date1{"28/11/2020"};

        WHEN("29 gun once") {
            Date date2{date1-29};
            CHECK(date2 == Date{"30/10/2020"});
        }
    }
}


SCENARIO("Karsilastirma operatorlerinin kullanimi", "[class Date]")
{
    GIVEN("Iki Ayni tarih")
    {
        Date date1{"25/12/2020"};
        Date date2{25,12,2020};

        CHECK(date1 == date2);
        CHECK(date1 <= date2);
        CHECK(date1 >= date2);
    }

    GIVEN("Iki Farkli tarih")
    {
        Date date1{"25/12/2020"};
        Date date2{17,8,2017};

        CHECK(date1 != date2);

        WHEN("Date1 > Date2")
        {
            CHECK(date1 > date2);
        }

        WHEN("Date1 >= Date2")
        {
            CHECK(date1 >= date2);
        }

        date1.set(17, 8,  2017);
        date2.set(28, 10, 2020);

        WHEN("Date1 < Date2")
        {
            CHECK(date1 < date2);
        }

        WHEN("Date1 <= Date2")
        {
            CHECK(date1 <= date2);
        }
    }
}

SCENARIO("set function", "[Date& set(d, m, y)]")
{
    GIVEN("gg/aa/yy as a parameter to set function")
    {
        Date mydate{};
        mydate.set(25, 12, 2017);

        CHECK(mydate == Date{"25/12/2017"});
    }
}

SCENARIO("set_year function", "[Date& set_year(int y)]")
{
    GIVEN("year as a parameter to set_year function")
    {
        Date mydate{};
        mydate.set_year(2017);

        CHECK(mydate.get_year() == Date{"25/12/2017"}.get_year());
    }
}

SCENARIO("set_month function", "[Date& set_month(int m)]")
{
    GIVEN("month as a parameter to set_month function")
    {
        Date mydate{};
        mydate.set_month(8);

        CHECK(mydate.get_month() == Date{"25/08/2017"}.get_month());
    }
}

SCENARIO("set_month_day function", "[Date& set_month_day(int d)]")
{
    GIVEN("day as a parameter to set_month_day function")
    {
        Date mydate{};
        mydate.set_month_day(13);

        CHECK(mydate.get_month_day() == Date{"13/08/2017"}.get_month_day());
    }
}

SCENARIO("get_year_day function", "[int get_year_day()]")
{
    GIVEN("A Valid Date")
    {
        Date mydate{"29/11/2020"};
        CHECK(mydate.get_year_day() == 334);
    }
}










