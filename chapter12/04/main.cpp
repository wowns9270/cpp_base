#include<iostream>
#include<memory>
class Base
{
public:
    virtual ~Base()
    {
        std::cout <<"~Base()" << std::endl;
    }
};

class Derived : public Base
{
public:
    Derived(int length)
    {
        m_array = new int[length];
    }


    ~Derived()
    {
        std::cout <<"~Derived" << std::endl;
        delete[] m_array;
    }

private:
    int *m_array;
};

int main()
{
    //std::unique_ptr<Derived> d = std::make_unique<Derived>();

    Derived* d = new Derived();

    Base *b = d;

    delete b;
}