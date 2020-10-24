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

int main()
{
    SmartPtr<int> ptr {new int};

    if (ptr)
        std::cout << "Gecerli\n";
    else
        std::cout << "Gecersiz\n";

    return 0;
}



