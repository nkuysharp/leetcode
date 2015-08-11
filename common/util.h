#ifndef __LEETCODE_UTIL_H__
#define __LEETCODE_UTIL_H__

#include <string>
#include <cstring>
#include <vector>

namespace leetcode_util
{
    std::string StringJoin(const std::vector<std::string>& strlist,
			   const std::string& sperator);
    
    std::string ToString(const std::string& instr) { return instr; }
    std::string ToString(const char* instr) { return std::string(instr); }
    std::string ToString (int val) { return std::to_string(val);}
    std::string ToString (long val) { return std::to_string(val);};
    std::string ToString (long long val) { return std::to_string(val);}
    std::string ToString (unsigned val) { return std::to_string(val);}
    std::string ToString (unsigned long val) { return std::to_string(val);}
    std::string ToString (unsigned long long val) { return std::to_string(val);}
    std::string ToString (float val) { return std::to_string(val);}
    std::string ToString (double val) { return std::to_string(val);}
    std::string ToString (long double val) { return std::to_string(val);}

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
    
    bool Equal(const std::string& lhs, const std::string& rhs) { return lhs == rhs; }
    bool Equal(const char* lhs, const char* rhs) { return std::strcmp(lhs, rhs) == 0; }

    template <typename T> 
    bool Equal(const std::vector<T>& lhs, const std::vector<T>& rhs)
    {
	return std::equal(lhs.begin(), lhs.end(), rhs.begin());
    }
};


#endif










