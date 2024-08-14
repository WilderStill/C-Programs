#include<bits/stdc++.h>
#define M 301
using namespace std;
int n,m,ans,tot,hd[M],match[M],vis[M];
struct Edge
{
    int nxt,to;
}edge[6001];
void addedge(int u,int v)
{
    edge[++tot].to=v;
    edge[tot].nxt=hd[u];
    hd[u]=tot;
}
bool found(int u,int t)
{
    for(int i=hd[u];i;i=edge[i].nxt)
    {
        int v=edge[i].to;
        if(vis[v]==t)continue;
        vis[v]=t;
        if(!match[v]||found(match[v],t))
        {
            match[v]=u;match[u]=v;
            return 1;
        }
    }
    return 0;
}
void print(int u)
{
    while(u!=-n)
    {
        printf("%d ",u);
        u=match[u]-n;
    }
    puts("");
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1,u,v;i<=m;i++)scanf("%d%d",&u,&v),addedge(u,n+v);
    for(int i=1;i<=n;i++)
    {
        memset(vis,0,sizeof vis);
        if(found(i,i))ans++;
    }
    for(int i=1;i<=n;i++)if(!match[i+n])print(i);
    printf("%d\n",n-ans);
    return 0;
}
