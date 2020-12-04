```c++
#include <string>
#include <iostream>
#include <ostream>


class Person {
private:
    int m_age;
    std::string m_name{};
    std::string m_surname{};
public:
    Person() = default;
    Person(int age, std::string && name, std::string && surname) : m_age(age), m_name(name), m_surname(surname) {}
    ~Person() = default;

    bool operator==(const Person& other);

    friend std::ostream& operator<<(std::ostream& os, const Person &p);
    friend std::istream& operator>>(std::istream& is,       Person &p);
};


std::ostream& operator<<(std::ostream& os, const Person &p)
{
    return os << p.m_name << " " << p.m_surname << " " << p.m_age << "\n";
}

std::istream& operator>>(std::istream& is,       Person &p)
{
    return is >> p.m_name >> p.m_surname >> p.m_age;
}

bool Person::operator==(const Person& other)
{
    return ((m_age == other.m_age) && (m_name == other.m_name) && (m_surname == other.m_surname));
}


int main ()
{
    Person p1{};
    Person p2{};

    std::cout << "Enter the user info : ";
    std::cin >> p1;

    std::cout << p1 << "\n";

    p2 = p1;

    if (p1 == p2)
    {
        std::cout << "The same person info was entered\n";
    }

    return 0;
}
```


## Mint Implementation
```c++
int main()
{
    Mint m1, m2;

    std::srand(static_cast<unsigned>(std::time(nullptr)));

    for (int i = 0; i < 10; ++i) {
        m1 = rand() % 1000;
        m2 = rand() % 1000;
        std::cout.width(4);
        std::cout <<  m1 << "  " <<  m2 << "\n";
    }

    return 0;
}
```

```c++
int main()
{
    Mint m1, m2;

    std::cout << "Enter the numbers = ";
    std::cin >> m1 >> m2;

    std::cout << "m1 = " << m1 << " m2 = " << m2 << "\n\n";

    std::cout << "Logical Operators\n";
    std::cout << "(m1 > m2)  = " << (m1 > m2) << "\n";
    std::cout << "(m1 >= m2) = " << (m1 >= m2) << "\n";
    std::cout << "(m1 < m2)  = " << (m1 < m2) << "\n";
    std::cout << "(m1 <= m2) = " << (m1 <= m2) << "\n";
    std::cout << "(m1 == m2) = " << (m1 == m2) << "\n";
    std::cout << "(m1 != m2) = " << (m1 != m2) << "\n\n";

    std::cout << "Sing Operators\n";
    std::cout << "(-m1) = " << (+m1) << "\n";
    std::cout << "(+m1) = " << (-m1) << "\n\n";

    std::cout << "Arithmetic Operators\n";
    std::cout << "(m1 + m2) = " << (m1 + m2) << "\n";
    std::cout << "(m1 - m2) = " << (m1 - m2) << "\n";
    std::cout << "(m1 * m2) = " << (m1 * m2) << "\n";
    std::cout << "(m1 / m2) = " << (m1 / m2) << "\n";
    std::cout << "(m1 % m2) = " << (m1 % m2) << "\n\n";

    std::cout << "Assignment Operators\n";
    std::cout << "(m1 += m2) = " << (m1 += m2) << "\n";
    std::cout << "(m1 -= m2) = " << (m1 -= m2) << "\n";
    std::cout << "(m1 *= m2) = " << (m1 *= m2) << "\n";
    std::cout << "(m1 /= m2) = " << (m1 /= m2) << "\n";
    std::cout << "(m1 %= m2) = " << (m1 %= m2) << "\n\n";

    std::cout << "Increment and Decrement Operators\n";
    std::cout << "(++m1) = " << (++m1) << "\n";
    std::cout << "(--m1) = " << (--m1) << "\n";
    std::cout << "(m2++) = " << (m2++) << "\n";
    std::cout << "(m2--) = " << (m2--) << "\n\n";

    return 0;
}
```

