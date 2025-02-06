#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0'||ch>'9')
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(ch<='9'&&ch>='0')
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
		x=-x;
	}
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int M=40010;
struct node
{
	int nxt,to,val;
}edge[M<<1];
int n,k,tot,hd[M];
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
inline int query(int rt,int val)
{
    cnt=0,dis[rt]=val;
	getdis(rt,0);
    sort(d+1,d+cnt+1);
    int l=1,r=cnt,res=0;
    while(l<=r)
    {
        if(d[l]+d[r]>k)--r;
        else res+=r-l,++l;
    }
    return res;
}
inline int solve(int rt)
{
    vis[rt]=1;
	int res=query(rt,0);
    for(int i=hd[rt];i;i=edge[i].nxt)
    {
        int to=edge[i].to,val=edge[i].val;
        if(vis[to])continue;
        res-=query(to,val);
		root=0,f[0]=n;
        sum=sz[to];
        getrt(to,rt);
		res+=solve(root);
    }
    return res;
}
int main()
{
    n=read();
    for(int i=1;i<n;++i)
    {
        int u=read(),v=read(),w=read();
        addedge(u,v,w),addedge(v,u,w);
    }
    k=read();
    f[0]=sum=n;
	root=0,getrt(1,0);
    write(solve(root));
    return 0;
}
