#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int Dg=63,M=500010;
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
inline ll readl()
{
    ll x=0,f=1;
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
inline void write(ll x)
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
int n,m;
ll num[110],dis[M],sum[M];
bool fg,vis[M];
struct node{int v;ll w;};
vector<node>edge[M];
inline void insert(ll x)
{
	for(int i=Dg;~i;--i)
		if(x&(1ll<<i))
		{
			if(!num[i]){num[i]=x;return;}
            x^=num[i];
		}
    fg=1;   
}
inline ll querymin(ll syh)
{
	ll res=syh;
	for(int i=Dg;~i;--i)res=min(res,res^num[i]);
    return res;
}
inline void dfs0(int x)
{
	vis[x]=1;
	for(auto nxt:edge[x])
	{
		if(vis[nxt.v])continue;
		dis[nxt.v]=dis[x]^nxt.w;
		dfs0(nxt.v);
	}
}
inline void dfs1(int x)
{
	vis[x]=1;
	for(auto nxt:edge[x])
	{
		if(vis[nxt.v])
		{
			insert(sum[x]^sum[nxt.v]^nxt.w);
			continue;
		}
		sum[nxt.v]=sum[x]^nxt.w;
		dfs1(nxt.v);
	}
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=m;++i)
    {
    	int u=read(),v=read();
		ll w=readl();
    	edge[u].push_back({v,w});
    	edge[v].push_back({u,w});
	}
	memset(vis,0,sizeof vis);
    dfs0(1);
    memset(vis,0,sizeof vis);
	dfs1(1);
	write(querymin(dis[n]));
    return 0;
}
