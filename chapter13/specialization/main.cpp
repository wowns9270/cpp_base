#include<iostream>
#include "../source/Storage.h"

template<typename T>
T getMax(T x, T y)
{
    return x > y ? x : y;
}

template<> //template specialization
char getMax(char x, char y)
{
    std::cout << "warning : comparing chars" << std::endl;

    return x > y ? x : y;
}

int main()
{

    std::cout << getMax(1,2) << std::endl;
    //std::cout <<getMax<double>(1,2) << std::endl;

    Storage<int> nValue(5);
    Storage<double> dValue(6.5);

    nValue.print();
    dValue.print();
}