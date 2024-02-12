#include <string>
#include <vector>
#include "../include/Resource.hpp"
#include "../include/AutoPtr.hpp"

template<class T>
void MySwap(T &a, T &b)
{
    // T tmp = a; // copy constr
    // a = b;    // copy assign
    // b = tmp; // copy assign

    T tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

int main()
{
    //ex1
    // {
    //   AutoPtr<Resource> res1(new Resource(10000000));

    //     std::cout << res1.m_ptr << std::endl;

    //     AutoPtr<Resource> res2 = std::move(res1);

    //     std::cout << res1.m_ptr << std::endl;
    //     std::cout << res2.m_ptr << std::endl;
    // }  

    // {
    //     AutoPtr<Resource> res1(new Resource(3));
    //     res1->setAll(3);

    //     AutoPtr<Resource> res2(new Resource(5));
    //     res2->setAll(5);

    //     res1->print();
    //     res2->print();

    //     MySwap(res1, res2);

    //     res1->print();
    //     res2->print();
    // }

    {
        std::vector<std::string> v;
        std::string str = "Hello";

        v.push_back(str);

        std::cout << str << std::endl;
        std::cout << v[0] << std::endl;

        v.push_back(std::move(str));

        std::cout << str << std::endl;
        std::cout << v[0] << " " << v[1] << std::endl;
    }


}