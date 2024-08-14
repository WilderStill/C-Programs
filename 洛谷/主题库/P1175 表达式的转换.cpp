#include<bits/stdc++.h>
using namespace std;
stack<char>stk1,op;
stack<int>num,stk2;
auto level=[](char c)
{
	switch(c)
	{
		case '+':return 1;
		case '-':return 1;
		case '*':return 2;
		case '/':return 2;
		case '^':return 3;
		case '(':return 0;
		case ')':return 0;
	}
};
auto cal=[](int x,int y,char c)
{
	switch(c)
	{
		case '+':return x+y;
		case '-':return x-y;
		case '*':return x*y;
		case '/':return x/y;
		case '^':return (int)pow(x,y);
	}
};
void change(string s)
{
	for(auto i:s)
	{
		if(isdigit(i))stk1.push(i);
		else if(i=='(')op.push(i);
		else if(i==')')
		{
			char t=op.top();
			while(t!='(')
			{
				op.pop();
				stk1.push(t);
				t=op.top();
			}
			op.pop();
		}
		else if(level(i)>=1&&level(i)<=3)
		{
			if(op.size())
			{
				char t=op.top();
				while(op.size()&&level(i)<=level(t))
				{
					if(level(i)==level(t)&&i=='^')break;
					op.pop();
					stk1.push(t);
					if(op.size())t=op.top();
				}
			}
			op.push(i);
		}
	}
	while(op.size())
	{
		char t=op.top();op.pop();
		stk1.push(t);
	}
	while(stk1.size())
	{
		char t=stk1.top();stk1.pop();
		op.push(t);
	}
	while(op.size())
	{
		char t=op.top();op.pop();
		putchar(t),putchar(' ');
		stk1.push(t);
	}
	putchar('\n');
}
void calc()
{
	while(stk1.size())
	{
		char t=stk1.top();stk1.pop();
		op.push(t);
	}
	while(op.size())
	{
		char t=op.top();op.pop();
		if(isdigit(t))num.push(t-'0');
		else
		{
			int a=num.top();num.pop();
			int b=num.top();num.pop();
			num.push(cal(b,a,t));
			while(num.size())
			{
				int t=num.top();
				num.pop();
				stk2.push(t); 
			}
			while(stk2.size())
			{
				int t=stk2.top();stk2.pop();
				printf("%d",t),putchar(' ');
				num.push(t);
			}
			while(op.size())
			{
				char t=op.top();op.pop();
				putchar(t),putchar(' ');
				stk1.push(t);
			}
			while(stk1.size())
			{
				char t=stk1.top();op.push(t);
				stk1.pop();
			}
			putchar('\n');
		}
	}
}
int main()
{
	string s;
	cin>>s;   
	change(s);
	calc();
	return 0;
}
