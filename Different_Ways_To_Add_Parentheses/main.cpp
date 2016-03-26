#include <iostream>
#include "DifferentWaysToAddParentheses.h" 
#include "../common/testlib.h"
using namespace std;


int main()
{
    Solution solution;
    ASSERT_EQ(vector<int>({15}), solution.diffWaysToCompute("15"));
    ASSERT_EQ(vector<int>({6, 6}), solution.diffWaysToCompute("1+2+3"));
    ASSERT_EQ(vector<int>({15, 30}), solution.diffWaysToCompute("3+2*6"));
    ASSERT_EQ(vector<int>({-34, -14, -10, -10, 10}), solution.diffWaysToCompute("2*3-4*5"));
    ASSERT_EQ(vector<int>({3, 3}), solution.diffWaysToCompute("1+1+1"));

    return 0;
}











