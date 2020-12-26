/**
 * @file    : Cpp_Applications project file
 * @author  : MEHMET AKSU
 * @note    : mmtaksu.25@gmail.com
 * @date    : 24 / December / 2020
 * @code    : fraction_test.cpp file
 * @details : 
 */

#define CATCH_CONFIG_MAIN
#include "../includes/catch.hpp"

#include "fraction.h"

SCENARIO("Pay (numerator) ve payda (denominator) isteyen kurucu işlev testi", "[Fraction (int num, int denum)]")
{
    GIVEN("Payda sifir")
    {
        REQUIRE_THROWS(Fraction{1,0}, throw bad_fraction{});
    }

    GIVEN("Gecerli bir kesirli sayi")
    {
        Fraction f{4,12};
        REQUIRE_NOTHROW(f);
        CHECK(f.get_num() == 1);
        CHECK(f.get_denom() == 3);
    }
}

SCENARIO("Decimal sayi isteyen kurucu işlev testi", "[Fraction (double decimal)]")
{
    GIVEN("Gecerli decimal sayi 1")
    {
        Fraction fd{0.001};
        REQUIRE_NOTHROW(fd);
        CHECK(fd.get_num() == 1);
        CHECK(fd.get_denom() == 1000);
    }

    GIVEN("Gecerli decimal sayi 2")
    {
        Fraction fd{0.005};
        REQUIRE_NOTHROW(fd);
        CHECK(fd.get_num() == 1);
        CHECK(fd.get_denom() == 200);
    }

    GIVEN("Gecerli decimal sayi 3")
    {
        Fraction fd{0.025};
        REQUIRE_NOTHROW(fd);
        CHECK(fd.get_num() == 1);
        CHECK(fd.get_denom() == 40);
    }

    GIVEN("Gecerli decimal sayi 4")
    {
        Fraction fd{4.5};
        REQUIRE_NOTHROW(fd);
        CHECK(fd.get_num() == 9);
        CHECK(fd.get_denom() == 2);
    }

    GIVEN("Gecerli decimal sayi 5")
    {
        Fraction fd{1.0};
        REQUIRE_NOTHROW(fd);
        CHECK(fd.get_num() == 1);
        CHECK(fd.get_denom() == 1);
    }

}


SCENARIO("String isteyen kurucu işlev testi", "[Fraction (const std::string& s)]")
{
    WHEN("String olarak yuzdelikli sayi girilirse")
    {
        GIVEN("Gecerli bir yuzde sayi 1")
        {
            Fraction fd{"25%"};
            REQUIRE_NOTHROW(fd);
            CHECK(fd.get_num() == 1);
            CHECK(fd.get_denom() == 4);
        }

        GIVEN("Gecerli bir yuzde sayi 2")
        {
            Fraction fd{"75%"};
            REQUIRE_NOTHROW(fd);
            CHECK(fd.get_num() == 3);
            CHECK(fd.get_denom() == 4);
        }

        GIVEN("Gecerli bir yuzde sayi 3")
        {
            Fraction fd{"100%"};
            REQUIRE_NOTHROW(fd);
            CHECK(fd.get_num() == 1);
            CHECK(fd.get_denom() == 1);
        }

        GIVEN("Gecerli bir yuzde sayi 4")
        {
            Fraction fd{"90%"};
            REQUIRE_NOTHROW(fd);
            CHECK(fd.get_num() == 9);
            CHECK(fd.get_denom() == 10);
        }

        GIVEN("Gecerli bir yuzde sayi 5")
        {
            Fraction fd{"99%"};
            REQUIRE_NOTHROW(fd);
            CHECK(fd.get_num() == 99);
            CHECK(fd.get_denom() == 100);
        }

        GIVEN("Gecerli bir yuzde sayi 6")
        {
            Fraction fd{"125%"};
            REQUIRE_NOTHROW(fd);
            CHECK(fd.get_num() == 5);
            CHECK(fd.get_denom() == 4);
        }

        GIVEN("Gecerli bir yuzde sayi 7")
        {
            Fraction fd{"150%"};
            REQUIRE_NOTHROW(fd);
            CHECK(fd.get_num() == 3);
            CHECK(fd.get_denom() == 2);
        }

    }

    WHEN("String olarak kesirli sayi girilirse")
    {
        GIVEN("Gecerli bir kesirli sayi 1")
        {
            Fraction fd{"4/12"};
            REQUIRE_NOTHROW(fd);
            CHECK(fd.get_num() == 1);
            CHECK(fd.get_denom() == 3);
        }

        GIVEN("Gecerli bir kesirli sayi 2")
        {
            Fraction fd{"50/100"};
            REQUIRE_NOTHROW(fd);
            CHECK(fd.get_num() == 1);
            CHECK(fd.get_denom() == 2);
        }

        GIVEN("Gecerli bir kesirli sayi 3")
        {
            Fraction fd{"-75/100"};
            REQUIRE_NOTHROW(fd);
            CHECK(fd.get_num() == -3);
            CHECK(fd.get_denom() == 4);
        }
    }

    WHEN("String olarak gecersiz sayi girilirse")
    {
        GIVEN(" '/' specifier girilmez ise")
        {
            REQUIRE_THROWS(Fraction{"-75100"}, throw bad_fraction{});
        }

        GIVEN(" '%' specifier girilmez ise")
        {
            REQUIRE_THROWS(Fraction{"25"}, throw bad_fraction{});
        }

    }
}

