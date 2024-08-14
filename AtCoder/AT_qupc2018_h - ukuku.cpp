#include<bits/stdc++.h>
#define mp make_pair
#define l first
#define r second
#define M 211451
using namespace std;
int n,num[M];
vector<int>ivt[M];
char ans[M];
bool vis[30];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&num[i]);
		int len=(num[i]+1)>>1,l=i-len,r=i+len;ans[i]=96;
		if(l>=1&&r<=n)ivt[r].emplace_back(l);
	}
	auto In=mp(-1,-1);
	for(int i=1;i<=n;++i)
	{
		if(In.l>=(i<<1)+1)ans[i]=ans[(In.r<<1)-i];
		else
		{
			memset(vis,0,sizeof vis);
			for(auto j:ivt[i])vis[ans[j]^96]=1;
			for(int j=1;j<=27;++j)
				if(!vis[j])
				{
					ans[i]+=j;
					break;
				}
		}
		In=max(In,mp((i<<1)+num[i],i));
	}
	printf("%s",ans+1);
	return 0;
}
