#include <iostream>

template<class T>
class AutoPtr
{
public:
    T *m_ptr = nullptr;

public:
    AutoPtr(T *ptr = nullptr)
        :m_ptr(ptr)
    {
        std::cout << "Auto default ptr contr" << std::endl; 
    }

    ~AutoPtr()
    {
        std::cout << "Auto ptr destr" << std::endl;
        if(m_ptr != nullptr)
        {
            delete m_ptr;
        }
    }

    AutoPtr(const AutoPtr &a) 
    {
        std::cout << "Auto ptr copy constructor" << std::endl;
        //deep copy
        m_ptr = new T;
        *m_ptr = *a;
    }

    AutoPtr( AutoPtr &&a)
    : m_ptr(a.m_ptr)
    {
        std::cout << "Autoptr move constructor" << std::endl;
        a.m_ptr = nullptr;
    }


    AutoPtr& operator =(const AutoPtr& a) 
    {
        std::cout << "Auto ptr copy assignment" << std::endl;

        if(&a == this)
        {
            return *this;
        }
        
        if(m_ptr != nullptr)
        {
            delete m_ptr;
        }

        m_ptr = new T;
        *m_ptr = *a;


        return *this;        
    }

    AutoPtr& operator = (AutoPtr &&a)
    {
        std::cout << "Autoptr move assignment" << std::endl;
        if(this == &a) return *this;

        if(m_ptr != nullptr)
        {
            delete m_ptr;
        }
        m_ptr = a.m_ptr;
        a.m_ptr = nullptr; 

        return *this;
    }




    T& operator*() const 
    {
        return *m_ptr;
    }
    T* operator->() const
    {
        return m_ptr;
    }
    bool isNull() const 
    {
        return m_ptr == nullptr;
    }
};