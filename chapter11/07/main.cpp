#include<iostream>

class Base
{
private:
    int m_value;

public:
    Base(int value = 0)
    : m_value(value)
    {

    }

    void print()
    {
        std::cout <<"I am base" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived(int value = 0)
    : Base(value)
    {
    }
    
    void print()
    {
        std::cout <<"I am drived" << std::endl;
    }
    
};

int main()
{
    Base base;
    base.print();

    Derived derived;
    derived.print();

    return 0;
}