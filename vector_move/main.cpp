#include<iostream>
#include<vector>
#include<map>
#include<chrono>

struct PP
{

	int id;
	std::vector<int> prev;
	std::vector<int> next;
};




int main() {
	
	std::map<int, PP> list;
	std::map<int, PP> list2;

	std::chrono::system_clock::time_point start = std::chrono::system_clock::now();
	for (int i = 0; i < 6000000; i++)
	{
		std::vector<int> prev_t = { 1,2,3,4 };
		std::vector<int> next_t = { 4,5,6,7 };

		PP tmp = { i, std::move(prev_t), std::move(next_t) };

		
		list.insert({ i, tmp });
	}
	std::chrono::duration<double>sec = std::chrono::system_clock::now() - start;
	std::cout << "time :" << sec.count() << "seconds\n";

	//////////////////////////////////////////////////////////////////

	std::chrono::system_clock::time_point start2 = std::chrono::system_clock::now();
	for (int i = 0; i < 6000000; i++)
	{
		std::vector<int> prev_t = { 1,2,3,4 };
		std::vector<int> next_t = { 4,5,6,7 };

		PP tmp = { i, prev_t, next_t };

		list2.insert({ i, tmp });
	}
	std::chrono::duration<double>sec2 = std::chrono::system_clock::now() - start2;
	std::cout << "time :" << sec2.count() << "seconds\n";

}