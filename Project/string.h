#pragma once

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
		string(const string & obj) = delete;	// todo ctor
		~string();
	};
}

