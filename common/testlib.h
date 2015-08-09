#ifndef __LEETCODE_TESTLIB_H__
#define __LEETCODE_TESTLIB_H__
#include <cstdio>
#include <exception>
#include <string>

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


#endif