SCENARIO("Fraction += () işlev testi", "[Fraction& operator+= (const Fraction& other)]")
{
    WHEN("Paydasi farkli iki fraction sayinin toplanmasi")
    {
        GIVEN("2 Fraction Numbers - 1")
        {
            Fraction f1{2, 3};
            Fraction f2{"25%"};
            Fraction f3 = (f1 += f2);
            CHECK(f3.get_num() == 11);
            CHECK(f3.get_denom() == 12);
        }

        GIVEN("2 Fraction Numbers - 2")
        {
            Fraction f1{6, 14};
            Fraction f2{"-99%"};
            Fraction f3 = (f1 += f2);
            CHECK(f3.get_num() == -393);
            CHECK(f3.get_denom() == 700);
        }

        GIVEN("2 Fraction Numbers - 3")
        {
            Fraction f1{7, 28};
            Fraction f2{"-19%"};
            Fraction f3 = (f1 += f2);
            CHECK(f3.get_num() == 3);
            CHECK(f3.get_denom() == 50);
        }
    }

    WHEN("Paydasi ayni iki fraction sayinin toplanmasi")
    {
        GIVEN("2 Fraction Numbers - 4")
        {
            Fraction f1{3, 4};
            Fraction f2{"-25%"};
            Fraction f3 = (f1 += f2);
            CHECK(f3.get_num() == 1);
            CHECK(f3.get_denom() == 2);
        }

        GIVEN("2 Fraction Numbers - 5")
        {
            Fraction f1{-7, 16};
            Fraction f2{"-25/16"};
            Fraction f3 = (f1 += f2);
            CHECK(f3.get_num() == -2);
            CHECK(f3.get_denom() == 1);
        }

        GIVEN("2 Fraction Numbers - 6")
        {
            Fraction f1{-63, 45};
            Fraction f2{"72/45"};
            Fraction f3 = (f1 += f2);
            CHECK(f3.get_num() == 1);
            CHECK(f3.get_denom() == 5);
        }
    }
}

