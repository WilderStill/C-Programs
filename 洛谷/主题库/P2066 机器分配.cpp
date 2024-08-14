#include<bits/stdc++.h>
#define M 1145
using namespace std;
int n,m,f[M],w[M][M],ans[M][M];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			scanf("%d",&w[i][j]);
	for(int i=n;i>=1;--i)
		for(int j=m;j>=0;--j)
			for(int k=1;k<=j;++k)
				if(f[j]<f[j-k]+w[i][k])
				{
					f[j]=f[j-k]+w[i][k];
					ans[i][j]=k;
				}
	printf("%d\n",f[m]);
	for(int i=1;i<=n;++i)
	{
		printf("%d %d\n",i,ans[i][m]);
		m-=ans[i][m];
	}
	return 0;
}
