#include<bits/stdc++.h>
#define ll long long
#define M 214
using namespace std;
ll n,l,ans,x[M],t[M],f[M][M][M][2];
int main()
{
	memset(f,0x3f,sizeof(f));
	f[0][0][0][0]=f[0][0][0][1]=0;
	scanf("%lld%lld",&n,&l);
	for(ll i=1;i<=n;++i)scanf("%lld",&x[i]);x[n+1]=l;
	for(ll i=1;i<=n;++i)scanf("%lld",&t[i]);
	for(ll i=0;i<=n;++i)
		for(ll j=0;j<=n;++j)
		{
			if(i+j>=n)break;
			for(ll k=0;k<=n;++k)
			{
				if(f[i][j][k][0]<=1e13)
				{
					if(f[i][j][k][0]+x[n-i+1]-x[n-i]<=t[n-i])f[i+1][j][k+1][0]=min(f[i+1][j][k+1][0],f[i][j][k][0]+x[n-i+1]-x[n-i]);
					else f[i+1][j][k][0]=min(f[i+1][j][k][0],f[i][j][k][0]+x[n-i+1]-x[n-i]);
					if(f[i][j][k][0]+l-x[n-i+1]+x[j+1]<=t[j+1])f[i][j+1][k+1][1]=min(f[i][j+1][k+1][1],f[i][j][k][0]+l-x[n-i+1]+x[j+1]);
					else f[i][j+1][k][1]=min(f[i][j+1][k][1],f[i][j][k][0]+l-x[n-i+1]+x[j+1]);
				}
				if(f[i][j][k][1]<=1e13)
				{
					if(f[i][j][k][1]+l-x[n-i]+x[j]<=t[n-i])f[i+1][j][k+1][0]=min(f[i+1][j][k+1][0],f[i][j][k][1]+l-x[n-i]+x[j]);
					else f[i+1][j][k][0]=min(f[i+1][j][k][0],f[i][j][k][1]+l-x[n-i]+x[j]);
					if(f[i][j][k][1]+x[j+1]-x[j]<=t[j+1])f[i][j+1][k+1][1]=min(f[i][j+1][k+1][1],f[i][j][k][1]+x[j+1]-x[j]);
					else f[i][j+1][k][1]=min(f[i][j+1][k][1],f[i][j][k][1]+x[j+1]-x[j]);
				}
			}
		}
	for(ll i=0;i<=n;++i)
		for(ll j=0;j<=n;++j)
			for(ll k=0;k<=n;++k)
				if(min(f[i][j][k][0],f[i][j][k][1])<1e15)
					ans=max(ans,k);
	printf("%lld",ans);
	return 0;
}
