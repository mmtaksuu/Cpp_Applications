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

class Person {
private:
    std::string m_name{};
    std::string m_surname{};
    Date m_birth_date{};
    int m_age{};
public:
    void set(std::string&& name, std::string&& surname, const Date& bdate)
    {
        m_name = name;
        m_surname = surname;
        m_birth_date = bdate;

        time_t timer{};
        m_age = Date{time(&timer)}.get_year() - m_birth_date.get_year();
    }

    friend std::ostream& operator<< (std::ostream& os, const Person& person)
    {
//        std::cout << "\nPerson Info\n";
//        std::cout << "-------------\n";
//        std::cout << "Name       : " << person.m_name       << "\n";
//        std::cout << "Surname    : " << person.m_surname    << "\n";
//        std::cout << "Age        : " << person.m_age        << "\n";
//        std::cout << "Birth Date : " << person.m_birth_date << "\n";

        char buff[25]{};
        std::sprintf(buff, "%3d  %-8s %-6s ", person.m_age, person.m_name.c_str(), person.m_surname.c_str());
        return os << buff << person.m_birth_date;;
    }
};


int main()
{
    try
    {
        Person p1 {};
        p1.set("Mehmet", "Aksu", Date{"15.07.1994"});
        std::cout << p1;
    }
    catch (const bad_date& ex)
    {
        std::cout << ex.what() << "\n";
    }
    catch (const std::exception& ex)
    {
        std::cout << ex.what() << "\n";
    }


    return 0;
}



