#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 5010
using namespace std;
int n,h[M],f[M],mr[M],cnt[M][M],sum[M][M];
int main()
{
	//memset("photo.in","r",stdin);
	//memset("photo.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&h[i]);
	for (int i=n;i;--i)
	{
		for(int j=1;j<=n;++j)
			j<h[i]?cnt[h[i]][j]=mr[j]:++mr[j];
		for(int j=1;j<i;++j)
			if(h[j]<h[i])++sum[h[j]][h[i]];
	}
	for(int i=n;i;--i)
		for(int j=i+2;j<=n;++j)
			sum[i][j]+=sum[i][j-1]+sum[i+1][j]-sum[i+1][j-1];
	memset(f,INF,sizeof f);
	f[0]=0; 
	for(int j=0;j<=n;++j)
	{
		int sumc=0;
		for(int i=j+1;i<=n;++i)
		{
			sumc+=cnt[i][j];
			f[i]=min(f[i],f[j]+sumc+sum[j+1][i]);
		}
	}
	printf("%d",f[n]);
	return 0;
}
