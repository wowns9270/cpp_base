#include<iostream>

int main()
{

    double x = 10.5;
    double y = 5.5;

    int sum1 = x + y ; // narrowing conversion을 점검하지 않음.
    int sum2(x + y) ; // narrowing conversion을 점검하지 않음.

    int sum3{ x + y }; // uniform initialization

    //uniform initialization

    // 1. 가장 다양한 문맥에서 사용가능
    // 2. narrow conversion을 방지 
    // 3. 함수 선언과 객체 생성을 구분 


    //but, std::initializer_list와의 사용에서 예상치 못한 문제가 발생할 수 있음.. 

}