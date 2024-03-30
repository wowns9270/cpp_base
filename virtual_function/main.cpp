#include<iostream>
class CParent
{
public:
    void func()
    {
        std::cout << "parent func" << std::endl;
    }

    virtual void vFunc()
    {
        std::cout <<"parent v func" << std::endl;
    }

    int m_p;
};

class CChild : public CParent
{
    void func()
    {
        std::cout << "child func " << std::endl;
    }

    virtual void vFunc()
    {
        std::cout <<"child v func" << std::endl;
    }

    int m_c;
};

int main()
{
    CParent *p = new CChild(); // (1)

    p->func();  // (2)
    p->vFunc();  // (3)

    delete p;
}