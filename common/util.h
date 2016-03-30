#ifndef __LEETCODE_UTIL_H__
#define __LEETCODE_UTIL_H__

#include <string>
#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>

namespace leetcode_util
{
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









