#include<iostream>
#include<string>
#include<vector>
#include<memory>

class Student
{

public:
	Student()
		:name("none")
	{
		std::cout << "default empty constructor" << std::endl;
	}

	explicit Student(const std::string &name)
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

	void print() const
	{
		std::cout <<name << std::endl;
	}

private:
	std::string name;
};