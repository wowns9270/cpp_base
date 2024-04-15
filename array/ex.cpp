#include<iostream>
int gogo(int x, int y)
{
    int a = 1;
    return a;
}

int main()
{
    int* sum = (int*)gogo(1, 2);

    std::cout << *sum << std::endl;
    return 0;
}