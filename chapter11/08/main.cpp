#include<iostream>

/// using 사용법 
/// 상속받은 클래스에서 using을 통해 접근지정을 변경가능 

class Base
{
protected:
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

public:
    using Base::m_value;
    
};

int main()
{
    Derived derived;
    derived.print();

    derived.m_value = 10;

    return 0;
}