```c++
#ifndef MINT_H
#define MINT_H

#include <iosfwd>

class Mint {
private:
    int mval{};
public:
    Mint() = default;
    explicit Mint(int val) : mval(val) {}
    Mint& operator=(const Mint& other)
    {
        mval = other.mval;
        return *this;
    }

    // Member logical operators
    bool operator>(const Mint& other)const;
    bool operator==(const Mint& other)const;

    // Member sign operators
    Mint operator+();
    Mint operator-();

    // Member Assignment Operators
    Mint& operator+=(const Mint& other);
    Mint& operator-=(const Mint& other);
    Mint& operator*=(const Mint& other);
    Mint& operator/=(const Mint& other);
    Mint& operator%=(const Mint& other);

    // Member Increment and Decrement Operators
    Mint& operator++();
    Mint  operator++(int);
    Mint& operator--();
    Mint  operator--(int);

    // Friend inserter and extractor operators
    friend std::ostream& operator<<(std::ostream& os, const Mint& mint);
    friend std::istream& operator>>(std::istream& is,       Mint& mint);
};


// inline Arithmetic Operators
inline Mint operator+(const Mint& x, const Mint& y)
{
    return Mint(x) += y;
}

inline Mint operator-(const Mint& x, const Mint& y)
{
    return Mint(x) -= y;
}

inline Mint operator*(const Mint& x, const Mint& y)
{
    return Mint(x) *= y;
}

inline Mint operator/(const Mint& x, const Mint& y)
{
    return Mint(x) /= y;
}

inline Mint operator%(const Mint& x, const Mint& y)
{
    return Mint(x) %= y;
}


// inline Logical Operators
inline bool operator<(const Mint& x, const Mint& y)
{
    return (y > x);
}

inline bool operator<=(const Mint& x, const Mint& y)
{
    return !(x > y);
}

inline bool operator>=(const Mint& x, const Mint& y)
{
    return !(y > x);
}

inline bool operator!=(const Mint& x, const Mint& y)
{
    return !(y == x);
}


#endif //MINT_H
```

```c++
// mint.cpp
#include "mint.h"
#include <iostream>

// Friend inserter and extractor operators
std::ostream& operator<<(std::ostream& os, const Mint& mint)
{
    return os << mint.mval;
}

std::istream& operator>>(std::istream& is,       Mint& mint)
{
    return is >> mint.mval;
}


// Member logical operators
bool Mint::operator>(const Mint& other)const
{
    return (mval > other.mval);
}

bool Mint::operator==(const Mint& other)const
{
    return (mval == other.mval);
}


// Member sign operators
Mint Mint::operator+()
{
    return *this;
}

Mint Mint::operator-()
{
    mval *= -1;
    return *this;
}


// Member Assignment Operators
Mint& Mint::operator+=(const Mint& other)
{
    mval += other.mval;
    return *this;
}

Mint& Mint::operator-=(const Mint& other)
{
    mval -= other.mval;
    return *this;
}

Mint& Mint::operator*=(const Mint& other)
{
    mval *= other.mval;
    return *this;
}

Mint& Mint::operator/=(const Mint& other)
{
    mval = other.mval !=0 ? mval/other.mval : mval;
    return *this;
}

Mint& Mint::operator%=(const Mint& other)
{
    mval = other.mval !=0 ? mval%other.mval : mval;
    return *this;
}


// Member Increment and Decrement Operators
Mint& Mint::operator++()
{
    ++mval;
    return *this;
}

Mint  Mint::operator++(int)
{
    Mint temp{*this};
    ++*this;
    return temp;
}

Mint& Mint::operator--()
{
    --mval;
    return *this;
}

Mint  Mint::operator--(int)
{
    Mint temp{*this};
    --*this;
    return temp;
}

```


### Introduction to Dynamic Lifecycle Objects
```text
* User-Defined otomatik omurlu nesne olusturulmasi
  Olusturulan nesne otomatik omurlu oldugu icin constructor cagrilir ardindan scopu bittiginde destructor cagrilir.
```
```c++
class Myclass {
public:
    Myclass()
    {
        std::cout << "Default Ctor this " << this << "\n";
    }

    ~Myclass()
    {
        std::cout << "Destructor   this " << this << "\n";
    }
};

int main()
{
   std::cout << "main basladi\n";
    {
        Myclass m1{};
    }
   std::cout << "main devam ediyor\n";

    return 0;
}
// Output : 
main basladi
Default Ctor this 0x63ff2f
Destructor   this 0x63ff2f
main devam ediyor
```

