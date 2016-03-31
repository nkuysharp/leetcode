#include <iostream>
#include "HouseRobber3.h" 
#include "../common/testlib.h"

using namespace std;

int main()
{
    Solution solution;
    ASSERT_EQ(7, solution.rob(MAKE_BINARY_TREE("3,2,3,#,3,#,1")));
    ASSERT_EQ(6, solution.rob(MAKE_BINARY_TREE("0,2,3,null,3,NULL,1")));
    return 0;
}