SCENARIO("Fraction -= () işlev testi", "[Fraction& operator-= (const Fraction& other)]")
{
    WHEN("Paydasi farkli iki fraction sayinin cikarilmasi")
    {
        GIVEN("2 Fraction Numbers - 1")
        {
            Fraction f1{2, 3};
            Fraction f2{"25%"};
            Fraction f3 = (f1 -= f2);
            CHECK(f3.get_num() == 5);
            CHECK(f3.get_denom() == 12);
        }

        GIVEN("2 Fraction Numbers - 2")
        {
            Fraction f1{6, 14};
            Fraction f2{"-99%"};
            Fraction f3 = (f1 -= f2);
            CHECK(f3.get_num() == 993);
            CHECK(f3.get_denom() == 700);
        }

        GIVEN("2 Fraction Numbers - 3")
        {
            Fraction f1{7, 28};
            Fraction f2{"-19%"};
            Fraction f3 = (f1 -= f2);
            CHECK(f3.get_num() == 11);
            CHECK(f3.get_denom() == 25);
        }
    }

    WHEN("Paydasi ayni iki fraction sayinin cikarilmasi")
    {
        GIVEN("2 Fraction Numbers - 4")
        {
            Fraction f1{3, 4};
            Fraction f2{"-25%"};
            Fraction f3 = (f1 -= f2);
            CHECK(f3.get_num() == 1);
            CHECK(f3.get_denom() == 1);
        }

        GIVEN("2 Fraction Numbers - 5")
        {
            Fraction f1{-7, 16};
            Fraction f2{"-25/16"};
            Fraction f3 = (f1 -= f2);
            CHECK(f3.get_num() == 9);
            CHECK(f3.get_denom() == 8);
        }

        GIVEN("2 Fraction Numbers - 6")
        {
            Fraction f1{-63, 45};
            Fraction f2{"72/45"};
            Fraction f3 = (f1 -= f2);
            CHECK(f3.get_num() == -3);
            CHECK(f3.get_denom() == 1);
        }
    }
}

SCENARIO("Fraction *= () işlev testi", "[Fraction& operator*= (const Fraction& other)]")
{
    WHEN("Paydasi farkli iki fraction sayinin carpilmasi")
    {
        GIVEN("2 Fraction Numbers - 1")
        {
            Fraction f1{2, 3};
            Fraction f2{"25%"};
            Fraction f3 = (f1 *= f2);
            CHECK(f3.get_num() == 1);
            CHECK(f3.get_denom() == 6);
        }

        GIVEN("2 Fraction Numbers - 2")
        {
            Fraction f1{6, 14};
            Fraction f2{"-99%"};
            Fraction f3 = (f1 *= f2);
            CHECK(f3.get_num() == -297);
            CHECK(f3.get_denom() == 700);
        }

        GIVEN("2 Fraction Numbers - 3")
        {
            Fraction f1{7, 28};
            Fraction f2{"-19%"};
            Fraction f3 = (f1 *= f2);
            CHECK(f3.get_num() == -19);
            CHECK(f3.get_denom() == 400);
        }
    }

    WHEN("Paydasi ayni iki fraction sayinin carpilmasi")
    {
        GIVEN("2 Fraction Numbers - 4")
        {
            Fraction f1{3, 4};
            Fraction f2{"-25%"};
            Fraction f3 = (f1 *= f2);
            CHECK(f3.get_num() == -3);
            CHECK(f3.get_denom() == 16);
        }

        GIVEN("2 Fraction Numbers - 5")
        {
            Fraction f1{-7, 16};
            Fraction f2{"-25/16"};
            Fraction f3 = (f1 *= f2);
            CHECK(f3.get_num() == 175);
            CHECK(f3.get_denom() == 256);
        }

        GIVEN("2 Fraction Numbers - 6")
        {
            Fraction f1{-63, 45};
            Fraction f2{"72/45"};
            Fraction f3 = (f1 *= f2);
            CHECK(f3.get_num() == -56);
            CHECK(f3.get_denom() == 25);
        }
    }
}

