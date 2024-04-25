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
#ifdef LOG_ENABLE
		std::cout << "default empty constructor" << std::endl;
#endif
	}

	Student(const std::string& name)
		:name(std::move(name))
	{
#ifdef LOG_ENABLE
		std::cout << "default  constructor" << std::endl;
#endif
	}

	~Student()
	{
#ifdef LOG_ENABLE
		std::cout << "default destructor" << std::endl;
#endif
	}

	Student(const Student& tmp)
	{
#ifdef LOG_ENABLE
		std::cout << "copy constructor " << std::endl;
#endif
		name = tmp.name;
	}

	Student(Student&& tmp) noexcept
	{
#ifdef LOG_ENABLE
		std::cout << "move constructor " << std::endl;
#endif
		name = std::move(tmp.name);
	}

	Student& operator =(const Student& tmp)
	{
#ifdef LOG_ENABLE
		std::cout << "copy assignement " << std::endl;
#endif
		name = tmp.name;

		return *this;
	}

	Student& operator =(Student&& tmp) \
	{
#ifdef LOG_ENABLE
		std::cout << "move assignement" << std::endl;
#endif
		name = std::move(tmp.name);

		return *this;
	}

	void print() const
	{
#ifdef LOG_ENABLE
		std::cout << name << std::endl;
#endif
	}

private:
	std::string name;
};