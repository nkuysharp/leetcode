#include <iostream>
#include "CountingBits.h" 
#include "../common/testlib.h"

using namespace std;

int main()
{
    Solution solution;
    ASSERT_EQ((vector<int>{0,1,1,2,1,2}), solution.countBits(5));
    return 0;
}