SCENARIO("Fraction /= () işlev testi", "[Fraction& operator/= (const Fraction& other)]")
{
    WHEN("Paydasi farkli iki fraction sayinin bolunmesi")
    {
        GIVEN("2 Fraction Numbers - 1")
        {
            Fraction f1{2, 3};
            Fraction f2{"25%"};
            Fraction f3 = (f1 /= f2);
            CHECK(f3.get_num() == 8);
            CHECK(f3.get_denom() == 3);
        }

        GIVEN("2 Fraction Numbers - 2")
        {
            Fraction f1{6, 14};
            Fraction f2{"-99%"};
            Fraction f3 = (f1 /= f2);
            CHECK(f3.get_num() == -100);
            CHECK(f3.get_denom() == 231);
        }

        GIVEN("2 Fraction Numbers - 3")
        {
            Fraction f1{7, 28};
            Fraction f2{"-19%"};
            Fraction f3 = (f1 /= f2);
            CHECK(f3.get_num() == -25);
            CHECK(f3.get_denom() == 19);
        }
    }

    WHEN("Paydasi ayni iki fraction sayinin bolunmesi")
    {
        GIVEN("2 Fraction Numbers - 4")
        {
            Fraction f1{3, 4};
            Fraction f2{"-25%"};
            Fraction f3 = (f1 /= f2);
            CHECK(f3.get_num() == -3);
            CHECK(f3.get_denom() == 1);
        }

        GIVEN("2 Fraction Numbers - 5")
        {
            Fraction f1{-7, 16};
            Fraction f2{"-25/16"};
            Fraction f3 = (f1 /= f2);
            CHECK(f3.get_num() == 7);
            CHECK(f3.get_denom() == 25);
        }

        GIVEN("2 Fraction Numbers - 6")
        {
            Fraction f1{-63, 45};
            Fraction f2{"72/45"};
            Fraction f3 = (f1 /= f2);
            CHECK(f3.get_num() == -7);
            CHECK(f3.get_denom() == 8);
        }
    }
}

SCENARIO("Fraction global toplama işlevi testi", "[Fraction operator+ (const Fraction& f1, const Fraction &f2)")
{
    WHEN("Paydasi farkli iki fraction sayinin toplanmasi")
    {
        GIVEN("2 Fraction Numbers - 1")
        {
            Fraction f1{2, 3};
            Fraction f2{"25%"};
            Fraction f3 = f1 + f2;
            CHECK(f3.get_num() == 11);
            CHECK(f3.get_denom() == 12);
        }

        GIVEN("2 Fraction Numbers - 2")
        {
            Fraction f1{6, 14};
            Fraction f2{"-99%"};
            Fraction f3 = f1 + f2;
            CHECK(f3.get_num() == -393);
            CHECK(f3.get_denom() == 700);
        }

        GIVEN("2 Fraction Numbers - 3")
        {
            Fraction f1{7, 28};
            Fraction f2{"-19%"};
            Fraction f3 = f1 + f2;
            CHECK(f3.get_num() == 3);
            CHECK(f3.get_denom() == 50);
        }
    }

    WHEN("Paydasi ayni iki fraction sayinin toplanmasi")
    {
        GIVEN("2 Fraction Numbers - 4")
        {
            Fraction f1{3, 4};
            Fraction f2{"-25%"};
            Fraction f3 = f1 + f2;
            CHECK(f3.get_num() == 1);
            CHECK(f3.get_denom() == 2);
        }

        GIVEN("2 Fraction Numbers - 5")
        {
            Fraction f1{-7, 16};
            Fraction f2{"-25/16"};
            Fraction f3 = (f1 + f2);
            CHECK(f3.get_num() == -2);
            CHECK(f3.get_denom() == 1);
        }

        GIVEN("2 Fraction Numbers - 6")
        {
            Fraction f1{-63, 45};
            Fraction f2{"72/45"};
            Fraction f3 = (f1 + f2);
            CHECK(f3.get_num() == 1);
            CHECK(f3.get_denom() == 5);
        }
    }
}

SCENARIO("Fraction global cikarma işlevi testi", "[Fraction operator- (const Fraction& f1, const Fraction &f2)")
{
    WHEN("Paydasi farkli iki fraction sayinin cikarilmasi")
    {
        GIVEN("2 Fraction Numbers - 1")
        {
            Fraction f1{2, 3};
            Fraction f2{"25%"};
            Fraction f3 = (f1 - f2);
            CHECK(f3.get_num() == 5);
            CHECK(f3.get_denom() == 12);
        }

        GIVEN("2 Fraction Numbers - 2")
        {
            Fraction f1{6, 14};
            Fraction f2{"-99%"};
            Fraction f3 = (f1 - f2);
            CHECK(f3.get_num() == 993);
            CHECK(f3.get_denom() == 700);
        }

        GIVEN("2 Fraction Numbers - 3")
        {
            Fraction f1{7, 28};
            Fraction f2{"-19%"};
            Fraction f3 = (f1 - f2);
            CHECK(f3.get_num() == 11);
            CHECK(f3.get_denom() == 25);
        }
    }

    WHEN("Paydasi ayni iki fraction sayinin cikarilmasi")
    {
        GIVEN("2 Fraction Numbers - 4")
        {
            Fraction f1{3, 4};
            Fraction f2{"-25%"};
            Fraction f3 = (f1 - f2);
            CHECK(f3.get_num() == 1);
            CHECK(f3.get_denom() == 1);
        }

        GIVEN("2 Fraction Numbers - 5")
        {
            Fraction f1{-7, 16};
            Fraction f2{"-25/16"};
            Fraction f3 = (f1 - f2);
            CHECK(f3.get_num() == 9);
            CHECK(f3.get_denom() == 8);
        }

        GIVEN("2 Fraction Numbers - 6")
        {
            Fraction f1{-63, 45};
            Fraction f2{"72/45"};
            Fraction f3 = (f1 - f2);
            CHECK(f3.get_num() == -3);
            CHECK(f3.get_denom() == 1);
        }
    }
}

