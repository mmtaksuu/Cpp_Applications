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






