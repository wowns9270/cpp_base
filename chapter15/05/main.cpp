#include <memory>
#include "../include/Resource.hpp"


void doSomething2(std::unique_ptr<Resource> &res)
{
    res->setAll(10);
}

int main()
{
    // ex1
    // {
    //     //Resource *res = new Resource(1000000);

    //     std::unique_ptr<Resource> res ( new Resource(1000000));
    // }

    // {
    //     std::unique_ptr<int> upi(new int);

    //     //std::unique_ptr<Resource> res1(new Resource(5));
    //     auto res1 = make_unique<Resource>(5);

    //     std::unique_ptr<Resource> res2;

    //     std::cout << std::boolalpha;
    //     std::cout << static_cast<bool>(res1) << std::endl;
    //     std::cout << static_cast<bool>(res2) << std::endl;

    //     res2 = std::move(res1);

    //     std::cout << static_cast<bool>(res1) << std::endl;
    //     std::cout << static_cast<bool>(res2) << std::endl;
    // }

    {
        auto res1 = std::make_unique<Resource>(5);
        res1->setAll(1);
        res1->print();

        doSomething2(res1);

        res1->print();   
    }


}