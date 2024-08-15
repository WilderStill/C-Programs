#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define M 1145
using namespace std; 
ll edge[M][M],dis[M][M];
double ans[M];
int main()
{
	ll n,m;
	scanf("%lld%lld",&n,&m);
	memset(dis,INF,sizeof(dis));
	for(ll i=1;i<=m;i++)
	{
		ll x,y,z;
		scanf("%lld%lld%lld",&x,&y,&z);
		dis[x][y]=dis[y][x]=min(dis[y][x],z);
		edge[x][y]=edge[y][x]=1;
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(dis[i][k]==INF||dis[k][j]==INF)continue; 
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					edge[i][j]=edge[i][k]*edge[k][j];
					dis[i][j]=dis[i][k]+dis[k][j];
				}
				else if(dis[i][j]==dis[i][k]+dis[k][j])
				{
					edge[i][j]+=edge[i][k]*edge[k][j];
				}
			}
		}
	}
	for(ll k=1;k<=n;k++)
	{
		for(ll i=1;i<=n;i++)
		{
			for(ll j=1;j<=n;j++)
			{
				if(i==j||j==k||i==k)continue; 
				if(dis[i][j]==dis[i][k]+dis[k][j])
					ans[k]+=(1.0*edge[i][k]*edge[k][j])/edge[i][j];
			}
		}
	}
	for(ll i=1;i<=n;i++)
		printf("%.3lf\n",ans[i]);
	return 0;
}
