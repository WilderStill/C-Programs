#include<bits/stdc++.h>
#define M 114514
using namespace std;
int n,ans,x[M],y[M];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d%d",&x[i],&y[i]);
	for(int i=1;i<n;++i)
	{
		for(int j=1;j<=n;++j)
		{
			if(i==j)continue;
			int maxn=2;
			for(int k=1;k<=n;++k)
			{
				if(k==i||k==j)continue;
				if((x[k]-x[i])*(y[k]-y[j])==(y[k]-y[i])*(x[k]-x[j]))maxn++;
			}
			ans=max(maxn,ans);
		}
	}
	printf("%d",ans);
	return 0;
}
