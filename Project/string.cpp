#include "string.h"

#include <string.h>
#include <exception>
#include <stdexcept>
#include <algorithm>

namespace UnLib
{
	string::string() : string("", 0)
	{}

	string::string(const char* str) : string(str, strlen(str))
	{}

	string::string(const char* str, size_t size)
		try : str_(nullptr)
	{
		if (size == npos)
			throw std::length_error("string too long");

		str_ = static_cast<char*>(calloc(++size, sizeof(char)));
		if (size > 1)
			strcpy_s(str_, std::min(strlen(str) + 1, size) * sizeof(char), str);
	}
	catch (const std::exception&)
	{
		clear();
		throw;
	}

	string::string(const string & obj)
		try : str_(nullptr)
	{
		if (!obj.str_) return;
		auto len = strlen(obj.str_);
		str_ = static_cast<char*>(calloc(++len, sizeof(char)));
		strcpy_s(str_, len * sizeof(char), obj.str_);
	}
	catch (const std::exception&)
	{
		clear();
		throw;
	}

	string::string(string && obj)
	{
		this->swap(obj);
	}

	string::~string()
	{
		clear();
	}

	void string::swap(string & obj)
	{
		if (this != &obj)
			std::swap(this->str_, obj.str_);
	}

	const char * string::data() const
	{
		return str_;
	}

	std::ostream& string::operator<<(std::ostream & out) const
	{
		return (out << str_);
	}

	void string::clear()
	{
		if (str_)
		{
			free(str_);
			str_ = nullptr;
		}
	}
}
