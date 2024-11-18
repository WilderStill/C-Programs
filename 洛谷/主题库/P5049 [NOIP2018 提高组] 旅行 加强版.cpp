#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0;
	char ch=getchar();
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
	return x;
}
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct node
{
	int x,y;
	bool operator <(node b){return y>b.y;}
}tp[1000010];
struct pnode
{
	int to,nxt;
}edge[1000010];
int tg,n,m,tot,hd[500100],f[500100],vis[500100],pis[500100],fg,syh;
void addedge(int u,int v)
{
	edge[++tot].to=v;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
void dfs0(int pos)
{
    vis[pos]=1;
    write(pos),putchar(' ');
    for(int i=hd[pos];i;i=edge[i].nxt)
	{
        int to=edge[i].to;
        if(!vis[to])dfs0(to);
    }
}
void dfs_circle(int pos,int fa)
{
    if(fg)return;
    if(!f[pos])f[pos]=fa;
    else if(f[pos]!=fa)
	{
        while(fa!=pos)
		{
            pis[fa]=1;
            fa=f[fa];
        }
        pis[pos]=1;
        fg=1;
        return;
    }
    for(int i=hd[pos];i;i=edge[i].nxt)
	{
        int to=edge[i].to;
        if(to==fa)continue;
        dfs_circle(to,pos);
    }
}
void dfs1(int pos)
{
	vis[pos]=1;
	write(pos),putchar(' ');
    if(pis[pos])
	{
    	int dg=0;
    	for(int i=hd[pos];i;i=edge[i].nxt)
		{
    		if(syh)break;
    		int to=edge[i].to;
    		if(vis[to])continue;
    		if(pis[to])
			{
    			i=edge[i].nxt;
    			while(vis[edge[i].to])i=edge[i].nxt;
    			if(i)tg=edge[i].to;
    			else if(to>tg)dg=syh=1;
    			break;
			}
		}
		for(int i=hd[pos];i;i=edge[i].nxt)
		{
			int to=edge[i].to;
    		if(vis[to])continue;
			if(pis[to]&&dg)continue;
			dfs1(to);
		}
	}
	else
	{
		for(int i=hd[pos];i;i=edge[i].nxt)
		{
			int to=edge[i].to;
			if(vis[to])continue;
			dfs1(to);
		}
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		tp[i].x=u,tp[i].y=v,tp[i+m].x=v,tp[i+m].y=u;
	}
	sort(tp+1,tp+2*m+1);
	for(int i=1;i<=2*m;++i)addedge(tp[i].x,tp[i].y);
	if(m<n)dfs0(1);
	else
	{
		dfs_circle(1,1);
        fg=0,tg=0x3f3f3f3f;
        dfs1(1);
	} 
	return 0;
}
