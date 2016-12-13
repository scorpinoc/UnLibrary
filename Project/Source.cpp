#include "string.h"
#include <string>
#include <iostream>

int	main(int argc, char * argv[])
{
	UnLib::string a;

//	auto b = UnLib::string("b");

	//auto c = b;

	UnLib::string d("d");

	UnLib::string e("d", 2);
/*
	std::cout << '!' << &a << "!\n";
	std::cout << '!' << &b << "!\n";
	std::cout << '!' << &c << "!\n";*/

	system("pause");

	return 0;
}