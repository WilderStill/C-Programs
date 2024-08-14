#include<bits/stdc++.h>
using namespace std;
int n,sum,ans,sumw[20010],w[20010],d[20010],f[20010];
int main()
{
	memset(f,0x3f3f3f3f,sizeof f);
	ans=0x3f3f3f3f;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d%d",&w[i],&d[i]);
	for(int i=n;i>=1;--i)d[i]+=d[i+1];
	for(int i=1;i<=n;++i)
	{
		sumw[i]=sumw[i-1]+w[i];
		sum+=d[i]*w[i];
	}
	for(int i=1;i<=n;++i)
		for(int j=1;j<i;++j)
			f[i]=min(f[i],sum-d[j]*sumw[j]-d[i]*(sumw[i]-sumw[j]));
	for(int i=1;i<=n;++i)ans=min(f[i],ans);
	printf("%d",ans);
    return 0;
}
