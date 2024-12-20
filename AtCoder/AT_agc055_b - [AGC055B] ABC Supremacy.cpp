#include<bits/stdc++.h>
using namespace std;
int n;
inline string change(string s)
{
	stack<int>stk;
	for(auto c:s)
	{
		stk.push(c-'A');
		if(stk.size()>=3)
		{
			int t1=stk.top();
			stk.pop();
			int t2=stk.top();
			stk.pop();
			int t3=stk.top();
			if(t3==(t1+1)%3&&t1==(t2+1)%3&&t2==(t3+1)%3)stk.pop();
			else stk.push(t2),stk.push(t1);
		}
	}
	string res;
	res.resize(n);
	for(int i=stk.size()-1;~i;--i)
	{
		res[i]=stk.top();
		stk.pop();
	}
	return res;
}
int main()
{
	string s,t;
	cin>>n>>s>>t;
	s=change(s),t=change(t);
	for(int i=0;i<n;++i)
		if(s[i]^t[i])
		{
			puts("NO");
			return 0;
		}
	puts("YES");
	return 0;
}
