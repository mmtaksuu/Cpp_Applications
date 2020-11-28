#ifndef SENTENCE_H
#define SENTENCE_H

#include <iosfwd>

#define     INPUT_CHARACTER_BUFFER_SIZE      1024

class Sentence {
private:
    size_t m_size{};
    char *m_pd{nullptr};

public:
    Sentence();
    Sentence(const char *p);
    ~Sentence();
    Sentence(const Sentence&);
    Sentence& operator=(const Sentence&);
    Sentence(Sentence&&);
    Sentence& operator=(Sentence&&);

    char& operator[](int idx);
    const char& operator[](int idx)const;

    Sentence& operator+=(const Sentence& other);

    size_t get_size()const;
    static char *sgets(char *p);

    // Type cast operator func.
    explicit operator std::string ()const;

    friend std::istream& operator>>(std::istream& is,       Sentence& s);
    friend std::ostream& operator<<(std::ostream& os, const Sentence& s);

};

inline Sentence operator+(const Sentence& s1, const Sentence& s2)
{
    return Sentence(s1) += s2;
}


#endif //SENTENCE_H
