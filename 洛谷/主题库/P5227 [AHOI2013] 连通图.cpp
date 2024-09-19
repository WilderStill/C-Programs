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
mt19937 syh(time(0));
int n,m,tim,dfn[M];
ll num[110],val[M];
struct node{int v,id;};
vector<node>edge[M];
inline bool insert(ll x)
{
	for(int i=Dg;~i;--i)
		if(x&(1ll<<i))
		{
			if(!num[i]){num[i]=x;return 1;}
            x^=num[i];
		}
    return 0;   
}
inline void dfs(int x,int fa)
{
	int sum=0;
	dfn[x]=++tim;
	for(auto nxt:edge[x])
	{
		if(nxt.id==fa)continue;
		if(dfn[nxt.v])
		{
			if(dfn[nxt.v]<dfn[x])
				val[nxt.id]=syh()%998244353;
		}
		else dfs(nxt.v,nxt.id);
		sum^=val[nxt.id]; 
	}
	val[fa]=sum;
}
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=m;++i)
    {
    	int u=read(),v=read();
    	edge[u].push_back({v,i});
    	edge[v].push_back({u,i});
	}
    dfs(1,0);
	int q=read();
	while(q--)
	{
		int k=read();bool fg=1;
		memset(num,0,sizeof num);
		for(int j=1;j<=k;++j)
		{
			ll x=readl();
			fg=insert(val[x])?fg:0;
		}
		puts(fg?"Connected":"Disconnected");
	}	
    return 0;
}
