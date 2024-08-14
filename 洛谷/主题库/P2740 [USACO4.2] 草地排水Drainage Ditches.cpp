#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define M 514514
#define ll long long
using namespace std;
ll n,m,s,t,ans,dis[M],tot=1,now[M],hd[M]; 
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
ll bfs()
{
	for(ll i=1;i<=n;i++)dis[i]=INF;
	queue<ll>q;
	q.push(s);
	dis[s]=0;
	now[s]=hd[s];
	while(q.size())
	{
		ll top=q.front();
		q.pop();
		for(ll i=hd[top];i;i=edge[i].nxt)
		{
			ll v=edge[i].to;
			if(edge[i].val>0&&dis[v]==INF)
			{
				q.push(v);
				now[v]=hd[v];
				dis[v]=dis[top]+1;
				if(v==t)return 1;
			}
		}
	}
	return 0;
}
ll dfs(ll x,ll sum)
{ 
	if(x==t)return sum;
	ll tmp,res=0;
	for(ll i=now[x];i&&sum;i=edge[i].nxt)
	{
		now[x]=i;
		ll v=edge[i].to;
		if(edge[i].val>0&&(dis[v]==dis[x]+1))
		{
			tmp=dfs(v,min(sum,edge[i].val));
			if(!tmp)dis[v]=INF;
			edge[i].val-=tmp;
			edge[i^1].val+=tmp;
			res+=tmp;
			sum-=tmp;
		}
	}
	return res;
}
int main()
{
	scanf("%lld%lld",&m,&n);
	s=1,t=n;
	for(ll i=1,u,v,w;i<=m;i++)
	{
		scanf("%lld%lld%lld",&u,&v,&w);
		addedge(u,v,w);
	}
	while(bfs())ans+=dfs(s,INF);
	printf("%lld",ans);
	return 0;
}