SCENARIO("Fraction global carpma işlevi testi", "[Fraction operator* (const Fraction& f1, const Fraction &f2)")
{
    WHEN("Paydasi farkli iki fraction sayinin carpilmasi")
    {
        GIVEN("2 Fraction Numbers - 1")
        {
            Fraction f1{2, 3};
            Fraction f2{"25%"};
            Fraction f3 = (f1 * f2);
            CHECK(f3.get_num() == 1);
            CHECK(f3.get_denom() == 6);
        }

        GIVEN("2 Fraction Numbers - 2")
        {
            Fraction f1{6, 14};
            Fraction f2{"-99%"};
            Fraction f3 = (f1 * f2);
            CHECK(f3.get_num() == -297);
            CHECK(f3.get_denom() == 700);
        }

        GIVEN("2 Fraction Numbers - 3")
        {
            Fraction f1{7, 28};
            Fraction f2{"-19%"};
            Fraction f3 = (f1 * f2);
            CHECK(f3.get_num() == -19);
            CHECK(f3.get_denom() == 400);
        }
    }

    WHEN("Paydasi ayni iki fraction sayinin carpilmasi")
    {
        GIVEN("2 Fraction Numbers - 4")
        {
            Fraction f1{3, 4};
            Fraction f2{"-25%"};
            Fraction f3 = (f1 * f2);
            CHECK(f3.get_num() == -3);
            CHECK(f3.get_denom() == 16);
        }

        GIVEN("2 Fraction Numbers - 5")
        {
            Fraction f1{-7, 16};
            Fraction f2{"-25/16"};
            Fraction f3 = (f1 * f2);
            CHECK(f3.get_num() == 175);
            CHECK(f3.get_denom() == 256);
        }

        GIVEN("2 Fraction Numbers - 6")
        {
            Fraction f1{-63, 45};
            Fraction f2{"72/45"};
            Fraction f3 = (f1 * f2);
            CHECK(f3.get_num() == -56);
            CHECK(f3.get_denom() == 25);
        }
    }
}

SCENARIO("Fraction global bolme işlevi testi", "[Fraction operator/ (const Fraction& f1, const Fraction &f2)")
{
    WHEN("Paydasi farkli iki fraction sayinin bolunmesi")
    {
        GIVEN("2 Fraction Numbers - 1")
        {
            Fraction f1{2, 3};
            Fraction f2{"25%"};
            Fraction f3 = (f1 / f2);
            CHECK(f3.get_num() == 8);
            CHECK(f3.get_denom() == 3);
        }

        GIVEN("2 Fraction Numbers - 2")
        {
            Fraction f1{6, 14};
            Fraction f2{"-99%"};
            Fraction f3 = (f1 / f2);
            CHECK(f3.get_num() == -100);
            CHECK(f3.get_denom() == 231);
        }

        GIVEN("2 Fraction Numbers - 3")
        {
            Fraction f1{7, 28};
            Fraction f2{"-19%"};
            Fraction f3 = (f1 / f2);
            CHECK(f3.get_num() == -25);
            CHECK(f3.get_denom() == 19);
        }
    }

    WHEN("Paydasi ayni iki fraction sayinin bolunmesi")
    {
        GIVEN("2 Fraction Numbers - 4")
        {
            Fraction f1{3, 4};
            Fraction f2{"-25%"};
            Fraction f3 = (f1 / f2);
            CHECK(f3.get_num() == -3);
            CHECK(f3.get_denom() == 1);
        }

        GIVEN("2 Fraction Numbers - 5")
        {
            Fraction f1{-7, 16};
            Fraction f2{"-25/16"};
            Fraction f3 = (f1 / f2);
            CHECK(f3.get_num() == 7);
            CHECK(f3.get_denom() == 25);
        }

        GIVEN("2 Fraction Numbers - 6")
        {
            Fraction f1{-63, 45};
            Fraction f2{"72/45"};
            Fraction f3 = (f1 / f2);
            CHECK(f3.get_num() == -7);
            CHECK(f3.get_denom() == 8);
        }
    }
}

