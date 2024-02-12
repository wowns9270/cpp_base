#include<iostream>

class Resource
{
public:
    int *m_data = nullptr;
    unsigned m_length = 0;

public:
    Resource()
    {
        std::cout << "Resource constructed " << std::endl;
    }

    Resource(unsigned length)
    {
        std::cout << "Resource length constructed " << std::endl;

        this->m_data = new int[length];
        this->m_length = length;
    }

    Resource(const Resource &res)
    {
        std::cout << "Resource copy constructed " << std::endl;

        //this->m_data = new int[res.m_length];
        //this->m_length = res.m_length;
        Resource(res.m_length);

        for(unsigned i = 0; i< m_length; i++)
        {
            this->m_data[i] = res.m_data[i];
        }
    }

    ~Resource()
    {
        std::cout << "Resource destroyed " << std::endl;

        if(m_data != nullptr)
        {
            delete[] m_data;
            m_data = nullptr;
            m_length = 0;
        }
    }

    Resource& operator =(const Resource & res)
    {
        std::cout << "Resource copy assignment " << std::endl;

        //자신 확인
        if(this == &res) return *this;

        if(this->m_data != nullptr)
        {
            delete[] this->m_data;
        }

        this->m_data = new int[res.m_length];
        this->m_length = res.m_length;

        for(unsigned i = 0 ; i< this->m_length; i++)
        {
            this->m_data[i] = res.m_data[i];
        }

        return *this;
    }

    void print() const
    {
        for(unsigned i = 0;  i < this->m_length; i++)
        {
            std::cout <<m_data[i] << " ";
        }
        std::cout << std::endl;
    }

    void setAll(const int & v)
    {
        for(unsigned i = 0; i< m_length; i++)
        {
            m_data[i] = v;
        }
    }

};