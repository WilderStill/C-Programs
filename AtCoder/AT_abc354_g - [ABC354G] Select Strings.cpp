#include<bits/stdc++.h>
#define INF 0x3f3f3f3f3f3f3f3f
#define M 514514
#define ll long long
using namespace std;
ll n,m,s,t,ans,dis[M],tot=1,now[M],hd[M],a[M],sum;string sk[M];
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
	for(int i=0;i<M;i++)dis[i]=INF;
	queue<ll>q;
	q.push(s);
	dis[s]=0;
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
	for(ll i=hd[x];i&&flow;i=edge[i].nxt)
	{
		ll v=edge[i].to;
		if(edge[i].val>0&&(dis[v]==dis[x]+1))
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
	scanf("%lld",&n);
	s=0,t=2*n+1;
	for(int i=1;i<=n;i++)cin>>sk[i];
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		sum+=a[i];
		addedge(s,i,a[i]);
		addedge(i+n,t,a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			if(sk[i]==sk[j]&&i<j)continue;
			if(sk[i].find(sk[j])!=string::npos)addedge(i,j+n,INF);
		}
	}
	while(bfs())ans+=dfs(s);
	printf("%lld",sum-ans);
	return 0;
}
