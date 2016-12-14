#include "string.h"

#include <string.h>
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
		str_ = static_cast<char*>(malloc((size + 1) * sizeof(char)));
		str_[size] = '\0';
		if (size)
#pragma warning(suppress: 4996)
			strncpy(str_, str, std::min(strlen(str), size));
		//	strncpy_s(str_, allocSize + 1, str, copySize);

	}
	catch (...)
	{
		freememory();
		throw;
	}

	string::string(const string & obj) : string(obj.str_)
	{}

	string::string(const string & obj, size_t size) : string(obj.str_, size)
	{}

	string::string(string && obj) : string()
	{
		this->swap(obj);
	}

	string::~string()
	{
		freememory();
	}

	string & string::operator=(const char * right_string)
	{
		if (str_ != right_string)
			string(right_string).swap(*this);
		return *this;
	}

	string & string::operator=(const string & right_string)
	{
		return *this = right_string.str_;
	}

	string & string::operator=(string && right_string)
	{
		if (str_ != right_string.str_)
			swap(right_string);
		return *this;
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

	string & string::append(const char * str)
	{
		return append(str, strlen(str));
	}

	string & string::append(const char * str, size_t size)
	{
		if (size == 0) return *this;
		auto len = strlen(str_);
		if (npos - size <= len)
			throw std::length_error("result string is too long");
		auto newLen = len + size;
		try
		{
			str_ = static_cast<char*>(realloc(str_, (newLen + 1) * sizeof(char)));
			str_[newLen] = '\0';
#pragma warning(suppress: 4996)
			strncpy(&str_[len], str, std::min(strlen(str), size));
		}
		catch (...)
		{
			freememory();
			throw;
		}
		return *this;
	}

	string & string::append(const string & obj)
	{
		return append(obj.str_, strlen(obj.str_));
	}

	string & string::append(const string & obj, size_t size)
	{
		return append(obj.str_, size);
	}

	string & string::operator+=(const char * right_string)
	{
		return append(right_string);
	}

	string & string::operator+=(const string & obj)
	{
		return append(obj);
	}

	string & operator+(const string & a, const char * b)
	{
		return string(a).append(b);
	}

	string & operator+(const string & a, const string & b)
	{
		return string(a).append(b);
	}

	int string::compare(const char * right_string) const
	{
		return compare(right_string, true);
	}

	int string::compare(const char * right_string, bool caseSensetive) const
	{
		if (str_ == right_string) return 0;
		return caseSensetive ? strcmp(str_, right_string) : _strcmpi(str_, right_string);
	}

	int string::compare(const string & right_string) const
	{
		return compare(right_string.str_);
	}

	int string::compare(const string & right_string, bool caseSensetive) const
	{
		return compare(right_string.str_, caseSensetive);
	}

	std::ostream & string::operator<<(std::ostream & out) const
	{
		return (out << str_);
	}

	std::ostream & operator<<(std::ostream & out, const string & obj)
	{
		return obj.operator<<(out);
	}

	void string::freememory()
	{
		if (str_)
		{
			free(str_);
			str_ = nullptr;
		}
	}
}
