#ifndef __LEETCODE_VALIDANAGRAM_H__
#define __LEETCODE_VALIDANAGRAM_H__
#include "../common/common.h"

class Solution {
public:
    bool isAnagram(string s, string t)
    {
	if (s.size() != t.size())
	{
	    return false;
	}
	vector<int> cnt(26, 0);
	for (size_t i = 0; i < s.size(); i++)
	{
	    cnt[s[i]-'a'] += 1;
	    cnt[t[i]-'a'] -= 1;
	}

	for (size_t i = 0; i < 26; i++)
	{
	    if (cnt[i] != 0)
		return false;
	}
	
	return true;
    }
};


#endif

