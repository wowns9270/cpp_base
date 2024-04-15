#include<iostream>
#include "Resource.hpp"
#include "AutoPtr.hpp"

void doSomething()
{
    //Resource *res = new Resource;
    AutoPtr<Resource> res(new Resource());


    //delete res;
    return ;
}

int main()
{
    doSomething();
}