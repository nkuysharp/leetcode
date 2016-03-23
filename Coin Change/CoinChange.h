#ifndef __LEETCODE_COINCHANGE_H__
#define __LEETCODE_COINCHANGE_H__
#include "../common/common.h"

class Solution {
public:
    struct Comp
    {
	bool operator () (int lhs, int rhs) const
	{
	    return lhs > rhs;
	}
    };
    
    int coinChange(vector<int>& coins, int amount) {
	sort(coins.begin(), coins.end(), Comp());
	vector<int> used(coins.size(), 0);
	vector<int> limits(coins.size(), 0);
	
	for (size_t i = 0; i < coins.size(); ++i)
	{
	    limits[i] = amount / coins[i];
	}

	int nCoin = -1;
	dfs(used, 0, limits, amount, nCoin);
	return nCoin;
    }

    void dfs(vector<int>& used, int k, const vector<int>& limits, int target, int& nCoin)
    {
	
	
    }
    
};


#endif














