#include<bits/stdc++.h>
#define M 1145
using namespace std;
int ans,sum[M][M],n,f[2][M];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		for(int j=1,x;j<=n;++j)
		{
			scanf("%d",&x);
			sum[i][j]=sum[i-1][j]+x;
		}
	for(int i=1;i<=n;++i)
		for(int k=1;k<=i;++k)
		{
			f[0][0]=f[1][0]=0;
			for(int j=1;j<=n;++j)
			{
				f[0][j]=sum[i][j]-sum[i-k][j];
				f[1][j]=max(f[1][j-1]+f[0][j],f[0][j]);
				ans=max(ans,f[1][j]);
			}
		}
	printf("%d",ans);
	return 0;
}
