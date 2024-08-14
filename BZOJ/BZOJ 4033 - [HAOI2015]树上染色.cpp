#include<bits/stdc++.h>
#define ll long long
#define M 2154
using namespace std;
ll n,q,cnt,head[M],size[M],f[M][M];
struct node
{
	ll nxt,to,val;
}edge[M<<2];
void addedge(ll u,ll v,ll w)
{
	edge[++cnt].to=v;
	edge[cnt].nxt=head[u];
	edge[cnt].val=w;
	head[u]=cnt;
}
void dfs(ll x,ll fa)
{
	size[x]=1;
	f[x][0]=f[x][1]=0;
	for(ll i=head[x];~i;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(v==fa)continue;
		dfs(v,x);
		size[x]+=size[v];
		for(ll j=min(size[x],q);j>=0;--j)
		{
			if(f[x][j]!=-1)f[x][j]+=(f[v][0]+size[v]*(n-q-size[v])*edge[i].val);
			for(ll k=1;k<=min(size[v],j);++k)
			{
				if(f[x][j-k]==-1)continue;
				f[x][j]=max(f[x][j],f[x][j-k]+f[v][k]+(k*(q-k)+(size[v]-k)*(n-q-size[v]+k))*edge[i].val);
			}
		} 		
	}
}
int main()
{
	memset(head,-1,sizeof head);
	memset(f,-1,sizeof f);
	scanf("%lld%lld",&n,&q);
	q=n-q<=q?n-q:q;
	for(ll i=1,x,y,z;i<n;++i)
	{
		scanf("%lld%lld%lld",&x,&y,&z);
		addedge(x,y,z);addedge(y,x,z);
	}
	dfs(1,-1);
	printf("%lld",f[1][q]);
	return 0;
}
