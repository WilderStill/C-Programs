#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,s,t,num,ans,sum,dep[50000],tot=1,now[50000],hd[50000];
int dx[5]={0,-1,1,0,0},dy[5]={0,0,0,-1,1};
struct node
{
	ll to,nxt,val;
}edge[50000];
inline void addedge(int u,int v,ll w)
{
	edge[++tot].to=v;
	edge[tot].val=w;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
inline bool bfs()
{
	queue<int>q;
	memset(dep,0,sizeof(dep));
	q.push(s);
	dep[s]=1;
	now[s]=hd[s];
    while(!q.empty())
	{
		int u=q.front();
		q.pop();
		for(int i=hd[u];i;i=edge[i].nxt)
		{
			int to=edge[i].to;
			if(edge[i].val&&!dep[to])
			{
				dep[to]=dep[u]+1;
		        now[to]=hd[to];
				q.push(to);
			}
		}
	}
	return dep[t];	
}
inline ll dfs(int x,ll flow)
{ 
	if(x==t)return flow;
	ll tmp,res=0;
	for(int i=now[x];i&&flow;i=edge[i].nxt)
	{
		now[x]=i;
		int v=edge[i].to;
		if(edge[i].val&&dep[v]==dep[x]+1)
		{
			tmp=dfs(v,min(flow,edge[i].val));
			edge[i].val-=tmp;
			edge[i^1].val+=tmp;
			res+=tmp;
			flow-=tmp;
		}
	}
	if(!res)dep[x]=0;
	return res;
}
int main()
{
	scanf("%lld",&n);
	s=0,t=n*n+1;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=n;++j)
		{
			scanf("%lld",&num);
			sum+=num;
			if((i+j)&1)
			{
				addedge((i-1)*n+j,t,num);
				addedge(t,(i-1)*n+j,0);
			}
			else
			{
				addedge(s,(i-1)*n+j,num);
				addedge((i-1)*n+j,s,0);
				for(int k=1;k<=4;++k)
				{
					int dxx=i+dx[k],dyy=j+dy[k];
					if(1<=dxx&&dxx<=n&&1<=dyy&&dyy<=n)
					{
						addedge((i-1)*n+j,(dxx-1)*n+dyy,1e18);
						addedge((dxx-1)*n+dyy,(i-1)*n+j,0);
					}
				}
			}
		}
	while(bfs())ans+=dfs(s,1e18);
	printf("%lld",sum-ans);
	return 0;
}
