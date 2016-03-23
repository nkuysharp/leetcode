#include <iostream>
#include "LongestIncreasingSubsequence.h" 
#include "../common/testlib.h"

using namespace std;

int main()
{
    Solution solution;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    ASSERT_EQ(4, solution.lengthOfLIS(nums));
    nums = {1,3,6,7,9,4,10,5,6};
    ASSERT_EQ(6, solution.lengthOfLIS(nums));
    return 0;
}

