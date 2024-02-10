
#include "../include/AutoPtr.hpp"
#include "../include/Resource.hpp"


AutoPtr<Resource> generateResource()
{
    AutoPtr<Resource> res(new Resource(10000000));
    // resource cotr 
    // auto default ( *ptr ) cotr 


    return res;
}

int main()
{
    using namespace std;

    streambuf* orig_buf = cout.rdbuf();

    //Timer timer;

    {
        AutoPtr<Resource> main_res;
        // auto cotr

        main_res = generateResource();
        // auto copy assignment
            // resoucre cotr
            // resource copy assignment

        // auto move assignment 

        // auto destroy
        // resource destroy
    }
    // auto destroy
    // resource destroy


    // cout.rdbuf(orig_buf);
    // cout << timer.elapsed() << endl;

    return 0;
}