SCENARIO("Fraction prefix ++ işlevi testi", "[Fraction& operator++ ()]")
{
    GIVEN("Fraction Number - 1")
    {
        Fraction f{2, 3};
        ++f;
        CHECK(f.get_num() == 5);
        CHECK(f.get_denom() == 3);
    }

    GIVEN("Fraction Number - 2")
    {
        Fraction f{"25%"};
        ++f;
        CHECK(f.get_num() == 5);
        CHECK(f.get_denom() == 4);
    }

    GIVEN("Fraction Number - 3")
    {
        Fraction f{6, 14};
        ++f;
        CHECK(f.get_num() == 10);
        CHECK(f.get_denom() == 7);
    }

    GIVEN("Fraction Number - 4")
    {
        Fraction f{"-99%"};
        ++f;
        CHECK(f.get_num() == 1);
        CHECK(f.get_denom() == 100);
    }

    GIVEN("Fraction Number - 5")
    {
        Fraction f{7, 28};
        ++f;
        CHECK(f.get_num() == 5);
        CHECK(f.get_denom() == 4);
    }

    GIVEN("Fraction Number - 6")
    {
        Fraction f{"-19%"};
        ++f;
        CHECK(f.get_num() == 81);
        CHECK(f.get_denom() == 100);
    }

}

SCENARIO("Fraction postfix ++ işlevi testi", "[Fraction operator++ (int)]")
{
    GIVEN("Fraction Number - 1")
    {
        Fraction f{2, 3};
        f++;
        CHECK(f.get_num() == 5);
        CHECK(f.get_denom() == 3);
    }

    GIVEN("Fraction Number - 2")
    {
        Fraction f{"25%"};
        f++;
        CHECK(f.get_num() == 5);
        CHECK(f.get_denom() == 4);
    }

    GIVEN("Fraction Number - 3")
    {
        Fraction f{6, 14};
        f++;
        CHECK(f.get_num() == 10);
        CHECK(f.get_denom() == 7);
    }

    GIVEN("Fraction Number - 4")
    {
        Fraction f{"-99%"};
        f++;
        CHECK(f.get_num() == 1);
        CHECK(f.get_denom() == 100);
    }

    GIVEN("Fraction Number - 5")
    {
        Fraction f{7, 28};
        f++;
        CHECK(f.get_num() == 5);
        CHECK(f.get_denom() == 4);
    }

    GIVEN("Fraction Number - 6")
    {
        Fraction f{"-19%"};
        f++;
        CHECK(f.get_num() == 81);
        CHECK(f.get_denom() == 100);
    }
}

SCENARIO("Fraction prefix -- işlevi testi", "[Fraction& operator-- ()]")
{
    GIVEN("Fraction Number - 1")
    {
        Fraction f{2, 3};
        --f;
        CHECK(f.get_num() == 1);
        CHECK(f.get_denom() == 3);
    }

    GIVEN("Fraction Number - 2")
    {
        Fraction f{"25%"};
        --f;
        CHECK(f.get_num() == 3);
        CHECK(f.get_denom() == 4);
    }

    GIVEN("Fraction Number - 3")
    {
        Fraction f{6, 14};
        --f;
        CHECK(f.get_num() == 4);
        CHECK(f.get_denom() == 7);
    }

    GIVEN("Fraction Number - 4")
    {
        Fraction f{"-99%"};
        --f;
        CHECK(f.get_num() == 199);
        CHECK(f.get_denom() == 100);
    }

    GIVEN("Fraction Number - 5")
    {
        Fraction f{7, 28};
        --f;
        CHECK(f.get_num() == 3);
        CHECK(f.get_denom() == 4);
    }

    GIVEN("Fraction Number - 6")
    {
        Fraction f{"-19%"};
        --f;
        CHECK(f.get_num() == 119);
        CHECK(f.get_denom() == 100);
    }
}

