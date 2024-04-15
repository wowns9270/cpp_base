#include<iostream>

class Cents
{
private:
    int m_cents;

public:
    Cents(int cents = 0) 
    {
        m_cents = cents;
    }

    int getCents() const 
    {
        return m_cents;
    }

    int& getCents() 
    {
        return m_cents;
    }

    // friend Cents operator +(const Cents &c1, const Cents &c2)
    // {
    //     return Cents( c1.getCents() + c2.getCents() );
    // }
    
    Cents& operator +(const Cents &c1)
    {
        this->m_cents += c1.m_cents;

        return *this;
    } 
};



int main()
{
    Cents cents1(6);
    Cents cents2(8);
    
    std::cout << (cents1 + cents2).getCents() << std::endl;
}