#include<bits/stdc++.h>
#define M 114514
using namespace std;
int f[M],dp[M],n,v;
int main()
{
	scanf("%d%d",&n,&v);
	for(int i=1,p,g;i<=n;++i)
	{
		scanf("%d%d",&p,&g);
		for(int j=0;j<=v-p;++j)dp[j]=f[j];
		for(int j=1,gp,pv;j<=g;++j)
		{
			scanf("%d%d",&gp,&pv);
			for(int k=v-p;k>=gp;--k)
				dp[k]=max(dp[k-gp]+pv,dp[k]);
		}
		for(int j=v;j>=p;--j)f[j]=max(f[j],dp[j-p]);
	}
	printf("%d",f[v]);
	return 0;
}