```text
* Raw pointer kullanilarak Dinamik Omurlu Nesne Olusturulmasi
  Olusturulan nesne dinamik omurlu nesnedir. Sadece constructor cagrildi. Destructor cagrilmadi cunku nesne delete edilmedi. (Memory Leak)
```
```c++
class Myclass {
public:
    Myclass()
    {
        std::cout << "Default Ctor this " << this << "\n";
    }

    ~Myclass()
    {
        std::cout << "Destructor   this " << this << "\n";
    }
};

int main()
{
   std::cout << "main basladi\n";
    {
        auto p = new Myclass;
    }
   std::cout << "main devam ediyor\n";

    return 0;
}
// Output : 
main basladi
Default Ctor this 0x3066e08
main devam ediyor
```

```text
* Smart pointer kullanilarak Dinamik Omurlu Nesne Olusturulmasi
  Olusturulan nesne dinamik omurlu ve dinamik omurlu nesne adresi smart pointerda tutuldugu icin hem constructor hem de destructor cagrilir.
```
```c++
#include <memory>

class Myclass {
public:
    Myclass()
    {
        std::cout << "Default Ctor this " << this << "\n";
    }

    ~Myclass()
    {
        std::cout << "Destructor   this " << this << "\n";
    }
};

int main()
{
   std::cout << "main basladi\n";
    {
        auto p = std::make_unique<Myclass>();
    }
   std::cout << "main devam ediyor\n";

    return 0;
}
// Output : 
main basladi
Default Ctor this 0x2f76e08
Destructor   this 0x2f76e08
main devam ediyor
```

## operator new() and operator delete()
```c++
void* operator new (size_t n);
void  operator delete (void *);
```

### new keyword'u ile nesne olusturulma senaryosu
```text  
    auto Myclass_ptr = new Myclass;

  1) Ilk olarak 'operator new()' fonksiyonuna cagri yaparak nesne icin bellek allocate eder.
  2) Ardindan 'operator new()' fonksiyonunun geri dondurdugu pointer uzerinden sinifin constructirina cagri yapar.
     Hangi constructorin cagrilacagi new ile olsuturulan ifadenin parametrik yapisina baglidir.
  
    static_cast<Myclass*>(operator new(sizeof(Myclass)))->Myclass();

Not: 'operator new()' fonksiyonu malloc() yerine kullanilmaktadir.
     malloc() yerine bunun kullanilmasinin sebebi, exception throw mekanizmasindan dolayidir.
 
    new keywordu overload edilemez.
    'operator new()' fonksiyonu overload edilebilir.
```
```c++
void* operator new (size_t n)
{
    void * vp = std::malloc(n);
    
    if (vp == nullptr)
        throw std::bad_alloc{};

    return vp;
}
```

### delete keyword'u ile dinamik omurlu nesnenin sonlandirilma senaryosu
```text
    delete Myclass_ptr;

    1) Ilk olarak sinifin destructor'ina cagri yapar.
    2) Ardindan 'operator delete()' fonksiyonunu cagirarak ayrilan bellek blogunu geri verir.

        Myclass_ptr->~Myclass();
        operator delete(Myclass_ptr);

Not: 'operator delete()' fonksiyonu free() yerine kullanilmaktadir.    

    delete keywordu overload edilemez.
    'operator delete()' fonksiyonu overload edilebilir.
```
```c++
void operator delete (void *vp)
{
    if (vp)
        std::free(vp);
}
```

### operator new() and operator delete() Fonksiyonlarinin Uygulamasi
```c++
class Myclass {
private:
    char buffer[1024]{};
public:
    Myclass()
    {
        std::cout << "Default Ctor this " << this << "\n";
    }

    ~Myclass()
    {
        std::cout << "Destructor   this " << this << "\n";
    }

    void* operator new (size_t n)
    {
        std::cout << "operator new(size_t n) called. n = " << n << "\n";
        void * vp = std::malloc(n);
        if (vp == nullptr) {
            throw std::bad_alloc{};
        }
        std::cout << "Address of allocated block is = " << vp << "\n";
        return vp;
    }

    void operator delete (void *vp)
    {
        std::cout << "operator delete(void *vp) called. n = " << vp << "\n";
        if (vp) {
            std::free(vp);
        }
    }
};


int main()
{
   std::cout << "main basladi\n";
    {
        auto p = new Myclass;
    }
   std::cout << "main devam ediyor\n";

    return 0;
}

// Output :
main basladi
operator new(size_t n) called. n = 1024 Bytes
Address of allocated block is    = 0x2727020
Default Ctor             this    = 0x2727020
main devam ediyor
```

