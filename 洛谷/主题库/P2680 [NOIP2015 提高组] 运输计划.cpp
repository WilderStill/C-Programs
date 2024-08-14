#include<bits/stdc++.h>
#define M 312940
using namespace std;
struct node
{
	int to,nxt,w;
}e[M*2];
struct Node
{
	int u,v,Lca,Dis;
}g[M*2];
int sum,cnt=0,k,n,m,num[M],vis[M],tmp[M],head[M],d[M],dis[M],fa[M][25];
void add(int u,int v,int w)
{
	k++;
	e[k].to=v;
	e[k].nxt=head[u];
	e[k].w=w;
	head[u]=k;
}
void dfs(int x,int dep)
{
	cnt++;
	num[cnt]=x;
	d[x]=dep;
	vis[x]=1;
	for(int i=1;i<25;i++)
		fa[x][i]=fa[fa[x][i-1]][i-1];
	for(int i=head[x];i>0;i=e[i].nxt)
	{
		int v=e[i].to;
		if(!vis[v])
		{
			fa[v][0]=x;
			dis[v]=dis[x]+e[i].w;
			dfs(v,dep+1);
		}
	}
}
int lca(int x,int y)
{
	if(d[x]<d[y]) swap(x,y);
	int t=d[x]-d[y];
	for(int i=0;i<=24;i++)
		if((1<<i)&t)
			x=fa[x][i];
	if(x==y) return x;
	for(int i=24;i>=0;i--)
		if(fa[x][i]!=fa[y][i])
		{
			x=fa[x][i];
			y=fa[y][i];
		}
	return fa[x][0];
}
bool check(int mid)
{
	int cnt=0,ans=0;
	memset(tmp,0,sizeof(tmp));
	for(int i=1;i<=m;i++)
		if(g[i].Dis>mid)
		{
			tmp[g[i].u]++;tmp[g[i].v]++;tmp[g[i].Lca]-=2;
			ans=max(ans,g[i].Dis-mid);
			cnt++;
		}
	if(!cnt) return true;
	for(int i=n;i>=1;i--) tmp[fa[num[i]][0]]+=tmp[num[i]];
	for(int i=2;i<=n;i++) if(tmp[i]==cnt&&dis[i]-dis[fa[i][0]]>=ans) return true;
	return false;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1,x,y,w;i<=n-1;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		add(x,y,w);
		add(y,x,w);
		sum+=w;
	}
	dis[1]=0;
	dfs(1,1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&g[i].u,&g[i].v);
		g[i].Lca=lca(g[i].u,g[i].v);
		g[i].Dis=dis[g[i].u]+dis[g[i].v]-2*dis[g[i].Lca];
	}
	int l=0,r=sum;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d",l);
	return 0;
}
