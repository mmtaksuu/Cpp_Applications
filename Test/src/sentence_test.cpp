#define CATCH_CONFIG_MAIN
#include "../includes/catch.hpp"

#include "sentence.h"


SCENARIO("Sentence Uzunluk Hesaplama Fonksiyonu", "[sentence]")
{
    GIVEN("get_size")
    {
        Sentence sentence{"Bugun havalar biraz isinmaya basladi."};
        WHEN("A sentence")
        {
            THEN("Yazinin uzunlugunu dondurur.")
            {
                CHECK(sentence.get_size() == 37);
            }
        }
    }
}
