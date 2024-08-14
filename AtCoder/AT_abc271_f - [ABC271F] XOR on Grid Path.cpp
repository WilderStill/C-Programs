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
ll n,m,k,mp[60][60],ans;
map<ll,ll>syhmp[60][60];
void dfs1(ll x,ll y,ll xsum)
{
	if(x>n||y>m)return;
	if(x+y==(n+m)/2+1)
	{
		++syhmp[x][y][xsum];
		return;
	}
	dfs1(x+1,y,mp[x+1][y]^xsum);
	dfs1(x,y+1,mp[x][y+1]^xsum);
}
void dfs2(ll x,ll y,ll xsum)
{
	if(x<1||y<1)return;
	if(x+y==(n+m)/2+1)
	{
		ans+=syhmp[x][y][xsum^k^mp[x][y]];
		return;
	}
	dfs2(x-1,y,mp[x-1][y]^xsum);
	dfs2(x,y-1,mp[x][y-1]^xsum);
}
int main()
{
	n=read(),m=n,k=0;
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=m;++j)
			mp[i][j]=read();
	dfs1(1,1,mp[1][1]);
	dfs2(n,m,mp[n][m]);
	write(ans);
	return 0;
}
