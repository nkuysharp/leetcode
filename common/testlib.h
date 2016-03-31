#ifndef __LEETCODE_TESTLIB_H__
#define __LEETCODE_TESTLIB_H__
#include <cstdio>
#include <exception>
#include <string>
#include <algorithm>
#include <cstring>
#include "util.h"
#include "data_structure.h"

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

TreeNode* make_tree(const vector<string>& nodeVec, int idx);
void delete_tree(TreeNode* root);

/* despStr example: "1,2,#" or "1,2,null"  */
/*   1                                     */
/*  / \                                    */
/* 2   null                                */
TreeNode* MAKE_BINARY_TREE(const std::string& despStr)
{
    vector<string> nodeVec = split(despStr, ",");
    TreeNode* root = make_tree(nodeVec, 0);
    return root;
}

TreeNode* make_tree(const vector<string>& nodeVec, int idx)
{
    if (idx >= nodeVec.size())
    {
	return NULL;
    }
    if (nodeVec[idx] == "#"
	|| nodeVec[idx] == "null"
	|| nodeVec[idx] == "NULL")
    {
	return NULL;
    }
    int val = fromString<int>(nodeVec[idx]);
    TreeNode* root = new TreeNode(val);
    root->left = make_tree(nodeVec, 2*idx+1);
    root->right = make_tree(nodeVec, 2*idx+2);
    return root;
}

void DELETE_BINARY_TREE(TreeNode* root)
{
    delete_tree(root);
}

void delete_tree(TreeNode* root)
{
    if (root)
    {
	delete_tree(root->left);
	delete_tree(root->right);
	delete root;
    }
}


#endif








