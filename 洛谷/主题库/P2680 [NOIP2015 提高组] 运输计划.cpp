#include<bits/stdc++.h>
#define M 300010
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x*f;
}
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct node
{
	int to,nxt,val;
}edge[M<<1];
struct Node
{
	int from,to,lca,dis;
}graph[M<<1];
int hd[M],tot;
inline void addedge(int u,int v,int w)
{
	edge[++tot].to=v;
	edge[tot].nxt=hd[u];
	edge[tot].val=w;
	hd[u]=tot;
}
int sum,tim,n,m,dfn[M],dep[M],dis[M],fa[M][25];
bool vis[M];
inline void dfs(int pos,int d)
{
	dfn[++tim]=pos,dep[pos]=d,vis[pos]=1;
	for(int i=1;i<25;++i)fa[pos][i]=fa[fa[pos][i-1]][i-1];
	for(int i=hd[pos];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(!vis[v])
		{
			fa[v][0]=pos;
			dis[v]=dis[pos]+edge[i].val;
			dfs(v,d+1);
		}
	}
}
inline int LCA(int x,int y)
{
	if(dep[x]<dep[y])swap(x,y);
	int del=dep[x]-dep[y];
	for(int i=0;i<25;++i)
		if((1<<i)&del)
			x=fa[x][i];
	if(x==y)return x;
	for(int i=24;~i;--i)
		if(fa[x][i]^fa[y][i])
			x=fa[x][i],y=fa[y][i];
	return fa[x][0];
}
int tp[M];
inline bool check(int x)
{
	int cnt=0,ans=0;
	memset(tp,0,sizeof tp);
	for(int i=1;i<=m;++i)
		if(graph[i].dis>x)
		{
			++tp[graph[i].from],--tp[graph[i].LCA];
			++tp[graph[i].to],--tp[graph[i].LCA];
			ans=max(ans,graph[i].dis-x);
			++cnt;
		}
	if(!cnt)return 0;
	for(int i=n;i;--i)tp[fa[dfn[i]][0]]+=tp[dfn[i]];
	for(int i=2;i<=n;++i)if(tp[i]==cnt&&dis[i]-dis[fa[i][0]]>=ans)return 0;
	return 1;
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<n;++i)
	{
		int u=read(),v=read(),w=read();
		addedge(u,v,w),addedge(v,u,w);
		sum+=w;
	}
	dfs(1,1);
	for(int i=1;i<=m;++i)
	{
		graph[i].from=read(),graph[i].to=read();
		graph[i].LCA=LCA(graph[i].from,graph[i].to);
		graph[i].dis=dis[graph[i].from]+dis[graph[i].to]-(dis[graph[i].LCA]<<1);
	}
	int l=0,r=sum;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(check(mid))l=mid+1;
		else r=mid;
	}
	write(l);
	return 0;
}
