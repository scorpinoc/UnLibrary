#pragma once
#include <ostream>

namespace UnLib
{
	class string
	{
	private:
		char * str_;
	public:
		static constexpr size_t npos = size_t(-1);

		string();
		string(const char * str);
		string(const char * str, size_t count);
		string(const string & obj);
		string(const string & obj, size_t count);
		string(string && obj);
		// todo init_list ctors
		~string();

		string & operator=(const char * right_string);
		string & operator=(const string & right_string);
		string & operator=(string && right_string);


		void swap(string & obj);
		const char * data() const;

		string & append(const char * right_string);
		string & append(const char * right_string, size_t count);
		string & append(const string & right_string);
		string & append(const string & right_string, size_t count);
		// todo init_list append

		string & operator+=(const char * right_string);
		string & operator+=(const string & right_string);
		friend string & operator+(const string & left_string, const char * right_string);
		friend string & operator+(const string & left_string, const string & right_string);

		int compare(const char * right_string) const;
		int compare(const char * right_string, bool caseSensetive) const;
		int compare(const string & right_string) const;
		int compare(const string & right_string, bool caseSensetive) const;

		std::ostream & operator<<(std::ostream & out) const;
		friend std::ostream & operator<<(std::ostream & out, const string & obj);
	private:
		void freememory();
	};
}

