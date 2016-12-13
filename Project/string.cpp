#include "string.h"

#include <string.h>
#include <exception>
#include <stdexcept>

namespace UnLib
{
	string::string() : string("", 0)
	{ }

	string::string(const char* str) : string(str, strlen(str))
	{}

	string::string(const char* str, size_t size)
		try : str_(nullptr)
	{
		if (size == npos)
			throw std::length_error("string too long");

		str_ = static_cast<char*>(calloc(size, sizeof(char)));
		strcpy_s(str_, strlen(str) * sizeof(char), str);
	}
	catch (const std::exception&)
	{
		if (str_) free(str_);
		throw;
	}

	string::~string()
	{
		if (str_) free(str_);
	}
}
