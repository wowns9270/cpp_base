class Parent
{
    public:
        virtual ~Parent()
        {

        }
};

class Child : public Parent
{
    public:
        ~Child()
        {

        } 
};

int main()
{
    Parent *p = new Child();
    delete p;
}
