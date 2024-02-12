#include<iostream>
#include<vector>
#include<algorithm>

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

    // friend bool operator < (const Cents &cents1, const Cents &cents2)
    // {
    //     if(cents1.m_cents < cents2.m_cents)
    //     {
    //         return true;
    //     }
    //     return false;
    // }
    bool operator < (const Cents &tmpCents) const
    {
        if(this->m_cents < tmpCents.m_cents)
        {
            return true;
        }
        return false;
    }
    
    bool operator == ( const Cents &tmpCents) const
    {
        if(this->m_cents == tmpCents.m_cents)
        {
            return true;
        }
        return false;
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
    Cents cents3(6);

    if(cents1 < cents2)
    {
        std::cout <<"ok" << std::endl;
    }

    if(cents1 == cents3)
    {
        std::cout <<"ok2" << std::endl;
    }

    //vector sort
    std::vector<Cents> arr(20); 
    for(unsigned i =0 ; i < 20; i++)
    {
        arr[i].getCents() = i;
    }
    
    std::random_shuffle(std::begin(arr) , std::end(arr));

    for(const auto & v : arr)
    {
        std::cout << v.getCents() <<  " ";
    }
    std::cout << std::endl;

    std::sort(begin(arr), end(arr));

    for(const auto & v : arr)
    {
        std::cout << v.getCents() <<  " ";
    }
    std::cout << std::endl;

    return 0;
}