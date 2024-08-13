#include<bits/stdc++.h>
#define ll long long
#define M 114514
using namespace std;
struct Edge
{
	int to,nxt,val;
}tedge[M<<1],gedge[M<<1];
int m,n,qs,ttot,gtot,thd[M],ghd[M],f[M][22],dep[M];
void gaddedge(int u,int v,int w)
{
	gedge[++gtot].val=w;
	gedge[gtot].to=v;
	gedge[gtot].nxt=ghd[u];
	ghd[u]=gtot;
}
void taddedge(int u,int v,int w)
{
	tedge[++ttot].val=w;
	tedge[ttot].to=v;
	tedge[ttot].nxt=thd[u];
	thd[u]=ttot;
}
ll tdis[M];
void dfs(int x,int fa)
{
	f[x][0]=fa;
	dep[x]=dep[fa]+1;
	for(int i=thd[x];i;i=tedge[i].nxt)
	{
		int v=tedge[i].to;
		if(v==fa)continue;
		tdis[v]=tdis[x]+tedge[i].val;
		dfs(v,x);
	}
}
int lca(int x,int v)
{
	if(dep[x]<dep[v])swap(x,v);
	int ht=dep[x]-dep[v];
	for(int i=20-1;i>=0;--i)if(ht&(1<<i))x=f[x][i];
	if(x==v)return x;
	for(int i=20-1;i>=0;--i)if(f[x][i]^f[v][i])x=f[x][i],v=f[v][i];
	return f[x][0];
}
ll dist(int u,int v){return tdis[u]+tdis[v]-tdis[lca(u,v)]*2;}
vector<ll>s,gdis[M];
bool vis[M];
priority_queue<pair<ll,int>> q;
void dijkstra(int pos)
{
	memset(vis,0,sizeof(vis));
	gdis[pos].resize(n+1);
	for(int i=1;i<=n;++i)gdis[pos][i]=0x3f3f3f3f3f;
	gdis[pos][pos]=0,q.push({0,pos});
	while(q.size())
	{
		auto top=q.top();
		q.pop();
		int x=top.second;
		if(vis[x])continue;
		vis[x]=1;
		for(int i=ghd[x];i;i=gedge[i].nxt)
		{
			int v=gedge[i].to;
			if(gdis[pos][x]+gedge[i].val<gdis[pos][v])
			{
				gdis[pos][v]=gdis[pos][x]+gedge[i].val;
				q.push(make_pair(-gdis[pos][v],v));
			}	
		}
	}
}
int fa[M];
bool fg[M];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
void merge(int x,int y){fa[find(x)]=fa[find(y)];}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)fa[i]=i;
	for(int i=1,u,v,w;i<=m;++i)
	{
		scanf("%d%d%d",&u,&v,&w);
		gaddedge(u,v,w),gaddedge(v,u,w);
		if(find(u)!=find(v))merge(u,v),taddedge(u,v,w),taddedge(v,u,w);
		else
		{
			if(!fg[u])s.push_back(u);
			if(!fg[v])s.push_back(v);
			fg[u]=fg[v]=1;
		}
	}
	dfs(1,0);
	for(int j=1;j<20;++j)
		for(int i=1;i<=n;++i)
			f[i][j]=f[f[i][j-1]][j-1];
	for(auto i:s)dijkstra(i);
	scanf("%d",&qs);
	for(int t=1,u,v;t<=qs;++t)
	{
		scanf("%d%d",&u,&v);
		ll ans=dist(u,v);
		for(auto i:s)ans=min(ans,gdis[i][u]+gdis[i][v]);
		printf("%lld\n",ans);
	}
    return 0;
}
