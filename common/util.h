#ifndef __LEETCODE_UTIL_H__
#define __LEETCODE_UTIL_H__

#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <typeinfo>

namespace leetcode_util
{
    void trim(std::string& str) {
	str.erase(str.find_last_not_of(' ') + 1);
	str.erase(0, str.find_first_not_of(' '));
    }

    std::vector<std::string> split(const std::string& srcStr,
				   const std::string& delim,
				   bool ignoreEmpty = true)
    {
	std::vector<std::string> vec;
	std::string str(srcStr);
	std::string sep(delim);
	size_t n = 0, old = 0;
	while (n != std::string::npos)
	{
	    n = str.find(sep,n);
	    if (n != std::string::npos)
	    {
		if (!ignoreEmpty || n != old)
		{
		    std::string item = str.substr(old, n-old);
		    trim(item);
		    vec.push_back(item);
		}

		n += sep.length();
		old = n;
	    }
	}

	if (!ignoreEmpty || old < str.length())
	{
	    std::string item = str.substr(old, str.length() - old);
	    trim(item);
	    vec.push_back(item);
	}
	return vec;
    }

    std::string StringJoin(const std::vector<std::string>& strlist,
			   const std::string& sperator);
    
    std::string ToString(const std::string& instr) { return instr; }
    std::string ToString(const char* instr) { return std::string(instr); }

    template <typename T>
    std::string ToString(const T& val)
    {
        std::ostringstream ostr;
        ostr << val;
        return ostr.str();
    }

    template <typename T>
    std::string ToString(const std::vector<T>& vec)
    {
	std::vector<std::string> strlist;
	for (auto iter = vec.begin(); iter != vec.end(); ++iter)
	{
	    strlist.push_back(ToString(*iter));
	}
	return std::string("[") + StringJoin(strlist, ",") + std::string("]");
    }

    
    // fromString
    bool fromString(const std::string& srcStr)
    {
	string trimStr = srcStr;
	trim(trimStr);
	if (trimStr == "t"
	    || trimStr == "true"
	    || trimStr == "True"
	    || trimStr == "TRUE"
	    || trimStr == "y"
	    || trimStr == "yes"
	    || trimStr == "Yes"
	    || trimStr == "YES"
	    || trimStr == "1")
	{
	    return true;
	}
	else
	{
	    return false;
	}
    }

    template <typename T>
    T fromString(const std::string& srcStr)
    {
	T val = T();
	std::istringstream iss(srcStr);
	iss >> val;
	if (iss.fail())
	{
	    std::cerr << "try to convert [" << srcStr << "] to "
		      << typeid(val).name() << " failed" << std::endl;
	    throw runtime_error("convert string failed.");
	}
	return val;
    }

    template <typename T>
    void fromString(std::vector<std::string>& strVec, std::vector<T>& vec)
    {
	vec.clear();
	vec.reserve(strVec.size());
	for (size_t i = 0; i < strVec.size(); ++i)
	{
	    vec.push_back(fromString<T>(strVec[i]));
	}
    }

    template <typename T>
    void fromString(const std::string& srcStr, std::vector<T>& vec, const std::string& delim)
    {
	std::vector<std::string> strVec = split(srcStr, delim);
	fromString(strVec, vec);
    }

    std::string StringJoin(const std::vector<std::string>& strlist,
			   const std::string& sperator)
    {
	std::string retStr;
	auto iter = strlist.begin();
	if (iter != strlist.end())
	{
	    retStr += *iter;
	    ++iter;
	}

	while (iter != strlist.end())
	{
	    retStr += sperator; 
	    retStr += *iter;
	    ++iter;
	}
	return retStr;
    }
    
    // bool Equal(const std::string& lhs, const std::string& rhs) { return lhs == rhs; }
    bool Equal(const char* lhs, const char* rhs) { return std::strcmp(lhs, rhs) == 0; }
    
    template <typename T>
    bool Equal(const T& lhs, const T& rhs) { return lhs == rhs; }

    template <typename T> 
    bool Equal(const std::vector<T>& lhs, const std::vector<T>& rhs)
    {
      return lhs.size() == rhs.size() ?
        std::equal(lhs.begin(), lhs.end(), rhs.begin()) : false;
    }
};

#endif
