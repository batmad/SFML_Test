#pragma once
#include <sstream>

class MakeString
{
public:
	template <typename T>
	MakeString& operator<<(const T& rhs)
	{
		mStream << rhs;
		return *this;
	}

	operator std::string() const
	{
		return mStream.str();
	}

private:
	std::ostringstream mStream;
};