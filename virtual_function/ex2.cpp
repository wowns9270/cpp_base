class Test
{
public:
    void func1(){   

    }
    void func2()
    {

    }

    virtual void vfunc1()
    {

    }

    virtual void vfunc2()
    {

    }
};

int main()
{
    Test t;
    Test *p = &t;

    p->func1();  // ( 1 )
    p->vfunc1(); // ( 2 )
}

