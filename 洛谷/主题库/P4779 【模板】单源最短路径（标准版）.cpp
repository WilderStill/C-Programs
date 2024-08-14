#include<bits/stdc++.h>
#define Maxn 114514
#define Maxm 541141
#define INF 0x7fffffff
using namespace std; 
struct edge
{
    int to,dis,nxt;
};
edge e[Maxm];
int head[Maxn],dis[Maxn],tot,n,m,s;
bool vis[Maxn];
void add_edge(int u,int v,int d)
{
    tot++;
    e[tot].dis=d;
    e[tot].to=v;
    e[tot].nxt=head[u];
    head[u]=tot;
}

struct node
{
    int dis,pos;
    bool operator <( const node &x )const
    {
        return x.dis<dis;
    }
};
priority_queue<node> q;
void dijkstra()
{
    dis[s] = 0;
    node tmp={0,s};
    q.push(tmp);
    while(!q.empty())
    {
        tmp=q.top();
        q.pop();
        int x=tmp.pos,d=tmp.dis;
        if(vis[x]) continue;
        vis[x]=1;
        for(int i=head[x];i;i=e[i].nxt)
        {
            int y=e[i].to;
            if(dis[y]>dis[x]+e[i].dis)
            {
                dis[y]=dis[x]+e[i].dis;
                if(!vis[y])
                {
                	tmp={dis[y],y};
                    q.push(tmp);
                }
            }
        }
    }
}


int main()
{
    scanf("%d%d%d",&n,&m,&s);
    for(int i=1;i<=n;i++)dis[i]=INF;
    for(int i=0,u,v,d;i<m;i++)
    {
        scanf("%d%d%d",&u,&v,&d);
        add_edge(u,v,d);
    }
    dijkstra();
    for(int i=1;i<=n;i++)printf("%d ",dis[i]);
    return 0;
}
