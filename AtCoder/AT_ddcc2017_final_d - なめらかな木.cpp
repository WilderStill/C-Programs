#include<bits/stdc++.h>
#define M 200005
#define ll long long
using namespace std;
const int mod=1000000007;
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
ll n,sum[M];
vector<ll>mp[M];
typedef tuple<ll,ll,ll>tll; 
map<tll,ll>f;
inline ll dfs(ll u,ll v,ll p)
{
	tll tp=tie(u,v,p);
	if(f.count(tp))return f[tp];
	if(p+1==(1ll<<n))
	{
		f[tp]=1;
		return 1;
	}
	f[tp]=0;
	for(ll i=0;i<n;++i)
	{
		if((p>>i)&1)continue;
		for(auto s:mp[i])
		{
			if(s==u||s==v)continue;
			if((p>>s)&1)return f[tp];
		}
	}
	for(ll i=0;i<n;++i)
	{
		if((p>>i)&1)continue;
		(f[tp]+=dfs(v,i,p|(1ll<<i)))%=mod;
	}
	return f[tp];
}
int main()
{
	//freopen("honor.in","r",stdin);
	//freopen("honor.out","w",stdout);
	n=read();
	for(ll i=1;i<n;++i)
	{
	    ll u=read()-1,v=read()-1;
	    mp[u].emplace_back(v);
	    mp[v].emplace_back(u);
	}
	for(ll i=0;i<n;++i)
		if(mp[i].size()>4)
		{
			write(0);
			return 0;
		}
	if(n<=200)write(dfs(n,n,0));
	else
	{
		sum[0]=sum[1]=sum[2]=1,sum[3]=2;
        for(ll i=4;i<=n;++i)
			(sum[i]=sum[i-4]+sum[i-3]+sum[i-2])%=mod;
		write(((sum[n]*3+sum[n-1]+sum[n-2]-(n+2))%mod*2%mod+mod)%mod);
	}
    return 0;
}

