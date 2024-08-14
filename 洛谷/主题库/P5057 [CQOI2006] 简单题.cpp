#include<bits/stdc++.h>
#define lowbit(x) (x&(-x)) 
using namespace std;
int n,m,s[114514];
void modify(int i)
{
	for(;i<=n;i+=lowbit(i))s[i]^=1;
}
int query(int i)
{
	int ans=0;
	for(;i;i-=lowbit(i))ans^=s[i];
	return ans;
}
int main()
{
	scanf("%d%d",&n, &m);
	for(int i=1;i<=m;i++)
	{
		int op,x,y;
		scanf("%d",&op);
		if(op==1)
		{
			scanf("%d%d",&x,&y);
			modify(x);
			modify(y+1);
		}
		else
		{
			scanf("%d",&x);
			printf("%d\n",query(x));
		}
	}
	return 0;
}
