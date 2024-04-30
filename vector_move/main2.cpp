#include<iostream>
#include<boost/shared_ptr.hpp>
#include<thread>
#include<vector>

class Ptr
{
public:
	Ptr() {};

	~Ptr() {
		std::cout << "destructor call" << std::endl;

		if (p != nullptr)
		{
			delete[] p;
			p = nullptr;
		}
	}

	Ptr(const Ptr& tmp)
	{
		std::cout << "ptr copy constructor" << std::endl;

		p = new int[tmp.ptr_num];
		ptr_num = tmp.ptr_num;
		for (int i = 0; i < tmp.ptr_num; i++)
		{
			p[i] = tmp.p[i];
		}

	}

	Ptr(Ptr&& tmp) noexcept
	{
		std::cout << "ptr move constructor" << std::endl;
		if (this == &tmp)
		{
			return;
		}

		std::swap(p, tmp.p);
		std::swap(ptr_num, tmp.ptr_num);
	
	}

	int* p = nullptr;
	int ptr_num;
};

class PP
{
public:
	PP() {};

	void set(std::string a)
	{
		str = a; 
	}

	void print()
	{
		std::cout << str << std::endl;
	}

	// 컴파일러가 제공하는 복사 생성자 호출
	//{
			// std::string  ( 이동 생성자 호출 ) 
	//}

private:
	std::string str;

public:
	Ptr ptr;
	/// 사용자 정의를 맴버로 가지고 있으면 그에맞는 이동 연산을 구현
	// primary type의 경우는 복사만 발생한다 ( 값복사 ) 

	/// 사용자 정의 객체  포인터는 ? 
};

int main() {

	//PP a;
	//a.set("aaa");

	//PP b = std::move(a); // 컴파일러가 제공하는 복사 생성자 호출
	//
	//a.print();
	//b.print();

	//PP a;
	//a.ptr.p = new int[5];
	//a.ptr.ptr_num = 5;
	//
	//for (int i = 0; i < 5; i++)
	//{
	//	a.ptr.p[i] = i + 1;
	//}

	//PP b = std::move(a);

	//std::cout << a.ptr.ptr_num << std::endl;
	//
	//if (a.ptr.p == nullptr)
	//{
	//	std::cout << "nullptr" << std::endl;
	//}

	//std::cout << std::endl;

	//for (int i = 0; i < 5; i++)
	//{
	//	std::cout << b.ptr.p[i] << " ";
	//}
	//std::cout << b.ptr.ptr_num << std::endl;
	//std::cout << std::endl;


	Ptr a1;
	a1.p = new int[5];
	a1.p[0] = 1;
	a1.p[1] = 2;
	a1.p[2] = 3;
	a1.p[3] = 4;
	a1.p[4] = 5;

	a1.ptr_num = 5;


	Ptr a2;
	a2.p = new int[5];
	a2.p[0] = 1;
	a2.p[1] = 2;
	a2.p[2] = 3;
	a2.p[3] = 4;
	a2.p[4] = 5;

	a2.ptr_num = 5;



	std::vector<Ptr> v1;
	//v1.reserve(5);
	//v1.push_back(a1);
	v1.push_back(std::move(a1));
	v1.push_back(std::move(a2));

	v1[0].p[2] = 10;
	for(int i=0; i<5; i++)
	{
		std::cout << v1[0].p[i] << " ";
	}


}
