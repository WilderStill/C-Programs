#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define M 414514
#define ll long long
using namespace std;
ll n,m,s,t,ans,dis[M],tot=1,now[M],hd[M],mp[415][415];
const pair<ll,ll>d[4]={{-1,0},{0,-1},{0,1},{1,0}};
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
}
bool bfs()
{
	for(int i=0;i<M;i++)dis[i]=INF;
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
ll dfs(ll x,ll flow=INF)
{ 
	if(x==t)return flow;
	ll tmp,res=0;
	for(ll i=now[x];i&&flow;i=edge[i].nxt)
	{
		now[x]=i;
		ll v=edge[i].to;
		if(edge[i].val&&(dis[v]==dis[x]+1))
		{
			tmp=dfs(v,min(flow,edge[i].val));
			if(!tmp)dis[v]=INF;
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
	scanf("%lld%lld",&n,&m);
	s=0,t=n*m*2+1;
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
			scanf("%lld",&mp[i][j]);
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
		{
			if(mp[i][j]==-1)continue;
			else if(mp[i][j]==0)
			{
				addedge((i-1)*m+j,(i-1)*m+j+n*m,INF);
				addedge((i-1)*m+j+n*m,(i-1)*m+j,0);
				addedge(s,(i-1)*m+j,INF);
				addedge((i-1)*m+j,s,0);
			}
			else
			{
				addedge((i-1)*m+j,(i-1)*m+j+n*m,mp[i][j]);
				addedge((i-1)*m+j+n*m,(i-1)*m+j,0);
			}
			for(ll k=0;k<4;k++)
			{
				ll dx=i+d[k].first,dy=j+d[k].second;
				if(1<=dx&&dx<=n&&1<=dy&&dy<=n&&mp[dx][dy]!=-1)
				{
					addedge((i-1)*m+j+n*m,(dx-1)*m+dy,INF);
					addedge((dx-1)*m+dy,(i-1)*m+j+n*m,0);
				}
			}
			if(i==1||j==1||i==n||j==m)addedge((i-1)*m+j+n*m,t,INF),addedge(t,(i-1)*m+j+n*m,0);
		}
	while(bfs())ans+=dfs(s);
	printf("%lld",ans);
	return 0;
}
