#include<bits/stdc++.h>
#define ll long long
using namespace std;
string s;
stack<int>num,stk;
stack<char>op;
ll short_path_and,short_path_or;
bool short_path;
auto level=[](char c)
{
	switch(c)
	{
		case '&':return 2;
		case '|':return 1;
		default:return 0;
	}
};
int main()
{
	cin>>s;
	for(int i=0;i<s.length();i++)
	{
		char t=s[i];
		if(isdigit(t))num.push(t-'0');
		else if(t=='(')op.push(t);
		else if(t==')')
		{
			while(op.size()&&op.top()!='(')
			{
				char c;
				int a,b,short_path_check;
				a=num.top();num.pop();
				b=num.top();num.pop();
				c=op.top();op.pop();
				short_path_check=stk.top();stk.pop();
				if(short_path_check==1)short_path=0;
				num.push(c=='|'?(a||b):(a&&b));
			}
			op.pop();
		}
		else
		{
			while(op.size()&&level(op.top())>=level(t))
			{
				char c;
				int a,b,short_path_check;
				a=num.top();num.pop();
				b=num.top();num.pop();
				c=op.top();op.pop();
				short_path_check=stk.top();stk.pop();
				if(short_path_check==1)short_path=0;
				num.push(c=='|'?(a||b):(a&&b));
			}
			if(t=='|')
			{
				if(num.top()==1&&short_path==0)
				{
					short_path=1;
					short_path_or++;
					stk.push(1);
				}
				else stk.push(0);
			}
			else if(t=='&')
			{
				if(num.top()==0&&short_path==0)
				{
					short_path=1;
					short_path_and++;
					stk.push(1);
				}
				else stk.push(0);
			}
			else stk.push(0);
			op.push(t);
		}
	}
	while(op.size())
	{
		char c;
		int a,b,short_path_check;
		a=num.top();num.pop();
		b=num.top();num.pop();
		c=op.top();op.pop();
		short_path_check=stk.top();stk.pop();
		if(short_path_check==1)short_path=0;
		num.push(c=='|'?(a||b):(a&&b));
	}
	printf("%d\n%d %d",num.top(),short_path_and,short_path_or);
}