SCENARIO("Fraction postfix -- işlevi testi", "[Fraction operator-- (int)]")
{
    GIVEN("Fraction Number - 1")
    {
        Fraction f{2, 3};
        f--;
        CHECK(f.get_num() == -1);
        CHECK(f.get_denom() == 3);
    }

    GIVEN("Fraction Number - 2")
    {
        Fraction f{"25%"};
        f--;
        CHECK(f.get_num() == -3);
        CHECK(f.get_denom() == 4);
    }

    GIVEN("Fraction Number - 3")
    {
        Fraction f{6, 14};
        f--;
        CHECK(f.get_num() == -4);
        CHECK(f.get_denom() == 7);
    }

    GIVEN("Fraction Number - 4")
    {
        Fraction f{"-99%"};
        f--;
        CHECK(f.get_num() == -199);
        CHECK(f.get_denom() == 100);
    }

    GIVEN("Fraction Number - 5")
    {
        Fraction f{7, 28};
        f--;
        CHECK(f.get_num() == -3);
        CHECK(f.get_denom() == 4);
    }

    GIVEN("Fraction Number - 6")
    {
        Fraction f{"-19%"};
        f--;
        CHECK(f.get_num() == -119);
        CHECK(f.get_denom() == 100);
    }
}

SCENARIO("Fraction member esit esit işlevi testi", "[bool operator== (const Fraction& other)const]")
{
    GIVEN("2 Fraction Numbers")
    {
        CHECK(Fraction{2,3}     == Fraction{"2/3"});
        CHECK(Fraction{-1,8}    == Fraction{"-1/8"});
        CHECK(Fraction{1,4}     == Fraction{"25%"});
        CHECK(Fraction{3,4}     == Fraction{"75%"});
        CHECK(Fraction{-99,100} == Fraction{"-99%"});
        CHECK(Fraction{-19,100} == Fraction{"-19%"});
        CHECK(Fraction{3,10}    == Fraction{"30%"});
        CHECK(Fraction{7,10}    == Fraction{"70%"});
        CHECK(Fraction{"1/2"}   == Fraction{"50%"});
        CHECK(Fraction{"-2/1"}  == Fraction{"-200%"});
    }
}


SCENARIO("Fraction global esit degil işlevi testi", "[bool operator!= (const Fraction& f1, const Fraction& f2)")
{
    GIVEN("2 Fraction Numbers")
    {
        CHECK(Fraction{2,3}     != Fraction{"1/3"});
        CHECK(Fraction{-1,8}    != Fraction{"1/8"});
        CHECK(Fraction{1,4}     != Fraction{"35%"});
        CHECK(Fraction{3,4}     != Fraction{"55%"});
        CHECK(Fraction{-99,100} != Fraction{"-9%"});
        CHECK(Fraction{-19,100} != Fraction{"-39%"});
        CHECK(Fraction{3,10}    != Fraction{"38%"});
        CHECK(Fraction{7,10}    != Fraction{"77%"});
        CHECK(Fraction{"1/2"}   != Fraction{"59%"});
        CHECK(Fraction{"-2/1"}  != Fraction{"-100%"});
    }
}

SCENARIO("Fraction member kucuk işlevi testi", "[bool operator< (const Fraction& other)const]")
{
    GIVEN("2 Fraction Numbers")
    {
        CHECK(Fraction{-2,3}    < Fraction{"2/3"});
        CHECK(Fraction{-1,8}    < Fraction{"1/8"});
        CHECK(Fraction{-1,4}    < Fraction{"25%"});
        CHECK(Fraction{-3,4}    < Fraction{"75%"});
        CHECK(Fraction{-99,100} < Fraction{"99%"});
        CHECK(Fraction{-19,100} < Fraction{"19%"});
        CHECK(Fraction{-3,10}   < Fraction{"30%"});
        CHECK(Fraction{-7,10}   < Fraction{"70%"});
        CHECK(Fraction{"-1/2"}  < Fraction{"50%"});
        CHECK(Fraction{"-2/1"}  < Fraction{"200%"});
    }
}

