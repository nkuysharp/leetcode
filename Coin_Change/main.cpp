#include <iostream>
#include "CoinChange.h" 
#include "../common/testlib.h"

using namespace std;

int main()
{
    Solution solution;
    vector<int> coins = {1, 2, 3};
    solution.coinChange(coins, 3);
    return 0;
}

