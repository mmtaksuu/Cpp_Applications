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

    while (true)
    {
        try
        {
            std::cout << Date::random_date() << "\n";
        }
        catch (const bad_date& ex)
        {
            std::cout << ex.what() << "\n";
        }
    }

    return 0;
}



