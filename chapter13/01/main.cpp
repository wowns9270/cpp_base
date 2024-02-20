#include <iostream>

template<typename T>
T getMax(T x, T y)
{
    return x > y ? x : y;
}

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents)
    : m_cents(cents)
    {
    }

    void print() const
    {
        std::cout << m_cents << std::endl;
    }

    bool operator > (const Cents &tmp)
    {
        return this->m_cents > tmp.m_cents;
    }
};

int main()
{
    auto k = getMax(1, 1);

    std::cout << k << std::endl;

    Cents a1(4);
    Cents a2(5);

    Cents ret = getMax(a1, a2);
    
    ret.print();
}

