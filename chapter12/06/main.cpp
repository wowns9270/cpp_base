#include <iostream>

class Base
{
public:
    virtual void printA()
    {
        std::cout <<"Base printA" << std::endl;
    }

    virtual void printB()
    {
        std::cout <<"Base printB" << std::endl;
    }

};

class Derived : public Base
{    
public:
    virtual void printA()
    {
        std::cout <<"Derived printA" << std::endl;
    }

    void virtual printC()
    {
        std::cout <<"Derived printc" << std::endl;
    }
};

int main()
{
    Derived *d  = new Derived();

    Base *b = d;

//     b->printA(); // derived print A 
//     b->printB(); // base print B

// //    b->printC(); // ERROR

//     d->printC();
    std::cout <<sizeof(Base) << std::endl;
    std::cout <<sizeof(Derived) << std::endl;
}