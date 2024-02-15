#include<iostream>
#include<string>

class Animal
{

protected:
    std::string m_name;

public:
    Animal(std::string name)
    :m_name(name)
    {
        std::cout << "Animal constructor" << std::endl;
    }

    std::string getName() const
    {
        return m_name;
    }

    virtual void speak() const 
    {
        std::cout << m_name << " ??? " << std::endl;
    }
};

class Cat : public Animal
{
public:
    Cat(std::string name)
    : Animal(name)
    {
        std::cout << "Cat constructor" << std::endl;
    }

    void speak() const 
    {
        std::cout << m_name << " Meow" << std::endl;
    }
};

class Dog : public Animal
{

public:
    Dog ( std::string name)
    : Animal(name)
    {
        std::cout <<"Dog Constructor" << std::endl;
    }

    void speak() const 
    {
        std::cout << m_name << " Woof" << std::endl;
    }
};

int main()
{
    Animal animal("my animal");
    Cat cat("my cat");
    Dog dog("my dog");

    // animal.speak();
    // cat.speak();
    // dog.speak();

    Animal *ptr_animal1 = &cat;
    Animal *ptr_animal2 = &dog;

    ptr_animal1->speak();
    ptr_animal2->speak();
}
