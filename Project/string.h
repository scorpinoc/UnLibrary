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
		string(const char * str, size_t size);
		string(const string & obj);
		string(string && obj);
		~string();

		void swap(string & obj);
		const char * data() const;
		std::ostream& operator<<(std::ostream & out) const;

		friend auto& operator<<(std::ostream & out, const string & obj) { return obj.operator<<(out); }

	private:
		void clear();
	};
}