```c++
class Myclass {
private:
    char buffer[1024]{};
public:
    Myclass()
    {
        std::cout << "Default Ctor this " << this << "\n";
    }

    ~Myclass()
    {
        std::cout << "Destructor   this " << this << "\n";
    }

    void* operator new (size_t n)
    {
        std::cout << "operator new(size_t n) called. n = " << n << "\n";
        void * vp = std::malloc(n);
        if (vp == nullptr) {
            throw std::bad_alloc{};
        }
        std::cout << "Address of allocated block is = " << vp << "\n";
        return vp;
    }

    void operator delete (void *vp)
    {
        std::cout << "operator delete(void *vp) called for " << vp << "\n";
        if (vp) {
            std::free(vp);
        }
    }
};


int main()
{
   std::cout << "main basladi\n";
    {
        auto p = new Myclass;

        delete p;
    }
   std::cout << "main devam ediyor\n";

    return 0;
}

main basladi
operator new(size_t n) called. n   = 1024 Bytes
Address of allocated block is      = 0x37020
Default Ctor this                  = 0x37020
Destructor   this                  = 0x37020
operator delete(void *vp) called for 0x37020
main devam ediyor
```

```c++
// Smart Pointer kullanimi ile operator new() ve operator delete() cagrilarini gozlemlemek
int main()
{
   std::cout << "main basladi\n";
    {
        auto p = std::make_unique<Myclass>();
    }
   std::cout << "main devam ediyor\n";

    return 0;
}

// Output :
main basladi
operator new(size_t n) called. n   = 1024 Bytes
Address of allocated block is      = 0x37020
Default Ctor this                  = 0x37020
Destructor   this                  = 0x37020
operator delete(void *vp) called for 0x37020
main devam ediyor
```

### About Smart Pointers
```text
* C++'da iki standart smart pointer sinifi vardir.
* Bunlardan biri unique_ptr sinifidir. 
  Tek sahiplik ilkesini implement eder. Yani dinamik omurlu bir nesnenin bir tane sahibi olur. Iki sahibi olamaz.
  Boylece ayni nesneyi iki pointerin gostermesi engellenmis olur. Cunku kopyalamaya karsi kapalidir. (Noncopyable)
  Copy memberlar delete edilmistir.

* unique pointer'da tutulan dinamik bellek adresinin delete edilmesi unutulsa dahi memory leak olusmaz.
  Cunku olsuturulan unique_ptr nesnesinin hayati bittiginde unique_ptr sinifinin destructori cagrilir ve ardindan
  unique_ptr nesnesi free() fonksiyonuna gonderilerek deallocate edilir. 
  Boylece olusturulan dinamik bellek alani geri verildiginden dolayi memory leak olusmaz.
```

```text
* Bu ornekte p pointerinin omru scope sonunda sonlanir ve destructor cagrilir. Boylece olsuturulan dinamik omurlu nesne delete edilir.
```
```c++
int main()
{
   std::cout << "main basladi\n";
    {
        auto p = std::make_unique<Myclass>();
    }
   std::cout << "main devam ediyor\n";

    return 0;
}
```


```text
* Bu ornekte p pointerinin omru programin sonlanmasi ile sonlanir ve destructor cagrilir. Boylece olsuturulan dinamik omurlu nesne delete edilir.
```
```c++
int main()
{
    std::unique_ptr<Myclass> p{nullptr};
    
    std::cout << "main basladi\n";
    {
        p = std::make_unique<Myclass>();
    }
    std::cout << "main devam ediyor\n";

    return 0;
}
```

```text
* unique_ptr nesnesinin olusturulma senaryolarin gosterilmesi
```
```c++
void test_1()
{
    std::unique_ptr<Myclass> p{nullptr};
    {
        p = std::make_unique<Myclass>();
    }
}

std::unique_ptr<Myclass> test_2()
{
    std::unique_ptr<Myclass> p{nullptr};

    {
        p = std::make_unique<Myclass>();
    }

    return p;
}


void test_3()
{
    auto p = std::make_unique<Myclass>();
}


int main()
{
    std::cout << "main basladi\n";
    test_1();
    test_2();
    test_3();
    std::cout << "main devam ediyor\n";

    return 0;
}
```

