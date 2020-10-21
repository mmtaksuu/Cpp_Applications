#include <string>
#include <vector>
#include <iostream>
#include <ostream>
#include <cstdlib>
#include <ctime>
#include <memory>
#include <cstring>

#include "mint.h"
#include "sentence.h"
#include "smart_ptr.h"


int main()
{
    Sentence sentence{"Bugun havalar biraz isinmaya basladi."};

    std::cout << sentence.get_size() << "\n";

    return 0;
}