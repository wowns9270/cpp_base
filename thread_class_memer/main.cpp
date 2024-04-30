#include<iostream>
#include<thread>

class PP
{
public:
	void gogo(int& a , int& b) {
		std::cout << a <<" " << b << " " << r << std::endl;
	}

	int r;
};

int main() {

	int a = 10;
	int b = 5;

	PP tmp;
	tmp.r = 55;

	//std::thread crateThread(gogo, std::ref(a), std::ref(b));
	std::thread crateThread(&PP::gogo, &tmp, std::ref(a), std::ref(b));

	crateThread.join();
	std::cout << a << " " << b << std::endl;


	std::cout << "end" << std::endl;

}
