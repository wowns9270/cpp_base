
// 상속

#include <iostream>

class Mother
{
private:
    int m_i;

public:
    Mother(const int &i_in)
        : m_i(i_in)
    {
        std::cout << "Mother cotr" << std::endl;
    }

    void setValue(const int &i_in)
    {
        m_i = i_in;
    }

    int getValue()
    {
        return m_i;
    }
};

class Child : public Mother
{
private:
    double m_d;

public:
    Child(const int &i_in, const double d_in)
        : Mother(i_in), m_d(d_in)
    {
        std::cout << "Child cotr" << std::endl;
    }

    void setValue(const int &i_in, const double &d_in)
    {
        Mother::setValue(i_in);
        m_d = d_in;
    }

    void setValue(const double &d_in)
    {
        m_d = d_in;
    }

    double getValue()
    {
        return m_d;
    }
};

int main()
{
    // Mother mother;
    // mother.setValue(1024);
    // std::cout << mother.getValue() << std::endl;

    Child child(1024, 128);
    // child.Mother::setValue(2048);
    // child.setValue(128);
    std::cout << child.Mother::getValue() << std::endl;
    std::cout << child.getValue() << std::endl;

    return 0;
}