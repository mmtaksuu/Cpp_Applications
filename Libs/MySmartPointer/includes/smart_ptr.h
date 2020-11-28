#ifndef SMART_PTR_H
#define SMART_PTR_H


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

    explicit operator bool ()const
    {
        return m_ptr != nullptr;
    }
};


#endif //SMART_PTR_H
