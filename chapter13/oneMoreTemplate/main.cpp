#include <iostream>

template <typename T>
class A
{

private:
    T m_data;

public:
    // template 내부에서 한번 더 template 화 시키기
    template <typename TT>
    void print(const TT &)
    {
        std::cout << typeid(T).name() << " " << typeid(TT).name() << std::endl;
    }

    void Set(const T &tmp)
    {
        m_data = tmp;
    }
};

int main()
{

    A<int> int_a;
    int_a.Set(123);

    int_a.print<double>(123.3);
    int_a.print(123.3); // 이것도 댐
}