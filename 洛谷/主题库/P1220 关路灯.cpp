#include<bits/stdc++.h>
#define INF 0x3f
#define M 1001
using namespace std;
int n,c,f[M][M][2],pos[M],w[M],sum[M];
int main()
{
	memset(f,INF,sizeof f);
	scanf("%d%d",&n,&c);
	f[c][c][0]=f[c][c][1]=0;
	for(int i=1;i<=n;++i)scanf("%d%d",&pos[i],&w[i]),sum[i]=sum[i-1]+w[i];
	for(int l=1;l<n;++l)
		for(int i=1,j=i+l;j<=n;++i,++j)
		{
			f[i][j][0]=min(f[i+1][j][0]+(pos[i+1]-pos[i])*(sum[i]+sum[n]-sum[j]),f[i+1][j][1]+(pos[j]-pos[i])*(sum[i]+sum[n]-sum[j]));
			f[i][j][1]=min(f[i][j-1][0]+(pos[j]-pos[i])*(sum[i-1]+sum[n]-sum[j-1]),f[i][j-1][1]+(pos[j]-pos[j-1])*(sum[i-1]+sum[n]-sum[j-1]));
		}
	printf("%d",min(f[1][n][0],f[1][n][1]));
	return 0;
}
