#include<iostream>

class PP
{

public:
    PP()
    {
        a= 0 ;
        b= 0;
        std::cout <<"default constructor" << std::endl;
    }
    PP(const PP& tmp)
    {
        a = tmp.a;
        b = tmp.b;
        std::cout <<"copy constructor" << std::endl;
    }

public:
    int a; 
    int b;
};

PP gogo()
{
    PP tmp;
    tmp.a = 10;
    tmp.b = 15;
    if(tmp. a== 10)
    {
        return tmp;
    }
    else
    {
        PP tmp2;
        tmp.a = 12;
        return tmp2;
    }
    return tmp;
}

int main()
{
    const PP& ret = gogo();

    std::cout << ret.a << std::endl;
    std::cout << ret.b << std::endl;
}
