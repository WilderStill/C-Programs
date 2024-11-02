#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define M 414514
#define ll long long
using namespace std;
ll n,m,T,s,t,ans,dis[M],tot=1,now[M],hd[M],mp[415][415];
const pair<ll,ll>d[8]={{-1,-2},{-2,-1},{2,-1},{1,-2},{-1,2},{-2,1},{2,1},{1,2}};
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
	scanf("%lld%lld%lld",&n,&m,&T);
	s=0,t=n*m+1;
	for(ll i=1,a,b;i<=T;i++)
	{
		scanf("%lld%lld",&a,&b);
		mp[a][b]=1;
	}
	for(ll i=1;i<=n;i++)
		for(ll j=1;j<=m;j++)
		{
			if(mp[i][j])continue;
			if((i+j)%2)
			{
				addedge((i-1)*m+j,t,1);
				addedge(t,(i-1)*m+j,0);
			}
			else
			{
				addedge(s,(i-1)*m+j,1);
				addedge((i-1)*m+j,s,0);
				for(ll k=0;k<8;k++)
				{
					ll dx=i+d[k].first,dy=j+d[k].second;
					if(1<=dx&&dx<=n&&1<=dy&&dy<=m&&!mp[dx][dy])
					{
						addedge((i-1)*m+j,(dx-1)*m+dy,INF);
						addedge((dx-1)*m+dy,(i-1)*m+j,0);
					}
				}
			}
		}
	while(bfs())ans+=dfs(s);
	printf("%lld",n*m-T-ans);
	return 0;
}