### Initialization Methods of Dynamic Lifecycle Objects
```c++
int main()
{
    // For default constructor
    auto p1 = new Myclass;
    auto p2 = new Myclass();
    auto p3 = new Myclass{};

    // For params constructor
    auto p4 = new Myclass(8, 10);
    auto p5 = new Myclass{12, 56};

    return 0;
}
```

```c++
int main()
{
    // Creates a dynamic object 'sizeof(int)' 
    auto p1 = new int;
    delete p1;

    // Creates a dynamic object 'sizeof(int * 10)'
    auto p2 = new int [10]{};
    
    for (int i = 0; i < 10; ++i)
        std::cout << p2[i] << " ";
    
    delete [] p2;

    return 0;
}
```

```c++
int main()
{
    auto p1 = new const int;   // Init edilmedigi icin gecersizdir.
    auto p2 = new const int(); 
    auto p3 = new const int{}; 
 
    auto p4 = new const Myclass;   // Default Ctor and zero-init
    auto p5 = new const Myclass(); // Default Ctor and zero-init
    auto p6 = new const Myclass{}; // Default Ctor and zero-init

    return 0;
}
```

### Operator Overloading Devami
```text
* 4 tane operator var, bunlar sinifin member operator fonksiyonu olarak overload edilmek zorundadir. Bunlar :
  Subscript Operator   (index)     []
  Dereference Operator (Icerik)    *
  Arrow Operator       (Ok)        ->
  Address Operator     (Adres)     &
  
```

#### Ornek Kullanimlar
```c++
int main()
{
    std::string str {"mehmet aksu"};

    for(auto c : str)           // range-based foo loop
        std::cout << c << " ";

    std::cout << "\n";

    for (int i = 0; i < str.size(); ++i) {
        std::cout << str[i] << " ";
    }
    return 0;
}
```

```c++
int main()
{
    std::vector<std::string> svec {"mehmet", "emir", "omer", "abdurrahim"};

    for (auto& vec : svec)
        std::cout << vec << " ";

    std::cout << "\n";
    svec[1] += "can";

    for (int i = 0; i < svec.size(); ++i) {
        std::cout << svec[i] << " ";
    }
    return 0;
}
```

### Overloading of Subscript operator[]() Function
```text
* a[b]
  a.operator[](b)
* Geri donus degeri L value expression'dir.

```
```c++
int g{};

class Myclass {
public:
    int& operator[](int x)
    {
        return g;
    }
};

int main()
{
    Myclass m{};

    m[5] = 1;
    std::cout << "g = " << g << "\n";

    m.operator[](10) = 2;
    std::cout << "g = " << g << "\n";

    return 0;
}

// Output 
g = 1
g = 2
```

### Darray Class Implementation 
```c++
class Darray {
private:
    size_t m_size{};
    double *m_data{nullptr};
public:
    Darray(size_t size) : m_size(size), m_data(new double [m_size]{}) { }

    ~Darray()
    {
        delete [] m_data;
    }

    double& operator[](int idx)
    {
        return m_data[idx];
    }

    const double& operator[](int idx)const
    {
        return m_data[idx];
    }

    friend std::ostream& operator<<(std::ostream& os, const Darray& d)
    {
        os << "[ ";
        for (int i = 0; i < d.m_size; ++i)
        {
            os << d.m_data[i] << " ";
        }
        return os << "]";
    }
};

int main()
{
    Darray a(10);
    a[5] = 3;
    auto x = a[9];

    const Darray ca(10);
    ca[5] = 3;            // const double& operator[]() sayesinde sentaks hatasi olur.
    auto y = ca[9];

    return 0;
}
```

### Overloading of Dereference operator*() and  Arrow operator->()Function
```text
  ptr bir pointer ise
  *ptr pointee 'dir.

- Icerik ve Ok operatoruk pointer-like siniflar icin overload edilebilr.(Dogal gozukmesi acisindan)
- Implementasyonunu yapmak icin Myclass turunden hayatta olan dinamik omurlu nesnelerin hayatini kontrol eden MyclassPtr (samart pointer) sinifi olusturuldu.
- Yani adeta unique_ptr sinifi gibi davranacak.

- operator->() fonksiyonunun geri donus degeri pointer yani bir adrestir.
  a->b
  a.operator->()->b

- Ok operatoru binary bir operand olmasina ragmen, unary bir operatormus gibi overload edilir.
```

