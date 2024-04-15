#include<iostream>
typedef int INT_THREE_ARR[3];

int main()
{
    INT_THREE_ARR k;

    k[0] = 1;
    k[1] = 2;
    k[2] = 3;

    std::cout << k[0] << " " << k[1] << " " << k[2];

}