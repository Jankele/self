#include <iostream>
#include <chrono>


int fun()
{

	int a = 1000 * 1000;
	return a;
}
int main()
{
	using namespace std::chrono;

	high_resolution_clock::time_point t1 = high_resolution_clock::now();
		int a = fun();
		std::cout << a << std::endl;
	high_resolution_clock::time_point t2 = high_resolution_clock::now();

	auto d = duration_cast<microseconds>(t2 - t1).count();
	std::cout << d <<std::endl;
///////////////////////////////////////////
	t1 = high_resolution_clock::now();
		std::cout << fun() << std::endl;
	t2 = high_resolution_clock::now();

	d = duration_cast<microseconds>(t2 - t1).count();
	std::cout << d <<std::endl;

	return 0;
}