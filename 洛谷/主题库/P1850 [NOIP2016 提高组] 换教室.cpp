#include<bits/stdc++.h>
#define M 2114
#define INF 0x3f3f3f3f
using namespace std;
const double INFd=1e9;
double p[M],f[M][M][2];
int n,m,v,e,c[M],d[M],mp[M][M];
int main()
{
	memset(mp,INF,sizeof mp);
    scanf("%d%d%d%d",&n,&m,&v,&e);
    for(int i=1;i<=n;++i)scanf("%d",&c[i]);
    for(int i=1;i<=n;++i)scanf("%d",&d[i]);
    for(int i=1;i<=n;++i)scanf("%lf",&p[i]);
    for(int i=1,x,y,z;i<=e;++i)
	{
		scanf("%d%d%d",&x,&y,&z);
        mp[x][y]=mp[y][x]=min(mp[x][y],z);
    }
    for(int k=1;k<=v;++k)
    	for(int i=1;i<=v;++i)
    		for(int j=1;j<=v;++j)
            	mp[i][j]=min(mp[i][j],mp[i][k]+mp[k][j]);
	for(int i=1;i<=v;++i)mp[i][i]=mp[i][0]=mp[0][i]=0;
	for(int i=0;i<=n;++i)
        for(int j=0;j<=m;++j)
			f[i][j][0]=f[i][j][1]=INFd;
    f[1][0][0]=f[1][1][1]=0;
    for(int i=2;i<=n;++i)
	{
		int C1=c[i-1],D1=d[i-1],C2=c[i],D2=d[i];
		f[i][0][0]=f[i-1][0][0]+mp[C1][C2];
    	for(int j=1;j<=min(m,i);++j)
    	{
    		f[i][j][0]=min(f[i][j][0],min(f[i-1][j][0]+mp[C1][C2],f[i-1][j][1]+mp[C1][C2]*(1-p[i-1])+mp[D1][C2]*p[i-1]));
    		f[i][j][1]=min(f[i][j][1],min(f[i-1][j-1][0]+mp[C1][C2]*(1-p[i])+mp[C1][D2]*p[i],f[i-1][j-1][1]+mp[D1][D2]*p[i]*p[i-1]+mp[D1][C2]*p[i-1]*(1-p[i])+mp[C1][D2]*(1-p[i-1])*p[i]+mp[C1][C2]*(1-p[i-1])*(1-p[i])));
		}
    }
    double ans=INFd;
    for(int i=0;i<=m;++i)ans=min(f[n][i][0],min(f[n][i][1],ans));
    printf("%.2lf",ans);
    return 0;
}
