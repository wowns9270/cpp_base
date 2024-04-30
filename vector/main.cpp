#include<vector>
#include<iostream>
int main()
{

    std::vector<int> vec;

    int& r = vec.emplace_back(4);

    r = 10;

    std::cout << vec[0] << std::endl;
}