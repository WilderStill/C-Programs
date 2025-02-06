#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch<='9'&&ch>='0')
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x;
}
const int M=200004,N=100000004,INF=0x3f3f3f3f;
struct node
{
	int nxt,to,val;
}edge[M<<1];
int n,m,k[M],tot,hd[M];
inline void addedge(int u,int v,int w)
{
	edge[++tot].nxt=hd[u];
	edge[tot].to=v;
	edge[tot].val=w;
	hd[u]=tot;
	return;
}
int root,sum,sz[M],f[M];
bool vis[M];
inline void getrt(int rt,int fa)
{
    sz[rt]=1,f[rt]=0;
    for(int i=hd[rt];i;i=edge[i].nxt)
    {
        int to=edge[i].to;
        if(vis[to]||to==fa)continue;
        getrt(to,rt);
        sz[rt]+=sz[to];
        f[rt]=max(f[rt],sz[to]);
    }
    f[rt]=max(f[rt],sum-sz[rt]);
    if(f[rt]<f[root])root=rt;
    return;
}
int cnt,d[M],dis[M];
inline void getdis(int rt,int fa)
{
    d[++cnt]=dis[rt];
    for(int i=hd[rt];i;i=edge[i].nxt)
    {
        int to=edge[i].to,val=edge[i].val;
        if(to==fa||vis[to])continue;
        dis[to]=dis[rt]+val;
        getdis(to,rt);
    }
    return;
}
int knt,ans[M],buk[N],q[M];
inline void query(int rt)
{
    buk[0]=1,knt=0;
    for(int i=hd[rt];i;i=edge[i].nxt)
    {
        int to=edge[i].to,val=edge[i].val;
        if(vis[to])continue;
        cnt=0,dis[to]=val;
		getdis(to,rt);
        for(int j=1;j<=cnt;++j)
            for(int l=1;l<=m;++l)
                if(k[l]>=d[j])ans[l]|=buk[k[l]-d[j]];
		for(int j=1;j<=cnt;++j)q[++knt]=d[j],buk[d[j]]=1;
    }
    for(int i=1;i<=knt;++i)buk[q[i]]=0;
    return;
}
inline void solve(int rt)
{
    vis[rt]=1;
    query(rt);
    for(int i=hd[rt];i;i=edge[i].nxt)
    {
        int to=edge[i].to,val=edge[i].val;
        if(vis[to])continue;
		root=0,f[0]=n;
        sum=sz[to];
        getrt(to,rt);
		solve(root);
    }
    return;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<n;++i)
    {
        int u=read(),v=read(),w=read();
        addedge(u,v,w),addedge(v,u,w);
    }
    for(int i=1;i<=m;++i)k[i]=read();
    f[0]=sum=n;
    root=0,getrt(1,0);
    solve(root);
    for(int i=1;i<=m;++i)puts(!ans[i]?"NAY":"AYE");
    return 0;
}
