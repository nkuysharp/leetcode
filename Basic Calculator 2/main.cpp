#include <iostream>
#include "BasicCalculator2.h" 
#include "../common/testlib.h"

using namespace std;

int main()
{
    Solution solution;
    ASSERT_EQ(8, solution.calculate("3 + 2 + 3"));
    ASSERT_EQ(9, solution.calculate("3 + 2 * 3"));
    ASSERT_EQ(8, solution.calculate("8"));
    ASSERT_EQ(8, solution.calculate("5 / 2 + 6"));
    ASSERT_EQ(0, solution.calculate("2/ 5 + 0"));
    ASSERT_EQ(-2, solution.calculate("3 - 5"));
    ASSERT_EQ(-7, solution.calculate("3 - 5 * 2"));
    ASSERT_EQ(60, solution.calculate("3 * 5 * 2 * 2"));
    ASSERT_EQ(6, solution.calculate("100 / 2 / 2/2 /   2 "));
    ASSERT_EQ(0, solution.calculate(""));
    return 0;
}

