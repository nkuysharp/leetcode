#ifndef __LEETCODE_HOUSEROBBER_H__
#define __LEETCODE_HOUSEROBBER_H__
#include "../common/common.h"

class Solution {
public:
    int rob(vector<int>& nums)
    {
        int cur = 0, pre = 0, ppre = 0;
        for (size_t i = 0; i < nums.size(); ++i)
        {
            cur = max(pre, ppre + nums[i]);
            ppre = pre;
            pre = cur;
        }
        return cur;
    }
};


#endif

