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
int m,n,q,tot,hd[100010];
int dis[100010],s[100010];
bool vis[100010];
struct edge
{
	int to,nxt,val;
}edge[400010];
void addedge(int u,int v,int w)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	edge[tot].val=w;
	hd[u]=tot;
}
int dijkstra(int st,int ed)
{
    if(s[ed])return s[ed];
    memset(vis,0,sizeof(vis));
    vis[st]=1;
	dis[st]=0;
    s[ed]=max(s[ed],dis[st]);
    queue<int>q;
    q.push(st);
    while(!q.empty())
	{
        int top=q.front();
		q.pop();
        for(int i=hd[top];i;i=edge[i].nxt)
		{
            int v=edge[i].to;
            if(edge[i].val>ed||vis[v])continue;
            dis[v]=dis[top]+1;
            s[ed]=max(s[ed],dis[v]);
            vis[v]=1;
            q.push(v);
        }
    }
    return s[ed];
}
int main()
{
    n=read(),m=read(),q=read();
    for(int i=1;i<=m;++i)
	{
        int u=read(),v=read();
        addedge(u,v,0),addedge(v,u,0);
    }
    for(int i=1;i<=q;++i)
	{
        int u=read(),v=read();
        addedge(u,v,i),addedge(v,u,i);
    }
    int x=dijkstra(1,0),p=1;
    write(x),putchar(' ');
    while(p<=q)
	{
        int l=p,r=q;
        while(l<=r)
		{
            int mid=(l+r)>>1;
            if((dijkstra(1,mid)*2)>=x)l=mid+1;
            else r=mid-1;
        }
        for(int i=p;i<=r;++i)write(x),putchar(' ');
        p=r+1;
		x=s[p];
    }
    return 0;
}

