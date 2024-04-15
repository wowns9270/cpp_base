#include <iostream>
void *get();

struct Man
{
    int age;
    int grade;
    int score;
};

void gogo(Man **pptr)
{
    Man *tmpPtr = nullptr;

    void *getShm = get(); // shd mem? offset ?? buffer ??

    tmpPtr = static_cast<Man *>(getShm);

    *pptr = tmpPtr;
}

void *get()
{
    Man *ptr = new Man();
    ptr->age = 10;
    ptr->grade = 5;
    ptr->score = 3;

    return static_cast<void *>(ptr);
}

void gogo2(Man *ptr)
{
    ptr = new Man();
    ptr->age = 10;
}

int main()
{
    Man *ptr = nullptr;

    gogo(&ptr);

    std::cout << ptr->age << std::endl;
    std::cout << ptr->grade << std::endl;
    std::cout << ptr->score << std::endl;

    Man *ptr2 = nullptr;
    gogo2(ptr);
}