#ifndef __LEETCODE_DIFFERENTWAYSTOADDPARENTHESES_H__
#define __LEETCODE_DIFFERENTWAYSTOADDPARENTHESES_H__
#include "../common/common.h"

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
	vector<int> ret = GetDiffWaysToCompute(input, 0, input.size());
	sort(ret.begin(), ret.end());
	return ret;
    }

    bool IsOperator(const char op)
    { return op == '+' || op == '-' || op == '*'; }
    
    vector<int> GetDiffWaysToCompute(
	const string& input, size_t start, size_t end)
    {
	vector<int> results;
	bool num_or_empty = true;
	for (size_t i = start; i < end; i++)
	{
	    if (IsOperator(input[i])) 
	    {
		num_or_empty = false;
		vector<int> leftVec = GetDiffWaysToCompute(input, start, i);
		vector<int> rightVec = GetDiffWaysToCompute(input, i+1, end); 
		ComputeResults(leftVec, rightVec, input[i], results);
	    }
	}

	if (num_or_empty)
	{
	    results.push_back(start == end ? 0:
			      atoi(input.substr(start, end).c_str()));
	}
	
	return results;
    }

    void ComputeResults(const vector<int>& leftVec, const vector<int>& rightVec,
			const char op, vector<int>& results)
    {
	for (size_t i = 0; i < leftVec.size(); i++)
	{
	    for (size_t j = 0; j < rightVec.size(); j++)
	    {
		results.push_back(Compute(leftVec[i], rightVec[j], op));
	    }
	}

    }

    int Compute(int lhs, int rhs, const char op)
    {
	switch(op)
	{
	case '+': return lhs + rhs;
	case '-': return lhs - rhs;
	case '*': return lhs * rhs;
	}
	return 0;
    }
};


#endif











