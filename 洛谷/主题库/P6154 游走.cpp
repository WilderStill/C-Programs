#include<bits/stdc++.h>
#define ll long long
#define mod 998244353
#define N 114514
#define M 714514
using namespace std;
ll n,m,sum,cnt,tot,hd[N],f[2][N];
struct edge
{
	ll nxt,to;
}edge[M];
ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
}
void addedge(ll u,ll v)
{
	edge[++cnt].to=v;
	edge[cnt].nxt=hd[u];
	hd[u]=cnt;
}
void dfs(int pos)
{
	if(f[0][pos])return;
	f[0][pos]=1;
	for(ll i=hd[pos];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		dfs(v);
		f[0][pos]=(f[0][pos]+f[0][v])%mod;
		f[1][pos]=(f[1][pos]+f[0][v]+f[1][v])%mod;
	}
}
int main()
{
	memset(hd,-1,sizeof hd);
	scanf("%lld%lld",&n,&m);
	for(ll i=1,u,v;i<=m;++i)
	{
		scanf("%lld%lld",&u,&v);
		addedge(u,v);
	}
	for(ll i=1;i<=n;++i)if(!f[0][i])dfs(i);
	for(ll i=1;i<=n;++i)
		tot=(tot+f[0][i])%mod,sum=(sum+f[1][i])%mod;
	printf("%lld",(sum*qpow(tot,mod-2))%mod);
	return 0;
}
