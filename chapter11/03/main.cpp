 
#include <iostream>

class Mother
{
public:
    int m_i;

    Mother(const int& i_in = 0)
    :m_i(i_in)
    {
        std::cout << "Mother Constr" << std::endl;
    }
};

class Child : public Mother
{

public:
    double m_d;

    Child()
    :Mother(1024)
    ,m_d(1.0)
    {
        //this->Mother::m_i = 2;

        std::cout << "Child Constr" << std::endl;
    }
};

int main()
{
    Child c1;
}
