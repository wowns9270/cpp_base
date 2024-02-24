#include <iostream>

template <typename T>
class A
{

private:
    T m_data;

public:
    void print()
    {
        std::cout << m_data << std::endl;
    }

    void Set(const T &tmp)
    {
        m_data = tmp;
    }
};

template <typename T>
class A<T *>
{

private:
    T *m_data;

public:
    void print()
    {
        std::cout << *m_data << std::endl;
    }

    void Set(T *tmp)
    {
        m_data = tmp;
    }
};

int main()
{

    A<int> int_a;

    int_a.Set(123);
    int_a.print();

    // pointer type
    // 포인터 타입으로 specialization을 하고 싶으면,
    A<int *> ptr_int_a;
    int val = 345;

    ptr_int_a.Set(&val);
    ptr_int_a.print(); //  val 의 주소가 나옴.
}