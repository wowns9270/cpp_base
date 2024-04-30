#include<memory>
#include<iostream>

class Student
{

public:
	Student()
		:name("none")
	{
		std::cout << "default empty constructor" << std::endl;
	}

	Student(const std::string &name)
		:name(std::move(name))
	{
		std::cout << "default  constructor" << std::endl;
	}

	~Student()
	{
		std::cout << "default destructor" << std::endl;
	}

	Student(const Student &tmp)
	{
		std::cout << "copy constructor " << std::endl;

		name = tmp.name;
	}

	Student(Student &&tmp) noexcept
	{
		std::cout << "move constructor " << std::endl;

		name = std::move(tmp.name);
	}

	Student& operator =(const Student &tmp)
	{
		std::cout << "copy assignement " << std::endl;
		name = tmp.name;

        return *this;
	}

	Student& operator =(Student &&tmp) \
	{
		std::cout << "move assignement" << std::endl;
		name = std::move(tmp.name);

        return *this;
	}
	std::string name;
private:
};


int main()
{
    std::allocator<Student> alloc;

    Student *ptr = alloc.allocate(5);

    ptr[0].name = "aa";
    ptr[1].name = "bb";
    ptr[2].name = "cc";
    ptr[3].name = "dd";
    ptr[4].name = "ee";

    alloc.deallocate(ptr,5);
}