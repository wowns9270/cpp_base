#include<iostream>
class Animal
{
    public:
        virtual void playsound()
        {
            //
        }

};

class Dog : public Animal
{
    public:
        void playsound() override
        {
           std::cout << "bark" << std::endl;
        }
};

class Cat : public Animal
{
    public:
        void playsound() override
        {
            std::cout << "meow" << std::endl;
        }
};

class Pig : public Animal
{
    public:
        void playsound() override
        {
            std::cout << "ggol" << std::endl;
        }
};


void playAnimalSound(Animal * pAnimal)
{
    pAnimal->playsound();
    // 미래에 추가될 타입에 대해서도 큰 변화 없이 기존 코드로 대응 가능하다. 

    // 실제타입으로 변환해줘야되고, 비효율,
}

int main()
{

    Animal *d = new Dog();
    playAnimalSound(d);

    Animal *c = new Cat();
    playAnimalSound(c);

    Animal *p = new Pig();
    playAnimalSound(p);

}