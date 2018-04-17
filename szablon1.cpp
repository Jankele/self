#include <iostream>
#include <vector>


template <size_t size, typename T, bool isIt>
class Array
{
	if(isIt)
		std::vector <T> _w; 
	else
		std::array <T> _a;
public:
	Array<T>& operator[](const std::vector)
};


template <typename T, unsigned const n>
class klasa
{
	std::vector<T> _a;
public:

	klasa(std::vector<T> a) : _a(a){}

	klasa(klasa &a)
	{
		_a = a._a;
		std::cout << "siema jestem konstruktorem kopiujacym hehe pieczolke :)" << std::endl;
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


int main()
{
	std::vector<int> w = {5, 5, 5, 5, 5};
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

	return 0;
}