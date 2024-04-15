#include<iostream>
class Parent
{
    public:
    Parent(){};

    virtual void vFunc()
    {
        std::cout << "p func" << std::endl;
    }

    int m_p;
};

class Child : public Parent
{
    public:
        Child(){};

        void vFunc() override
        {
            std::cout <<"c func" << std::endl;
        }

    int m_c;
};

int main()
{
    // Child c;
    // Parent * p = &c;

    // p->vFunc(); // ( 5 )

    Child c;
    Parent p = c;
    p.vFunc();

    Parent &p2 = c;
    p2.vFunc();

}

