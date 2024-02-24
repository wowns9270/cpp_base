#include <iostream>
#include <math.h>

int main()
{
    // 예외처리 try, catch, throw

    double x;
    std::cin >> x;

    try
    {
        if (x <= 0.0)
        {

            throw 1.0f;
            // throw "negative input";
            //  throw std::string("negative input");
        }

        std::cout << std::sqrt(x) << std::endl;
    }
    catch (double e)
    {
        std::cerr << "double" << e << '\n';
    }
    catch (float e)
    {
        std::cerr << "float" << e << '\n';
    }
    catch (std::string e)
    {
        std::cerr << e << '\n';
    }
    catch (const char *e)
    {
        std::cerr << e << '\n';
    }

    return 0;
}