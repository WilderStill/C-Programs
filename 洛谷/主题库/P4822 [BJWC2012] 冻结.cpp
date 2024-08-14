#include<bits/stdc++.h>
#define M 1145141
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
struct edge
{
	ll v,w;
	edge(ll a,ll b){v=a,w=b;}
	bool operator<(const edge &b)const
	{
		return w>b.w;
	}
};
ll n,m,k,s,t,dis[M],vis[M];
vector<edge>to[M];
void dijkstra(ll s)
{
	for(ll i=0;i<=(k+1)*n;i++)dis[i]=INF;
	priority_queue<edge> q;
	dis[s]=0;
	q.push(edge(s,0));
	while(!q.empty())
	{
		ll x=q.top().v;
		q.pop();
		if(vis[x])continue;vis[x]=1;
		for(ll i=0;i<to[x].size();i++)
		{
			ll v=to[x][i].v,w=to[x][i].w;
			if(dis[v]>dis[x]+w)
			{
				dis[v]=min(dis[v],dis[x]+w);
				q.push(edge(v,dis[v]));
			}
		}
	}
}
int main()
{
	scanf("%lld%lld%lld",&n,&m,&k);
	s=1,t=n;
	for(ll i=0,u,v,w;i<m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		to[u].push_back(edge(v,w));to[v].push_back(edge(u,w));
		for(ll j=1;j<=k;j++)
		{
			to[u+j*n].push_back(edge(v+j*n,w));to[v+j*n].push_back(edge(u+j*n,w));
			to[u+(j-1)*n].push_back(edge(v+j*n,w/2));to[v+(j-1)*n].push_back(edge(u+j*n,w/2));
		}
	}
	for(ll i=1;i<=k;i++)to[t+(i-1)*n].push_back(edge(t+i*n,0));
	dijkstra(s);
	printf("%lld",dis[t+k*n]);
	return 0;
}
