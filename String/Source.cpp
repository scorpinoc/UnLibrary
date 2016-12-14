#include "string.h"
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

void Creation_test();
void Sort_test(int argc, char * argv[]);

int	main(int argc, char * argv[])
{
	//Creation_test();

	char* c[] = { "test", "data", "string", "dd" };
	Sort_test(4, c);

	//Sort_test(argc, argv);

	return 0;
}

void Creation_test()
{
	auto print = [](UnLib::string str, const char * name, const char * result)
	{
		std::cout << name << ": |" << str << "|  - " << result << std::endl;
	};

	UnLib::string b("b");
	print(b, "b", "b");

	auto c = b;
	print(c, "c", "b - copy from 'b'");

	UnLib::string d("d", 1);
	print(d, "d", "d");

	UnLib::string e("e", 5);
	print(e, "e", "e and 4 more symbols");

	e.swap(d);
	print(d, "d", "e - swaped with 'd'");
	print(e, "e", "d - swaped with 'e'");

	UnLib::string f("fffff", 2);
	print(f, "f", "fffff trimed to 2 symbols");

	UnLib::string g("");
	print(g, "g", "empty string");

	auto h(UnLib::string("h"));
	print(h, "h", "h");

	auto i(std::move(h));
	print(h, "h", "empty|null after std::move");
	print(i, "i", "h");

	auto j = std::move(i);
	print(i, "i", "empty|null after std::move");
	print(j, "j", "h");

	system("pause");
}

void Sort_test(int argc, char * argv[])
{
	if (argc < 2)
	{
		std::cout << "wrong init data";
		system("pause");
		return;
	}
	std::vector<UnLib::string> data(argc - 1);
	for (auto i = 1; i < argc; i++)
		data.push_back(argv[i]);
	std::sort(data.begin(), data.end(), [](UnLib::string a, UnLib::string b) {return a.compare(b, false) < 0; });
	system("pause");
}
