#include<bits/stdc++.h>
using namespace std;
int a,b;
bool ans[4010];
inline bool query(int x,int y)
{
	printf("? %d %d\n",x,y);
	fflush(stdout);
	char s[4];
	scanf("%s",s);
	return (s[0]=='Y');
}
inline void answer()
{
	printf("!");
	for(int i=0;i<a+b;++i)printf("%d",ans[i]);
	fflush(stdout);
	return;
}
int main()
{
	scanf("%d%d",&a,&b);
	if(a<=b)
	{
		puts("Impossible");
		return 0;
	}
	stack<int>stk;
	for(int i=0;i<a+b;++i)
	{
		if(stk.empty())stk.push(i);
		else
		{
			int top=stk.top();
			if(!query(top,i))stk.pop();
			else stk.push(i);
		}
	}
	int dg=stk.top();
	for(int i=0;i<a+b;++i)ans[i]=query(dg,i);
	answer();
    return 0;
}
