#include "string.h"
#include <string>
#include <iostream>

void Test();

int	main(int argc, char * argv[])
{
	Test();

	return 0;
}

void Test()
{
	auto print = [](UnLib::string str, const char * name)
	{
		if (str.data())
			std::cout << name << ": !" << str << "! " << std::endl;
		else
			std::cout << name << " is null" << std::endl;
	};

	UnLib::string a;
	print(a, "a");

	auto b = UnLib::string("b");
	print(b, "b");

	auto c = b;
	print(c, "c");

	UnLib::string d("d", 1);
	print(d, "d");

	UnLib::string e("e", 5);
	print(e, "e");

	e.swap(d);
	print(d, "d");
	print(e, "e");

	UnLib::string f("");
	print(f, "f");

	auto g(UnLib::string("g"));
	print(g, "g");

	auto h(std::move(g));
	print(g, "g");
	print(h, "h");

	auto i = std::move(h);
	print(h, "h");
	print(i, "i");

	system("pause");
}