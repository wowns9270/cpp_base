#include <iostream>
#include <vector>

class Base
{
public:
    virtual void print()
    {
        std::cout << "defualt print" << std::endl;
    };
};

class Dog : public Base
{
public:
    void print() override
    {
        std::cout << "Bark" << std::endl;
    }
};

class Cat : public Base
{
public:
    void print() override
    {
        std::cout << "meow" << std::endl;

        Action();

        for (int val : catNumber)
        {
            std::cout << val << " ";
        }
        std::cout << std::endl;
    }

    void Action()
    {
        std::cout << "cat_action" << std::endl;
    }

    std::vector<int> catNumber;
};

int main()
{
    // Base *ptr = new Dog();
    // ptr->print();

    // Base *ptr2 = new Cat();
    // ptr2->print();

    //---------------------------------------

    Cat a;

    a.catNumber.push_back(1);
    a.catNumber.push_back(2);
    a.catNumber.push_back(3);
    a.catNumber.push_back(4);

    //    Base &r = a;

    Base k = a;

    //   r.print();
    k.print();
}