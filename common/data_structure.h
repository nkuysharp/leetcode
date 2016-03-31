#ifndef __LEETCODE_DATA_STRUCTRUE_H__
#define __LEETCODE_DATA_STRUCTRUE_H__

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

#endif
