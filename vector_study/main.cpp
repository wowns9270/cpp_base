#include "MyVector.hpp"
#include "Student.hpp"
#include <vector>


class PP
{
    void print()
    {
        std::cout <<"hello" << std::endl;
    }
};

int main()
{
//     std::cout <<"start process" << std::endl;
//     Student p;
    
//     {
//     std::cout <<"start block" << std::endl;

//         MyVector<Student> a;
//         a.emplace_back(p);

//         std::cout <<"end block" << std::endl;
//     }
//     std::cout <<"end process" << std::endl;


// /////////////////////////////////////////////////////
//     std::vector<Student> _vec;

//     _vec.emplace_back("a");


//    std::cout << sizeof(PP) << std::endl;


    Student pp("aaa");

    Student qq("xxx") ;

//    std::cout <<"############" << std::endl;
//    qq = std::move(pp);

//    qq.print();


    std::cout <<"############" << std::endl;
    std::swap(pp, qq);

    pp.print();


}