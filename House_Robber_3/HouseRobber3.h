#ifndef __LEETCODE_HOUSEROBBER3_H__
#define __LEETCODE_HOUSEROBBER3_H__
#include "../common/common.h"
#include "../common/data_structure.h"

class Solution {
public:
    int rob(TreeNode* root)
    {
	pair<int, int> ret = doRobbery(root);
	return ret.first;
    }

    pair<int, int> doRobbery(TreeNode* root)
    {
	if (!root)
	{
	    return make_pair(0,0);
	}
	pair<int, int> lGain = doRobbery(root->left);
	pair<int, int> rGain = doRobbery(root->right);
	int maxGainWithoutCurrentNode = lGain.first + rGain.first;
	int maxGainWithCurrentNode = root->val + lGain.second + rGain.second;
	int maxGain = max(maxGainWithoutCurrentNode, maxGainWithCurrentNode);
	return make_pair(maxGain, maxGainWithoutCurrentNode);
    }
};


#endif

