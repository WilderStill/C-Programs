#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
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
	int from,nxt,to,val;
}edge[10010];
int n,m,rt,tot,cnt,ans,hd[10010],scc[10010],top[10010],minv[10010],fa[10010];
inline void addedge(int u,int v,int w)
{
	edge[++tot].from=u;
	edge[tot].to=v;
	edge[tot].val=w;
	edge[tot].nxt=hd[u];
	hd[u]=tot; 
}
inline void init()
{
	memset(scc,0,sizeof scc);
	memset(top,0,sizeof top);
	memset(minv,INF,sizeof minv);
	minv[rt]=cnt=0;
}
int main()
{
	n=read(),m=read(),rt=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		addedge(u,v,w);
	}
	bool fg=1;
	while(true)
	{
		init();
		for(int i=1;i<=m;++i)
			if(edge[i].from!=edge[i].to&&edge[i].val<minv[edge[i].to])
				minv[edge[i].to]=edge[i].val,fa[edge[i].to]=edge[i].from;
		for(int i=1;i<=n;++i)
			if(minv[i]==INF)
			{
				fg=0;
				goto dgsyh;
			}
		for(int i=1,u;i<=n;++i)
		{
			ans+=minv[i];
			u=i;
			while(u!=rt&&!top[u]&&!scc[u])top[u]=i,u=fa[u];
			if(u!=rt&&top[u]==i)
			{
			    scc[u]=++cnt;
			    for(int v=fa[u];v!=u;v=fa[v])scc[v]=cnt;
			}
			u=i;
			while(u!=rt&&top[u]!=i&&!scc[u])top[u]=i,u=fa[u];
		}
		if(!cnt)goto dgsyh;
		for(int i=1;i<=n;++i)if(!scc[i])scc[i]=++cnt;
		for(int i=1;i<=m;++i)
		{
			if(scc[edge[i].from]!=scc[edge[i].to])edge[i].val-=minv[edge[i].to];
			edge[i].from=scc[edge[i].from],edge[i].to=scc[edge[i].to];
		}
		n=cnt,rt=scc[rt];
	}
dgsyh:if(fg)write(ans);else puts("-1");
    return 0;
}
