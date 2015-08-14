#include <iostream>
#include "BasicCalculator.h" 
#include "../common/testlib.h"

using namespace std;

int main()
{
    Solution solution;
    ASSERT_EQ(2, solution.calculate("1 + 1"));
    ASSERT_EQ(3, solution.calculate("2 - 1 + 2"));
    ASSERT_EQ(5, solution.calculate("(1+(2-1) + 3)"));
    ASSERT_EQ(23, solution.calculate("(1+(4+5+2)-3+(6+8))"));
    ASSERT_EQ(-4, solution.calculate("1 - (5)"));
    ASSERT_EQ(6, solution.calculate("1+((((1+4))))"));
    ASSERT_EQ(11, solution.calculate("(7)-(0)+(4)"));
    return 0;
}

