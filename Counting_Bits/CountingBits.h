#ifndef __LEETCODE_COUNTINGBITS_H__
#define __LEETCODE_COUNTINGBITS_H__
#include "../common/common.h"

class Solution {
public:
    vector<int> countBits(int num)
    {
	vector<int> nbits(num + 1, 0);
	for (int i = 1; i <=num; ++i)
	{
	    nbits[i] = nbits[i>>1] + (i & 1);
	}
	return nbits;
    }
};


#endif











