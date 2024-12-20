#include<bits/stdc++.h>
#define int long long
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
const int M=1000010,INF=0x3f3f3f3f3f3f3f3f;
struct node
{
    int from,to,nxt,val;
}edge[M<<1];
int dotnum,tot,hd[M],fa[M],dist[M];
inline void addedge(int u,int v,int w)
{
	edge[++tot].from=u;
	edge[tot].to=v;
	edge[tot].val=w;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
inline void build(int n,int m,bool isDir,bool isVal)
{
	tot=0,dotnum=n;
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=isVal?read():0;
		if(u==v)continue;
		addedge(u,v,w);
		if(!isDir)addedge(v,u,w);
	}
}
bool vis[M];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
inline void dijkstra(int s)
{
	for(int i=0;i<M;++i)dist[i]=INF;
	dist[s]=0;
	q.push({0,s});
    while(!q.empty())
    {
        int top=q.top().second;
		q.pop();
        if(vis[top])continue;
        vis[top]=1;
        for(int i=hd[top];i;i=edge[i].nxt)
        {
            int to=edge[i].to;
            if(dist[to]>dist[top]+edge[i].val)
            {
                dist[to]=dist[top]+edge[i].val;
                if(!vis[to])q.push({dist[to],to});
            }
        }
    }
}
signed main()
{
	int n=read(),m=read(),s=1;
	build(n,m,1,1);
	dijkstra(s);
	for(int i=1;i<=n;++i)
        printf("%lld ",dist[i]==INF?-1:dist[i]);
    return 0;
}
