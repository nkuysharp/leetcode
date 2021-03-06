#ifndef __LEETCODE_LONGESTINCREASINGSUBSEQUENCE_H__
#define __LEETCODE_LONGESTINCREASINGSUBSEQUENCE_H__
#include "../common/common.h"

class Solution {
public:
    int lengthOfLIS(vector<int>& nums)
    {
	if (nums.size() == 0)
	{
	    return 0;
	}
	
	vector<int> opt;
	opt.push_back(nums[0]);
	for (size_t i = 1; i < nums.size(); ++i)
	{
	    if (nums[i] > opt.back())
	    {
		opt.push_back(nums[i]);
	    }
	    else
	    {
		vector<int>::iterator it = lower_bound(opt.begin(), opt.end(), nums[i]);
		*it = nums[i];
	    }
	}
	return opt.size();
    }

    
    int lengthOfLIS_1(vector<int>& nums)
    {
	vector<int> opt(nums.size(), 1); // opt[i] is the max length of all sub sequences ended with nums[i]
	int maxLength = nums.size() > 0 ? 1 : 0;
	for (int i = 1; i < nums.size(); ++i)
	{
	    opt[i] = 1;
	    for (int j = i - 1; j >= 0; --j)
	    {
		if (nums[i] > nums[j])
		{
		    opt[i] = max(opt[i], opt[j] + 1);
		}
	    }
	    maxLength = max(maxLength, opt[i]);
	}

	return maxLength;
    }
};


#endif

