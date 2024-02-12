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

    Cents operator - () const 
    {
        return Cents( - m_cents);
    } 

    bool operator !() const 
    {
        if(m_cents == 0 ) return false;

        return true;
    }

    friend std::ostream& operator << ( std:: ostream &out, const Cents &cents)
    {
        out << cents.m_cents;
        return out;
    }
};



int main()
{
    Cents cents1(6);
    Cents cents2(8);
    Cents cents3(0);
    
    std::cout << -cents1 << std::endl;

    std::cout << !cents3 << std::endl;
    return 0;
}