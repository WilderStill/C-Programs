#include<bits/stdc++.h>
using namespace std;
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
int m,n,etot=1,ttot=1,tp[200010],ehd[200010],thd[200010];
bool vis[200010];
struct edge
{
	int from,to,nxt;
	bool tedge;
}edge[400010],tree[400010];
void addedge(int u,int v)
{
	edge[++etot].nxt=ehd[u];
	edge[etot].from=u;
	edge[etot].to=v;
	edge[etot].tedge=0;
	ehd[u]=etot;
}
void addtree(int u,int v)
{
	tree[++ttot].nxt=thd[u];
	tree[ttot].from=u;
	tree[ttot].to=v;
	tree[etot].tedge=1;
	thd[u]=ttot;
}
void build(int rt,int fa)
{
	vis[rt]=1;
	for(int i=ehd[rt];i;i=edge[i].nxt)
	{
		int v=edge[i].to;
		if(v==fa||vis[v])continue;
		edge[i].tedge=edge[i^1].tedge=1;
		addtree(edge[i].from,edge[i].to);
		addtree(edge[i^1].from,edge[i^1].to);
		build(v,rt);
	}
}
void dfs(int rt,int fa)
{
	for(int i=thd[rt];i;i=tree[i].nxt)
	{
		int v=tree[i].to;
		if(v==fa)continue;
		dfs(v,rt);
		if(tp[v]&1)write(v),putchar(' '),write(rt),putchar('\n'),++tp[v];
		else write(rt),putchar(' '),write(v),putchar('\n'),++tp[rt];
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		addedge(u,v);
		addedge(v,u);
	}
	if(m&1)
	{
		write(-1);
		return 0;
	}
	build(1,0);
	for(int i=2;i<=etot;++i)
	{
		if(!edge[i].tedge)
		{
			edge[i].tedge=edge[i^1].tedge=1;
			++tp[edge[i].to];
			write(edge[i].to),putchar(' '),write(edge[i].from),putchar('\n');
		}
	}
	dfs(1,0);
	return 0;
}
