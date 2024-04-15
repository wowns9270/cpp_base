
#include<iostream>

/// 공변환 ?? 코베리언트 리턴 이거 잘 모르겠다.. 

class A 
{
public:
    void print(int x)
    {
        std::cout << "A" << std::endl;
    }

    virtual A* getThis() 
    {
        return this;
    }
};

class B : public A 
{
public:
    void print(int x) 
    {
        std::cout << "B" << std::endl;
    } 

     B* getThis() override
    {
        return this;
    }
};

class C : public B 
{
public:
    void print(int x) 
    {
        std::cout << "C" << std::endl;
    }

    C* getThis() override
    {
        return this;
    }
};

int main()
{
    A a;
    B b;

    A &ref = b;
    
    b.getThis()->print(1);
    ref.getThis()->print(1); // 이해 안감. 
    
    std::cout << typeid(b.getThis()).name() << std::endl;
    std::cout << typeid(ref.getThis()).name() << std::endl;

        std::cout << typeid(a).name() << std::endl;
    std::cout << typeid(b).name() << std::endl;
}