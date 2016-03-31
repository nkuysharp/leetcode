#include <iostream>
#include "HouseRobber3.h" 
#include "../common/testlib.h"

using namespace std;

int main()
{
    Solution solution;
    TreeNode* root = MAKE_BINARY_TREE("3,2,3,#,3,#,1");
    ASSERT_EQ(7, solution.rob(root));
    DELETE_BINARY_TREE(root);
    return 0;
}