SCENARIO("Fraction global kucuk esit işlevi testi", "[bool operator<= (const Fraction& f1, const Fraction& f2)")
{
    GIVEN("2 Fraction Numbers")
    {
        CHECK(Fraction{-2,3}    <= Fraction{"2/3"});
        CHECK(Fraction{-1,8}    <= Fraction{"1/8"});
        CHECK(Fraction{-1,4}    <= Fraction{"25%"});
        CHECK(Fraction{-3,4}    <= Fraction{"75%"});
        CHECK(Fraction{-99,100} <= Fraction{"99%"});
        CHECK(Fraction{-19,100} <= Fraction{"19%"});
        CHECK(Fraction{-3,10}   <= Fraction{"30%"});
        CHECK(Fraction{-7,10}   <= Fraction{"70%"});
        CHECK(Fraction{"-1/2"}  <= Fraction{"50%"});
        CHECK(Fraction{"-2/1"}  <= Fraction{"200%"});
        CHECK(Fraction{"8/15"}  <= Fraction{8,15});
        CHECK(Fraction{-7,42}   <= Fraction{"-7/42"});
    }
}

SCENARIO("Fraction global buyuk işlevi testi", "[bool operator> (const Fraction& f1, const Fraction& f2)")
{
    GIVEN("2 Fraction Numbers")
    {
        CHECK(Fraction{2,3}    > Fraction{"-2/3"});
        CHECK(Fraction{1,8}    > Fraction{"-1/8"});
        CHECK(Fraction{1,4}    > Fraction{"-25%"});
        CHECK(Fraction{3,4}    > Fraction{"-75%"});
        CHECK(Fraction{99,100} > Fraction{"-99%"});
        CHECK(Fraction{19,100} > Fraction{"-19%"});
        CHECK(Fraction{3,10}   > Fraction{"-30%"});
        CHECK(Fraction{7,10}   > Fraction{"-70%"});
        CHECK(Fraction{"1/2"}  > Fraction{"-50%"});
        CHECK(Fraction{"2/1"}  > Fraction{"-200%"});
        CHECK(Fraction{"8/15"} > Fraction{-8,15});
        CHECK(Fraction{7,42}   > Fraction{"-7/42"});
    }
}

SCENARIO("Fraction global buyuk esit işlevi testi", "[bool operator>= (const Fraction& f1, const Fraction& f2)")
{
    GIVEN("2 Fraction Numbers")
    {
        CHECK(Fraction{2,3}    >= Fraction{"-2/3"});
        CHECK(Fraction{1,8}    >= Fraction{"-1/8"});
        CHECK(Fraction{1,4}    >= Fraction{"-25%"});
        CHECK(Fraction{3,4}    >= Fraction{"-75%"});
        CHECK(Fraction{99,100} >= Fraction{"-99%"});
        CHECK(Fraction{19,100} >= Fraction{"-19%"});
        CHECK(Fraction{3,10}   >= Fraction{"-30%"});
        CHECK(Fraction{7,10}   >= Fraction{"-70%"});
        CHECK(Fraction{"1/2"}  >= Fraction{"-50%"});
        CHECK(Fraction{"2/1"}  >= Fraction{"-200%"});
        CHECK(Fraction{"8/15"} >= Fraction{8,15});
        CHECK(Fraction{7,42}   >= Fraction{"7/42"});
    }
}


//SCENARIO("Fraction member bool type cast işlevi testi", "[explicit operator bool()const");
//SCENARIO("Fraction member bool operator()! işlevi testi", "[bool operator !()const");
//SCENARIO("Fraction member to_double işlevi testi", "[double to_double()const");
//SCENARIO("Fraction member to_string işlevi testi", "[double to_string()const");







