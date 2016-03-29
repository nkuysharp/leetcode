#ifndef __LEETCODE_HOUSEROBBER2_H__
#define __LEETCODE_HOUSEROBBER2_H__
#include "../common/common.h"

class Solution {
public:
    int rob(vector<int>& nums)
    {
        if (nums.size() == 0)
        {
            return 0;
        }
        int gain0 = 0, pre = 0, ppre = 0;
        for (size_t i = 0; i < nums.size()-1; ++i)
        {
            gain0 = max(pre, ppre + nums[i]);
            ppre = pre;
            pre = gain0;
        }
        int gain1 = 0;
        pre = 0, ppre = 0;
        for (size_t i = 1; i < nums.size(); ++i)
        {
            gain1 = max(pre, ppre + nums[i]);
            ppre = pre;
            pre = gain1;
        }
        
        return max(gain0, gain1);
    }    
};


#endif

