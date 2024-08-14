#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define M 4114514
#define ll long long
using namespace std;
ll n,m,k,s,t,ans,depth[M],tot=1,now[M],hd[M]; 
struct node
{
	ll to,nxt,val;
}edge[M];
void addedge(ll u,ll v,ll w)
{
	edge[++tot].to=v;
	edge[tot].val=w;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
	edge[++tot].to=u;
	edge[tot].val=0;
	edge[tot].nxt=hd[v];
	hd[v]=tot;
}
bool bfs()
{
	for(int i=0;i<M;i++)depth[i]=INF;
	queue<ll>q;
	q.push(s);
	depth[s]=0;
	now[s]=hd[s];
	while(q.size())
	{
		ll top=q.front();
		q.pop();
		for(ll i=hd[top];i;i=edge[i].nxt)
		{
			ll v=edge[i].to;
			if(edge[i].val>0&&depth[v]==INF)
			{
				q.push(v);
				now[v]=hd[v];
				depth[v]=depth[top]+1;
				if(v==t)return 1;
			}
		}
	}
	return 0;
}
ll dfs(ll x,ll flow=INF)
{ 
	if(x==t)return flow;
	ll tmp,res=0;
	for(ll i=now[x];i&&flow;i=edge[i].nxt)
	{
		now[x]=i;
		ll v=edge[i].to;
		if(edge[i].val>0&&(depth[v]==depth[x]+1))
		{
			tmp=dfs(v,min(flow,edge[i].val));
			if(!tmp)depth[v]=INF;
			edge[i].val-=tmp;
			edge[i^1].val+=tmp;
			res+=tmp;
			flow-=tmp;
		}
	}
	return res;
}
int main()
{
	scanf("%lld%lld%lld%lld",&n,&m,&s,&t);
	for(ll i=1;i<=n;i++)addedge(i,i+n,1);
	for(ll i=1,u,v,w;i<=m;i++)
	{
		scanf("%lld%lld",&u,&v);
		addedge(u+n,v,INF);
		addedge(v+n,u,INF);
	}
	while(bfs())ans+=dfs(s+n);
	printf("%lld",ans);
	return 0;
}
