#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read()
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
struct edge
{
	int nxt,to,id;
}edge[4000010];
ll hd[4000010],dep[4000010],syh[4000100],tot,v[4000100];
bool vis[4000010],gs[4000010];
void addedge(ll u,ll v,ll w)
{
	edge[++tot].to=v;
	edge[tot].id=w;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
void dfs(ll pos)
{
	vis[pos]=1;
	for(ll i=hd[pos];i;i=edge[i].nxt)
	{
		if(edge[i].id==syh[pos])continue;
		if(!vis[edge[i].to])
		{
			syh[edge[i].to]=edge[i].id;
			dep[edge[i].to]=dep[pos]+1;
			dfs(edge[i].to);
			v[syh[pos]]^=v[syh[edge[i].to]];
		}
		else
		{
			if(!gs[edge[i].id])
			{
				gs[edge[i].id]=1;
				v[edge[i].id]=0;
				for(int j=1;j<=21;++j)v[edge[i].id]^=v[edge[i].id]*8+rand()%8;
				v[syh[pos]]^=v[edge[i].id];
			}
			else v[syh[pos]]^=v[edge[i].id];
		}
		
	}
	if(!syh[pos])v[0]=0;
}
int main()
{
	//freopen("sharkboo.in","r",stdin);
	//freopen("sharkboo.out","w",stdout);
	srand(time(0));
	int n=read(),m=read();
	for(ll i=1;i<=m;++i)
	{
		ll u=read(),v=read();
		addedge(u,v,i);
		addedge(v,u,i);
	}
	dfs(1);
	sort(v+1,v+m+1);
	ll tmp=m;
	for(ll i=1;i<=m;++i)
	{
		if(v[i])
		{
			tmp=i-1;
			break;
		}
	}
	ll ans=tmp*(m-tmp)+tmp*(tmp-1)/2,dg=0;
	for(ll i=tmp+1;i<=m;++i)
	{
		if(v[i]^v[i-1])
		{
			ans+=dg*(dg-1)/2;
			dg=0;
		}
		++dg;
	}
	ans+=dg*(dg-1)/2;
	write(ans);
	return 0;
}
