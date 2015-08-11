#ifndef __LEETCODE_TESTLIB_H__
#define __LEETCODE_TESTLIB_H__
#include <cstdio>
#include <exception>
#include <string>
#include <algorithm>
#include <cstring>
#include "util.h"

using namespace leetcode_util;

#define ASSERT_TRUE(expr)						\
    {									\
	if(expr)							\
	{								\
	    fprintf(stderr, "ASSERT_TRUE:\t[PASS]\n");			\
	}								\
	else								\
	{								\
	    fprintf(stderr, "%s:%d: error: ASSERT_TRUE failed\n", __FILE__, __LINE__); \
	}								\
    }									

#define ASSERT_FALSE(expr)				\
    {							\
	if(!expr)					\
	{						\
	    fprintf(stderr, "ASSERT_FALSE:\t[PASS]\n");	\
	}						\
	else								\
	{								\
	    fprintf(stderr, "%s:%d: error: ASSERT_FALSE failed\n", __FILE__, __LINE__); \
	}								\
    }									

#define ASSERT_EQ(expected, actual)  assert_eq(expected, actual, __FILE__, __LINE__)

template <typename T>
void assert_eq(const T& expected, const T& actual, const char* filename, int line) 
{
    if (Equal(expected, actual))
    {
	fprintf(stderr, "ASSERT_EQ:\t[PASS]\n");
    }
    else
    {
	std::string expectedStr = ToString(expected);
	std::string actualStr = ToString(actual);
	fprintf(stderr, "%s:%d: error: AEERT_EQ failed\nExpected:%s\nActual:%s\n", __FILE__, __LINE__,expectedStr.c_str(),actualStr.c_str());
    }
}

template <typename T, typename U>
void assert_eq(const T& expected, const U& actual, const char* filename, int line) 
{
    if (Equal(expected, (T)actual))
    {
	fprintf(stderr, "ASSERT_EQ:\t[PASS]\n");
    }
    else
    {
	std::string expectedStr = ToString(expected);
	std::string actualStr = ToString(actual);
	fprintf(stderr, "%s:%d: error: AEERT_EQ failed\nExpected:%s\nActual:%s\n", __FILE__, __LINE__,expectedStr.c_str(),actualStr.c_str());
    }
}



#endif













