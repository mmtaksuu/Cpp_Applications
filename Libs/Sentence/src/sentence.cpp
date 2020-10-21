#include <iostream>
#include <cstring>
#include "../includes/sentence.h"

Sentence::Sentence() = default;

Sentence::Sentence(const char *p)
{
    m_size = std::strlen(p);
    m_pd   = new char [m_size+1]{};
    std::strcpy(m_pd, p);
}

Sentence::~Sentence()
{
    delete [] m_pd;
}

Sentence::Sentence(const Sentence& other)
{
    m_size = other.m_size;
    m_pd   = new char [m_size+1]{};
    std::strcpy(m_pd, other.m_pd);
}

Sentence& Sentence::operator=(const Sentence& other)
{
    m_size = other.m_size;
    m_pd   = new char [m_size+1]{};
    std::strcpy(m_pd, other.m_pd);
    return *this;
}

Sentence::Sentence(Sentence&& other)
{
    m_size = other.m_size;
    m_pd   = other.m_pd;
    other.m_size = 0;
    other.m_pd   = nullptr;
}

Sentence& Sentence::operator=(Sentence&& other)
{
    delete m_pd;

    m_pd   = other.m_pd;
    m_size = other.m_size;

    other.m_size = 0;
    other.m_pd   = nullptr;

    return *this;
}

char& Sentence::operator[](int idx)
{
    return m_pd[idx];
}

const char& Sentence::operator[](int idx)const
{
    return m_pd[idx];
}

Sentence& Sentence::operator+=(const Sentence& other)
{
    char temp[INPUT_CHARACTER_BUFFER_SIZE]{};
    std::strcpy(temp, m_pd);
    m_size += other.m_size;
    delete [] m_pd;
    m_pd   = new char [m_size+1]{};
    std::strcat(std::strcat(std::strcpy(m_pd, temp), " "), other.m_pd);
    return *this;
}


size_t Sentence::get_size()const
{
    return m_size;
}

char * Sentence::sgets(char *p)
{
    char * str = p;
    size_t size{};
    int ch{};

    while ((ch = std::getchar()) != '\n')
        str[size++] = static_cast<char>(ch);

    str[size++] = '\n';

    return p;
}

std::istream& operator>>(std::istream& is,       Sentence& s)
{
    char str[INPUT_CHARACTER_BUFFER_SIZE]{};
    Sentence::sgets(str);
    s = Sentence(str);
    return is;
}

std::ostream& operator<<(std::ostream& os, const Sentence& s)
{
    return os << s.m_pd;
}

