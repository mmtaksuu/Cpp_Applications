#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <cstring>
#include <fstream>
#include <string>

#include "myint.h"
#include "sentence.h"
#include "smart_ptr.h"
#include "date.h"


int main()
{

    try
    {
        Date date1 {"1/1/2021"};
        Date date2 {"01/12/2020"};
        const Date date3 {operator+(date2, (date1 - date2))};
        const Date date4 {operator+((date1 - date2), date2)};
        std::cout << date3  << "\n";
        std::cout << date4  << "\n";
    }
    catch (const bad_date& ex)
    {
        std::cout << ex.what() << "\n";
    }

    return 0;
}



