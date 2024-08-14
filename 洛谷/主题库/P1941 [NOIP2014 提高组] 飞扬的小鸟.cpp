#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 2145
using namespace std;
int n,m,k,ans=INF,f[M*5][M],up[M*5],dn[M*5];
bool pix[M*5];
struct Pipes
{
	int l,h;
}pipes[M*5];
int main()
{
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;++i)scanf("%d%d",&up[i],&dn[i]);
	for(int i=1,p;i<=k;++i)
	{
		scanf("%d",&p);
		scanf("%d%d",&pipes[p].l,&pipes[p].h);
		pix[p]=1;
	}
	memset(f,INF,sizeof f);
	for(int j=1;j<=m;++j)f[0][j]=0;
	for(int i=1;i<=n;++i)
	{
        for(int j=up[i]+1;j<=m+up[i];++j)f[i][j]=min(f[i-1][j-up[i]]+1,f[i][j-up[i]]+1);//完全背包
        for(int j=m+1;j<=m+up[i];++j)f[i][m]=min(f[i][m],f[i][j]);//特判到达上边界
        for(int j=1;j<=m-dn[i];++j)f[i][j]=min(f[i][j],f[i-1][j+dn[i]]);//01背包
        if(pix[i])
		{
			for(int j=1;j<=pipes[i].l;++j)f[i][j]=INF;
        	for(int j=pipes[i].h;j<=m;++j)f[i][j]=INF;
		}
	}
	for(int i=1;i<=m;++i)ans=min(ans,f[n][i]);
	if(ans<INF)printf("1\n%d\n",ans);
	else
	{
		int i,j,dans=0;
        for(i=n;i>=1;--i)
		{
            for(j=1;j<=m;++j)if(f[i][j]<INF)break;
            if(j<=m)break;
        }
		for(int j=1;j<=i;++j)
			if(pix[j])++dans;
		printf("0\n%d\n",dans);
	}
	return 0;
}
