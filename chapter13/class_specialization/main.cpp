#include<iostream>
#include "../source/Storage8.h"

using namespace std;


template<typename T> 
class A
{
public:
    void doSomething()
    {
        std::cout << typeid(T).name() << endl;
    }

    void test()
    {
        std::cout <<"test"<< std::endl;
    }
};

//class specialization
template<>
class A<char>
{
public:
    void doSomething()
    {
        std::cout <<"Char type specialization " << std::endl;
    }
};

int main()
{
    A<int> a_int;
    A<double> a_double;
    A<char> a_char;

    a_int.doSomething();
    a_double.doSomething();
    a_char.doSomething();

    a_int.test();
    //c_char.test(); error

    unsigned char a = 16;
    unsigned char b = ~a;
    //std::cout << ~a << std::endl;

    Storage8<bool> t;

    t.set(6, true);
    std::cout <<t.print(6) << std::endl;


    t.set(4, true);
    std::cout <<t.print(4) << std::endl;

    t.set(4, false);
    std::cout <<t.print(4) << std::endl;
}