### Myclass ve MyclassPtr ile Smart Pointer Uygulamasi
```text
* Myclass Implementation
```
```c++
class Myclass {
public:
    Myclass()
    {
        std::cout << "Default ctor this " << this << "\n";
    }

    ~Myclass()
    {
        std::cout << "Destructor this " << this << "\n";
    }

    void func()const
    {
        std::cout << "func() called this " << this << "\n";
    }

    void foo()const
    {
        std::cout << "foo() called this " << this << "\n";
    }

private:
    char buffer[1024]{};
};
```
```text
* Raw pointer kullanarak test kodu yazilmasi
```
```c++
int main()
{
    auto * p = new Myclass;

    p->foo();
    p->func();

    delete p;

    return 0;
}
```
```text
* MyclassPtr implementation 
```
```c++
class MyclassPtr {
public:
    MyclassPtr() = default;

    MyclassPtr(Myclass * ptr) : m_ptr{ptr} { }

    ~MyclassPtr()
    {
        if (m_ptr != nullptr)
            delete m_ptr;
    }

    Myclass& operator*()
    {
        return *m_ptr;
    }

    Myclass* operator->()
    {
        return m_ptr;
    }

private:
    Myclass * m_ptr{nullptr};
};


int main()
{
    std::cout << "main basladi!\n";
    {
        MyclassPtr p = new Myclass;
        p->foo();
        p->func();
    }
    std::cout << "main devam ediyor\n";

    return 0;
}
```

### Generic Smart Pointer Implementation
```c++
template<typename T>
class SmartPtr {
private:
    T * m_ptr{nullptr};

public:
    SmartPtr() = default;

    SmartPtr(T * ptr) : m_ptr(ptr) { }

    ~SmartPtr()
    {
        if (m_ptr)
            delete m_ptr;
    }

    SmartPtr(const SmartPtr& other) = delete;

    SmartPtr& operator=(const SmartPtr& other) = delete;

    SmartPtr(SmartPtr&& other)
    {
        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;
    }

    SmartPtr& operator=(SmartPtr&& other)
    {
        if (m_ptr != nullptr)
            delete m_ptr;

        m_ptr = other.m_ptr;
        other.m_ptr = nullptr;

        return *this;
    }

    T& operator*()
    {
        return *m_ptr;
    }

    T* operator->()
    {
        return m_ptr;
    }
};
```    



### Sentence Class Implementation
```text
* Tipki string sinifinda oldugu gibi Sentence sinifi da yazilari tutacaktir.
* Sentence sinifi input stream'den '\n' karakteri girilene kadar girilen yaziyi tutacaktir. (Buffer boyutu 1024 Byte)
* Sentence sinifinin edindigi kaynaklar copy ve move memberlar tarafindan deep copy ile kullanilacaktir.
```
```c++
class Sentence {
private:
    size_t m_size{};
    char * m_pd{nullptr};

public:
    Sentence()
    {
        std::cout << "Default Constructor this = " << this << "\n";
    }

    Sentence(const char * p) : m_size{std::strlen(p)}, m_pd{new char [m_size+1]{}}
    {
        std::strcpy(m_pd, p);
        std::cout << "Param Constructor this = " << this << "\n";
    }

    ~Sentence()
    {
        std::cout << "Destructor this = " << this << "\n";
        delete [] m_pd;
    }

    Sentence(const Sentence& other) : m_size{other.m_size}, m_pd{new char [m_size+1]{}}
    {
        std::strcpy(m_pd, other.m_pd);
        std::cout << "Copy Constructor this = " << this << "\n";
    }

    Sentence& operator=(const Sentence& other)
    {
        m_size = other.m_size;
        m_pd = new char [m_size+1]{};
        std::strcpy(m_pd, other.m_pd);
        std::cout << "Copy Assignment this = " << this << "\n";
        return *this;
    }

    Sentence(Sentence&& other) : m_size{other.m_size}, m_pd{other.m_pd}
    {
        other.m_size = 0;
        other.m_pd   = nullptr;
        std::cout << "Move Constructor this = " << this << "\n";
    }

    Sentence& operator=(Sentence&& other)
    {
        m_pd         = other.m_pd;
        m_size       = other.m_size;
        other.m_size = 0;
        other.m_pd   = nullptr;

        std::cout << "Move Assignment this = " << this << "\n";
        return *this;
    }
    
    static char* sgets(char *p)
    {
        char *str = p;
        int ch{};
        size_t size{};

        while ((ch = std::getchar()) != '\n')
            str[size++] = static_cast<char>(ch);

        str[size++] = '\n';
        std::cout << "sgets() Called\n";
        return p;
    }

    friend std::istream& operator>>(std::istream& is, Sentence& s)
    {
        char str[1024]{};
        sgets(str);
        Sentence temp{str};    // Param Ctor will call
        s = std::move(temp);   // Move Assignment Operator will call

        return is;
    }
    
    friend std::ostream& operator<<(std::ostream& os, const Sentence& s)
    {
        return os << s.m_pd;
    }

    bool operator==(const Sentence& other)
    {
        return !stricmp(m_pd, other.m_pd);
    }

    bool operator>(const Sentence& other)const
    {
        return (m_size > other.m_size);
    }

    size_t get_size()const
    {
        return m_size;
    }

};
```

