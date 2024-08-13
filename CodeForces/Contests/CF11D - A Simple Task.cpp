#include<bits/stdc++.h>
#define ll long long
#define M 21
using namespace std;
bool mp[M][M];
ll n,m,ans,f[566514][M];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=1,u,v;i<=m;++i)
	{
		scanf("%lld%lld",&u,&v);
		mp[u-1][v-1]=mp[v-1][u-1]=1;
	}
	for(int i=0;i<n;++i)f[1<<i][i]=1;
	for(int i=1;i<=1<<n;++i)
		for(int j=0;j<n;++j)
			for(int k=0;k<n;++k)
			{
				if(!mp[j][k])continue;
				if((i&-i)>1<<k)continue;
				if(1<<k&i)
				{
					if(1<<k==(i&-i))
						ans+=f[i][j];
				}
				else f[i|1<<k][k]+=f[i][j];
			}
	printf("%lld",(ans-m)>>1);
	return 0;
}
