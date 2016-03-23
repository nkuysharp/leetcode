#include <iostream>
#include "IncreasingTripletSubsequence.h" 
#include "../common/testlib.h"

using namespace std;

int main()
{
    Solution solution;
    vector<int> nums = {3,2,1,4,5};
    ASSERT_TRUE(solution.increasingTriplet(nums));
    nums = {2,9,2,2,2,2,2,2,3,4};
    ASSERT_TRUE(solution.increasingTriplet(nums));
    nums = {2,9,2,2,2,2,2,2,3,2};
    ASSERT_FALSE(solution.increasingTriplet(nums));
    nums = {1,9,2,-1,5};
    ASSERT_TRUE(solution.increasingTriplet(nums));
    return 0;
}

