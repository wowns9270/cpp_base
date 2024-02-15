#include<iostream>

class A  
{
public:
    virtual void print() const
    {
        std::cout <<"A" << std::endl;
    }
};

class B : public A
{
public:
    void print() const 
    {
        std::cout <<"B" << std::endl;
    }
};

class C : public B 
{
public:
    void print() const
    {
        std::cout <<"C" << std::endl;
    }
};

class D : public C
{
public:
    void print() const
    {
        std::cout << "D" << std::endl;    
    }
};


int main()
{
    A a; 
    //a.print();

    B b;
    //b.print();

    C c; 
    //c.print();

    D d;
    //d.print();

    const A &ref = b;

    ref.print();
}