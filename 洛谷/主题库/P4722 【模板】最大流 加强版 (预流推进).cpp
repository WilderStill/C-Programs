#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define M 300010
using namespace std;
int n,m,k,s,t,ans,dis[1210],tot,now[1210],hd[1210]; 
struct node
{
	int to,nxt,val;
}edge[M];
struct shutup
{
	int u,v,w;
	inline bool operator<(shutup b){return w>b.w;}
}mp[M];
inline void addedge(int u,int v,int w)
{
	tot+=2;
	edge[tot].to=v;
	edge[tot].val=w;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
inline void newedge(int u,int v)
{
	tot+=2;
	edge[tot].to=v;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
inline bool bfs()
{
	for(int i=1;i<=n;++i)dis[i]=INF;
	queue<int>q;
	q.push(s);
	dis[s]=0;
	now[s]=hd[s];
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(int i=hd[top];i;i=edge[i].nxt)
		{
			int v=edge[i].to;
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
inline int dfs(int x,int sum)
{ 
	if(x==t)return sum;
	int tmp,res=0;
	for(int i=now[x];i&&sum;i=edge[i].nxt)
	{
		now[x]=i;
		int v=edge[i].to;
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
	scanf("%d%d%d",&n,&m,&k);s=1,t=n;
	for(int i=1;i<=m;++i)scanf("%d%d%d",&mp[i].u,&mp[i].v,&mp[i].w);
	sort(mp+1,mp+m+1);
	for(int tp=0;tp<=1;++tp)
	{
		if(tp)tot=1;
		for(int p=5,i=1;~p;--p)
		{
			while(i<=m&&mp[i].w>=(1<<(p*6)))
			{
				if(tp)newedge(mp[i].v,mp[i].u);
				else addedge(mp[i].u,mp[i].v,mp[i].w);
				++i;
			}
			while(bfs())ans+=dfs(s,INF);
		}
	}
	printf("%d",ans);
	return 0;
}
