#include <iostream>
#include <vector>
#include <array>
#include <functional>
#include <cstring>
#include <algorithm>

/*template < typename T>
class String
{
	std::vector<T> _w;
public:
	String()
	{
		_w.push_back("test");
	}
	String& operator+=(String<T> w)
	{
		std::vector<T> final;
		std::merge(_w.begin(), _w.end(), w.begin(), w.end(), final.begin());
		return final;
	}
	bool operator==(String<T> w)
	{
		if(_w == w)
			return true
		else
			return false;
	}
};*/

template <std::size_t size, typename T, bool isItVector>
class Array
{
	std::vector <T> _w;
	std::array <T,size> _a;

public:
	Array()
	{
		if(isItVector)
		{
			for(int i=0;i<size;i++)
				_w.push_back(i);
		}
		else
		{
			for(int i=0;i<size;i++)
				_a.fill(i);
		}
	}
	T& operator[](std::size_t it)
	{
		if(isItVector)
			return _w.at(it);
		else
			return _a.at(it);
	}
	T Begin()
	{
		if(isItVector)
			return *begin(_w);
		else
			return *begin(_a);
	}
	T End()
	{
		if(isItVector)
			return *(end(_w)-1);
		else
			return *(clrend(_a)-1);
	}
	T Max()
	{
		if(isItVector)
			return *std::max_element(begin(_w), end(_w));
		else
			return *std::max_element(begin(_a), end(_a));

	}
	T Min()
	{
		if(isItVector)
			return *std::min_element(begin(_w), end(_w));
		else
			return *std::min_element(begin(_a), end(_a));
	}
	void wypisz()
	{
		if(isItVector) 
		{
			for(T& i : _w)
				std::cout << i << " ";
			std::cout << std::endl;
		}
		else
		{
			for(T& i : _a)
				std::cout << i << " ";
			std::cout << std::endl;
		}
	}
};


/*template <typename T, unsigned const n>
class klasa
{
	std::vector<T> _a;
public:

	klasa(std::vector<T> a) : _a(a){}

	klasa(klasa &a)
	{
		_a = a._a;
		std::cout << "siema jestem konstruktorem kopiujacym" << std::endl;
	}

	void wypelnij(T a)
	{
		for(int i=0;i<n;i++)
			_a.push_back(a);
	}
	void wypisz()
	{
		for(int i=0;i<n;i++)
		std::cout << "a = : " << _a[i] << std::endl;	
	}
};

typedef klasa <std::string, 2> klasastring;
typedef klasa <float, 4> klasafloat;
*/

int main()
{
/*	std::vector<int> w = {5, 5, 5, 5, 5};
	klasa <int, 5> obj1(w);
	klasa <int, 5> obj2 = obj1;
	klasa <int, 5> obj3(obj2);
	//klasafloat obj2(2.3);
	//klasastring obj3("asd");
	
	//obj.wypelnij(5);
	std::cout << "klasa1 " << std::endl;
	obj1.wypisz();
	//obj2.wypelnij(2.3);
	std::cout << std::endl << "klasa2 " << std::endl;
	obj2.wypisz();
	obj3.wypisz();
	//obj3.wypelnij("asasdas");
	//obj3.wypisz();
*/
	Array <10,int,1> obj;
	std::cout << "Obiekt1" << std::endl;
	obj.wypisz();
	Array <5,int,0> obj2;
	std::cout << "Obiekt2" << std::endl;
	obj2.wypisz();
	std::cout << "Obiekt1" << std::endl;
	std::cout << obj.Max() << std::endl;
	std::cout << obj.Min() << std::endl;
	std::cout << "Obiekt2" << std::endl;
	std::cout << obj2.Max() << std::endl;
	std::cout << obj2.Min() << std::endl;
	std::cout << "Obiekt1" << std::endl;
	std::cout << obj.Begin() << std::endl;
	std::cout << obj.End() << std::endl;
	std::cout << "Obiekt2" << std::endl;
	std::cout << obj2.Begin() << std::endl;
	std::cout << obj2.End() << std::endl;
	return 0;
}