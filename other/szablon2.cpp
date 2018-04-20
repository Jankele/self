#include <iostream>
#include <vector>
#include <cmath>
/*
template <typename T1, typename T2>
std::vector<T1> powVector(std::vector<T1> &w, T2 pot)
{
	for(T1 &i : w)
	{
		i = std::pow(i,pot);
	}
	return w;
}
*/
enum operation
{
	Replace = 0,
	Append
};

void Clamp(std::vector<int>& input, std::vector<int>& output, int& hi, int& lo, operation arg)
{
	switch(arg)
	{
		case 0:
		{
			for(int i=1;i<input.size();i++)
			{
				if(input[i] < lo)
					output[i] = lo;
				if(input[i] > hi)
					output[i] = hi;
			}
		}
		break;
		case 1:
		{
			output.reserve(input.size());
			for(int i=0;i<input.size();i++)
			{
				if(input[i] < lo)
				{
					output.push_back(lo);
					continue;
				}
				if(input[i] > hi)
				{
					output.push_back(hi);
					continue;
				}
				output.push_back(input[i]);
			}
		}
		break;
		default:
			std::cout << "Nieprawidłowa opcja" <<std::endl;
		break;
	}
}

int main()
{
	std::vector<int> input = {1,2,3,4,5};
	std::vector<int> output = {2,3,4,5,6};
	int hi = 4;
	int lo = 2;
	operation arg = Replace;
	Clamp(input, output, hi, lo, arg);
	for(int& i : input)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	for(int& i : output)
	{
		std::cout << i << " ";
	}
	std::cout << std::endl;
	return 0;
	/*int pot = 2;
	std::vector<float> _w = {2,3,4,5};
	powVector<float, int>(_w, pot);
	for(float &i : _w)
		std::cout << i << std::endl;
	return 0;*/
}