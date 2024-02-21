
// 클래스 탬플릿의 특정 함수를  specialization 하는 방법

#include <iostream>

template <typename T, int size>
class StaticArray_Base
{

private:
    T m_data[size];

public:
    void print()
    {

        for (int i = 0; i < size; i++)
        {
            std::cout << (*this)[i] << " ";
        }

        std::cout << std::endl;
    }

    T &operator[](int idx)
    {
        return m_data[idx];
    }
};

template <class T, int size>
class StaticArray : public StaticArray_Base<T, size>
{
};

template <int size>
class StaticArray<char, size> : public StaticArray_Base<char, size>
{
public:
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            std::cout << (*this)[i];
        }

        std::cout << std::endl;
    }
};

int main()
{

    StaticArray<int, 4> int_arr;

    int_arr[0] = 1;
    int_arr[1] = 2;
    int_arr[2] = 3;
    int_arr[3] = 4;

    int_arr.print();

    // 여기서 char 형식에 대해서는 띄어쓰기가 없었으면 좋겠다.  ( print 함수 참고 )

    // char 형식에 대해서는 문자간의 띄어쓰기가 없도록 구현하라.
    StaticArray<char, 5> char_arr;

    char_arr[0] = 'h';
    char_arr[1] = 'e';
    char_arr[2] = 'l';
    char_arr[3] = 'l';
    char_arr[4] = 'o';

    char_arr.print();
}