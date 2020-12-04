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
        time_t timer{};
        Date date1{time(&timer)};
        Date date2{"31/12/2020"};

        int n = date2-date1;
        for (int i = 0; i < n; ++i)
            ++date1;
        std::cout << date1   << "\n";

    }
    catch (const bad_date& ex)
    {
        std::cout << ex.what() << "\n";
    }

    return 0;
}



