#ifndef __LEETCODE_BASICCALCULATOR_H__
#define __LEETCODE_BASICCALCULATOR_H__
#include "../common/common.h"

class Solution {
public:
    int calculate(string s) {
	stack<int> operand; 
	stack<char> op;

	int i = 0;
	string token = GetToken(s, i);
	while (!token.empty())
	{
	    if (isdigit(token[0]))
	    {
		operand.push(atoi(token.c_str()));
	        EvalStack(operand, op);
	    }
	    else
	    {
		if (token[0] == ')')
		{
		    EvalStack(operand, op);
		    op.pop();
		    EvalStack(operand, op);
		}
		else
		{
		    op.push(token[0]);
		}
	    }
	    token = GetToken(s, i);
	}

	if (!operand.empty())
	{
	    EvalStack(operand, op);
	    return operand.top();
	}
	else
	{
	    return 0;
	}
    }

    string GetToken(const string& instr, int& pos)
    {
	if (pos >= instr.size())
	{
	    return string();
	}
	else
	{
	    while( pos < instr.size() && instr[pos] == ' ') { pos ++; } 
	    if (pos < instr.size() && !isdigit(instr[pos]))
	    {
		pos ++;
		return instr.substr(pos - 1, 1);
	    }
	    int start = pos;
	    int end = pos;
	    while (end < instr.size() && isdigit(instr[end])) { end ++; }
	    pos = end;
	    return instr.substr(start, end - start);
	}
    }
    
    void EvalStack(stack<int>& operand, stack<char>& op)
    {
	while(!op.empty())
	{
	    if (op.top() == '(')
	    {
		return;
	    }
	    else
	    {
		int rhs = operand.top();
		operand.pop();
		int lhs = operand.top();
		operand.pop();
		char opc = op.top();
		op.pop();
		operand.push(Compute(lhs, rhs, opc));
	    }
	}
    }

    int Compute(const int lhs, const int rhs, const char op)
    {
	switch(op)
	{
	case '+': return lhs + rhs;
	case '-': return lhs - rhs;
	}
	return 0;
    }

};


#endif















