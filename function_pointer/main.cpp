#include<iostream>

int (*func)(int a, int b);

int sum(int a, int b)
{
    return a+ b;
}

int main()
{
    func = sum;

    std::cout << func(1,2);
}