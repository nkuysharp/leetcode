#ifndef __LEETCODE_INCREASINGTRIPLETSUBSEQUENCE_H__
#define __LEETCODE_INCREASINGTRIPLETSUBSEQUENCE_H__
#include "../common/common.h"

class Solution {
public:
    bool increasingTriplet(vector<int>& nums)
    {
	if (nums.size() < 3)
	{
	    return false;
	}
	int min = numeric_limits<int>::max(); // min number 
	int minWithSmallerPre = numeric_limits<int>::max(); // min number with a smaller pre-num

	for (int i = 0; i < nums.size(); ++i)
	{
	    if (nums[i] > minWithSmallerPre)
	    {
		return true;
	    }
	    else if (nums[i] > min)
	    {
		minWithSmallerPre = nums[i];
	    }
	    else // nums[i] <= min 
	    {
		min = nums[i];
	    }
	}
	return false;
    }
};


#endif

