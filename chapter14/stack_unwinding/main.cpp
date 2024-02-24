
// stack 되감기.

// throw 이후에 catch를 잡을 때까지 unwinding ( int로 throw 할 경우 , first 의 catch 까지 unwiding)
#include <iostream>

void last()
{
    std::cout << "last start" << std::endl;

    throw -1;

    std::cout << "last end" << std::endl;
}

void third()
{
    std::cout << "third start" << std::endl;

    try
    {
        last();
    }
    catch (double e)
    {
        std::cerr << "thrid" << e << '\n';
    }

    std::cout << "third end" << std::endl;
}

void second()
{
    std::cout << "second start" << std::endl;

    try
    {
        third();
    }
    catch (double e)
    {
        std::cerr << "second" << e << '\n';
    }

    std::cout << "second end" << std::endl;
}

void first()
{
    std::cout << "first start" << std::endl;

    try
    {
        second();
    }
    catch (int e)
    {
        std::cerr << "first" << e << '\n';
    }

    std::cout << "first end" << std::endl;
}

int main()
{

    std::cout << "main start" << std::endl;

    try
    {
        first();
    }
    catch (...) // catch all exception
    {
        std::cerr << "main catch" << '\n';
    }

    std::cout << "main end" << std::endl;
}