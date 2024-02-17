#include<iostream>
#include<functional>


int add (int x, int y)
{
    return x + y ;
}

int main()
{

    // 정적 바인딩
    int ret = add(1, 4);
    std::cout << ret << std::endl;


 

   // 동적 바인딩
   //int (*func)(int , int) = nullptr;
   std::function<int(int, int)> func2;

    // ~~ ing 
    // ~~ ing 

   func2 = add;  // 상황에 따라, 해당 함수 호출이 필요한 경우
   std::cout << func2( 1,  5) << std::endl;
}