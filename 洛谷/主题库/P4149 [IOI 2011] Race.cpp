#include<bits/stdc++.h>
#define getchar getchar_unlocked
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
const int M=200004,N=1000001,INF=0x3f3f3f3f;
struct node{int nxt,to,val;}edge[M<<1];
int n,k,tot,root,sum,cnt,hd[M],f[M],sz[M],d[M],dis[M];
bool vis[M];
inline void addedge(int u,int v,int w){edge[++tot]={hd[u],v,w},hd[u]=tot;return;}
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
inline void getdis(int rt,int fa,int dk,int dc)
{
    if(dk>k)return;
    dis[++cnt]=dk,d[cnt]=dc;
    for(int i=hd[rt];i;i=edge[i].nxt)
    {
        int to=edge[i].to,val=edge[i].val;
        if(to==fa||vis[to])continue;
        getdis(to,rt,dk+val,dc+1);
    }
    return;
}
int ans=INF,buk[N];
inline void query(int rt)
{
    buk[0]=0,cnt=0;
    for(int i=hd[rt];i;i=edge[i].nxt)
    {
        int to=edge[i].to,val=edge[i].val,pnt=cnt;
        if(vis[to])continue;
		getdis(to,rt,val,1);
        for(int j=pnt+1;j<=cnt;++j)ans=min(ans,buk[k-dis[j]]+d[j]);
		for(int j=pnt+1;j<=cnt;++j)buk[dis[j]]=min(buk[dis[j]],d[j]);
    }
    for(int i=1;i<=cnt;++i)buk[dis[i]]=INF;
    return;
}
inline void solve(int rt)
{
    vis[rt]=1,query(rt);
    for(int i=hd[rt];i;i=edge[i].nxt)
    {
        int to=edge[i].to;
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
    n=read(),k=read();
    for(int i=1;i<n;++i)
    {
        int u=read()+1,v=read()+1,w=read();
        addedge(u,v,w),addedge(v,u,w);
    }
    f[0]=sum=n;
	root=0,getrt(1,0);
	memset(buk,INF,sizeof buk);
    solve(root);
    if(ans>=n)puts("-1");
    else write(ans);
    return 0;
}
