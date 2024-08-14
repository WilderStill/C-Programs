#include<bits/stdc++.h>
#define INF 0
#define M 1001
using namespace std;
int n,m,f[M][M][2],ans=INF,pos[M],w[M],sum[M];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&pos[i]);
	sort(pos+1,pos+n+1);
	for(int t=1;t<=n;++t)
	{
		memset(f,INF,sizeof(f));
		for(int i=1;i<=n;++i)f[i][i][0]=f[i][i][1]=m-abs(pos[i])*t,ans=max(ans,f[i][i][0]);
		for(int l=2;l<=t;++l)
		{
			for(int i=1,j=l;j<=n;++i,++j)
			{
				f[i][j][0]=max(f[i+1][j][0]+m-abs(pos[i+1]-pos[i])*(t-l+1),f[i+1][j][1]+m-abs(pos[j]-pos[i])*(t-l+1));
				f[i][j][1]=max(f[i][j-1][0]+m-abs(pos[j]-pos[i])*(t-l+1),f[i][j-1][1]+m-abs(pos[j]-pos[j-1])*(t-l+1));
				ans=max(max(f[i][j][0],f[i][j][1]),ans);
			}
		}
	}
	printf("%d",ans);
	return 0;
}