```text
* Test 1
```
```c++
int main()
{
    Sentence s1{};                       // Default Constructor
    std::cout << "Enter sentence : ";
    std::cin >> s1;
    std::cout << "s1 = " << s1 << "\n";

    Sentence s2 = s1;                   // Copy Constructor
    std::cout << "s2 = " << s2 << "\n";

    Sentence s3{};                       // Default Constructor
    s3 = s2;                             // Copy Assignment
    std::cout << "s3 = " << s3 << "\n";

    Sentence s4 = std::move(s1);         // Move Constructor
    std::cout << "s4 = " << s4 << "\n";

    return 0;
}
```
```text
* Test 2
```
```c++
int main()
{
    Sentence s1{};
    Sentence s2{};

    std::cout << "Enter sentence 1 : ";
    std::cin >> s1;

    std::cout << "Enter sentence 2 : ";
    std::cin >> s2;

    std::cout << "s1 = " << s1 << "len = " << s1.get_size() << "\n";
    std::cout << "s2 = " << s2 << "len = " << s2.get_size() << "\n";

    if (s1 > s2)
        std::cout << "s1 greater than s2\n";
    else if (s2 > s1)
        std::cout << "s2 greater than s1\n";
    else
        std::cout << "s1 is equal to s2\n";

    if (s1 == s2)
        std::cout << "Both are the same sentences\n";

    return 0;
}
```

### Mint and Sentence Class Together Usage Example 
```c++
#include <string>
#include <iostream>

#include "mint.h"
#include "sentence.h"

class Person {
private:
    std::string name{};
    std::string surname{};
    Mint age{};
    Sentence info{};
public:
    Person() = default;
    ~Person() = default;

    friend std::istream& operator>>(std::istream& is, Person& person)
    {
        return is >> person.name >> person.surname >> person.age >> person.info;
    }

    friend std::ostream& operator<<(std::ostream& os, const Person& person)
    {
        os << "Person :\n";
        os << "    Name    : " << person.name    << "\n";
        os << "    Surname : " << person.surname << "\n";
        os << "    Age     : " << person.age     << "\n";
        os << "    Info    : " << person.info    << "\n";
        os << "--------------------------------------\n";
        return os;
    }
};

int main()
{
    Person p1{};

    std::cout << "Enter person : ";
    std::cin >> p1;
    std::cout << p1;

    return 0;
}
```

### Template Linked List Turunden Sentence ve Mint siniflari Turunden Linked List Olusturulmasi
```c++
#include "mint.h"
#include "sentence.h"

template<typename T>
struct Node {
    T m_data{};
    Node * m_pnext{nullptr};
    Node() = default;
    Node(T& data) : m_data(data), m_pnext(nullptr) {}
    Node(T& data, Node<T *> next) : m_data(data), m_pnext(next) {}
};

template<typename T>
class LinkedList {
public:
    Node<T *> head{};
    LinkedList() = default;
    ~LinkedList() = default;
};


int main()
{
    LinkedList<Sentence> sentence_list {};
    LinkedList<Mint> mint_list {};
    
    return 0;
}
```

```c++
int main()
{
    Sentence s1{"Mehmet naber"};
    Sentence s2{"Iyi senden naber."};
    Sentence s3{"Fena sayilmaz"};
    Sentence s4{"Gorusmek uzere"};

    std::cout << s1 + s2 + s3 + s4 << "\n";

    return 0;
}
```

```c++
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
```