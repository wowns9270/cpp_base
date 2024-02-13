#include<iostream>
#include<string>
#include<vector>
#include<algorithm>

class Object
{
public:
    void hello(const std::string &s)
    {
        std::cout <<"Hello " << s << std::endl;
    }
};

void goodbye(const std::string &s)
{
    std::cout << "Goodbye " << s << std::endl;
}

int main()
{
    // lamda-introducer 
    // lamda-parameter-declaration
    // lamda-return-type-clause
    // compund-statement

    auto func = [](const int& i) ->void 
    { 
        std::cout <<"Hello, World!" << std::endl;
    };

    func(123);

    [](const int& i) ->void 
    {
        std::cout << "Hello, World2!" << std::endl;
    }(123);

    {
        std::string name = "JackJack";
        [&]() -> void 
        {
            std::cout << name << std::endl;
        }();
    }

    std::vector<int> v;
    v.push_back(1);
    v.push_back(2);

    auto func2 = [](int val) -> void
    {
        std::cout << val << std::endl;
    };

    for_each(v.begin(), v.end(), func2);


    std::cout << []() ->int { return 1; }() << std::endl;

    std::function<void(int)> func3 = func2;
    func3(1234);

    std::function<void()> func4 = std::bind(func3, 1234567);
    func4();

    Object instance;
    auto f = std::bind(&Object::hello, &instance, std::placeholders::_1);

    f(std::string("World"));

    auto f2 = std::bind(&goodbye, std::placeholders::_1);

    f2(std::string("World"));
}