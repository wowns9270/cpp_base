#include<iostream>
#include<vector>
#include<map>
#include<chrono>
#include<string>
#include "Student.hpp"

struct PP
{

	int id;
	std::vector<Student> prev;
	std::vector<Student> next;
};




int main() {


	std::map<int, PP> list;
	std::map<int, PP> list2;

	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	for (int i = 0; i < 10000000; i++)
	{
		std::vector<Student> prev_t = { Student("aa"), Student("bb")};



		std::vector<Student> next_t = { Student("aa"), Student("bb")};

		//std::cout << "check1 before" << std::endl;

		PP tmp = { i, std::move(prev_t), std::move(next_t) };
		//std::cout << "check1 after" << std::endl;
		
		//list.insert({ i, tmp });
	}
	std::chrono::duration<double>sec = std::chrono::system_clock::now() - start;
	std::cout << "time :" << sec.count() << "seconds\n";

	//////////////////////////////////////////////////////////////////

	std::chrono::system_clock::time_point start2 = std::chrono::system_clock::now();
	for (int i = 0; i < 10000000; i++)
	{
		std::vector<Student> prev_t = { Student("aa"), Student("bb")};
		std::vector<Student> next_t = { Student("aa"), Student("bb")};

		//std::cout << "check2 before" << std::endl;
		PP tmp = { i, prev_t, next_t };
		//std::cout << "check2 after" << std::endl;

		//list2.insert({ i, tmp });
	}
	std::chrono::duration<double>sec2 = std::chrono::system_clock::now() - start2;
	std::cout << "time :" << sec2.count() << "seconds\n";

}