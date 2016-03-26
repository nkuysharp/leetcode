#ifndef __LEETCODE_BASICCALCULATOR2_H__
#define __LEETCODE_BASICCALCULATOR2_H__
#include "../common/common.h"

class Solution {
public:
    typedef map<char, int> PriTable;
    int calculate(string s)
    {
	stack<int> operand; 
	stack<char> op;
	PriTable priTable;
	priTable['*'] = 2;
	priTable['/'] = 2;
	priTable['+'] = 1;
	priTable['-'] = 1;
	
	int i = 0;
	string token = GetToken(s, i);
	char preOp;
	int lhs, rhs;
	while (!token.empty())
	{
	    if (isdigit(token[0]))
	    {
		operand.push(atoi(token.c_str()));
		token = GetToken(s, i);
		continue;
	    }
	    
	    if (op.empty())
	    {
		op.push(token[0]);
	    }
	    else
	    {
		preOp = op.top();
		if (priTable[token[0]] > priTable[preOp])
		{
		    lhs = operand.top();
		    operand.pop();
		    rhs = atoi(GetToken(s, i).c_str());
		    operand.push(Compute(lhs, rhs, token[0]));
		}
		else
		{
		    EvalStack(operand, op);
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
	    int rhs = operand.top();
	    operand.pop();
	    int lhs = operand.top();
	    operand.pop();
	    char opc = op.top();
	    op.pop();
	    operand.push(Compute(lhs, rhs, opc));
	}
    }

    int Compute(const int lhs, const int rhs, const char op)
    {
	switch(op)
	{
	case '+': return lhs + rhs;
	case '-': return lhs - rhs;
	case '*': return lhs * rhs;
	case '/': return lhs / rhs;
	}
	return 0;
    }
    
};


#endif

