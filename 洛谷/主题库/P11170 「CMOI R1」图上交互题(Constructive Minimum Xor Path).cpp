#include<bits/stdc++.h>
#define M 1000010 
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
struct enode
{
	int from,to,val;
}line[M];
struct gnode
{
	int nxt,to,val;
}edge[M<<1];
int tot,hd[M],sum[M];
bool vis[M];
inline void addedge(int u,int v)
{
	edge[++tot].to=v;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
inline void dfs(int pos,int val)
{
    sum[pos]=val;
	vis[pos]=1;
    for(int i=hd[pos];i;i=edge[i].nxt)
	{
		int id=edge[i].to,to=pos^line[id].from^line[id].to;
		if(vis[to])continue;
    	dfs(to,val^line[id].val);
	}
}
int main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		line[i]={read(),read(),read()};
		addedge(line[i].from,i),addedge(line[i].to,i);
	}
	for(int i=1;i<=n;++i)if(!vis[i])dfs(i,0);
	for(int i=1;i<=m;++i)if(sum[line[i].from]^sum[line[i].to]^line[i].val)return puts("No"),0;
	puts("Yes");
	for(int i=1;i<=m;++i)write(line[i].val),putchar(' ');
	return 0;
}
