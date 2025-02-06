#include<bits/stdc++.h>
#define int long long
#define M 1145141
#define lowbit(x) ((x)&(-(x)))
using namespace std;
int b[M];
void add(int x,int v,int n)
{
	for(int i=x;i<=n;i+=lowbit(i))b[i]+=v;
}
int query(int x)
{
	int ans=0;
	for(int i=x;i;i-=lowbit(i))ans+=b[i];
	return ans;
}
signed main()
{
	int m,n;
	scanf("%lld%lld",&n,&m);
	for(int i=1,x;i<=n;i++)add(i,0,n);
	for(int i=1,x,y;i<=m;i++)
	{
		char op[2];
		scanf("%s%lld%lld",op,&x,&y);
		if(op[0]=='x')add(x,y,n);
		else printf("%lld\n",query(y)-query(x-1));
	}
	return 0;
}
