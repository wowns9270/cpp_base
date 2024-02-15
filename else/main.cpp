#include<iostream>
#include<vector>
class Object
{
public:
    Object()
    {
        std::cout <<"Object Constructor" << std::endl;
    }

    ~Object()
    {
        std::cout <<"Object destructor" << std::endl;
    }
    std::vector<int> list;
};

class Object2
{
public:
    Object2()
    {
        std::cout <<"Object2 Constructor" << std::endl;
    }

    Object2(const int &a)
    {
        std::cout <<"Object2 Constructor" << a << std::endl;
    }

    ~Object2()
    {
        std::cout <<"Object2 destructor" << std::endl;
    }

public:
    int a;
};


class Base
{
public:
    Base()
    : object2(3)
    {
        std::cout <<"Base Constructor " << std::endl;
    }

    ~Base()
    {
        std::cout << "Base Destructor " << std::endl;
    }

private:
    Object object;
    Object2 object2;
};

int main()
{
    Base b;

    std::cout << sizeof(Object) << std::endl;


    std::cout << sizeof(std::vector<int>) << std::endl; // 벡터의 크기 24 

    // size 
    // capacity 
    // 포인터 
}

