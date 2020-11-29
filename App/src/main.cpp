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
        Date mydate{time(&timer)};
//        mydate - 30;
        std::cout << mydate - 30 << "\n";
    }
    catch (const bad_date& ex)
    {
        std::cout << ex.what() << "\n";
    }

    return 0;
}



