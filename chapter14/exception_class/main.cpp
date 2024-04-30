#include <iostream>

class Exception
{
public:
    virtual void report() const
    {
        std::cout << "error report" << std::endl;
    }
};

class ArrayEeception : public Exception
{
public:
    void report() const override
    {
        std::cout << "error array report" << std::endl;
    }
};

class MyArray
{
private:
    int m_data[5];

public:
    int &operator[](const int &index)
    {
        if (index < 0 || index >= 5)
            throw ArrayEeception();

        return m_data[index];
    }
};

void doSomething()
{
    MyArray my_array;

    try
    {
        my_array[100];
    }
    catch (const Exception &e)
    {
        e.report();
        throw e // rethrow
    }
}

int main()
{
    try
    {
        doSomething();
    }
    catch (const Exception &e)
    {
        e.report();
    }

    return 0;
}