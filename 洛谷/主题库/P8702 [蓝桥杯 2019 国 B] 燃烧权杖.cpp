#include<bits/stdc++.h>
#define ll long long
using namespace std;
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
ll qpow(ll x,ll y,ll mod)
{
	ll res=1;
	while(y)
	{
		if(y&1)(res*=x)%=mod;
		(x*=x)%=mod;
		y>>=1;
	}
	return res;
}
ll get_inv(ll n,ll mod)
{
    return qpow(n,mod-2,mod);
}
ll C(ll a,ll b,ll mod)
{
	if(b>a)return 0;
    ll res=1;
    for(ll i=1;i<=b;++i,--a)res=res*a%mod*get_inv(i,mod)%mod;
	return res;
}
ll Lucas(ll a,ll b,ll mod)
{
	if(!b)return 1;
	return Lucas(a/mod,b/mod,mod)*C(a%mod,b%mod,mod)%mod;
}
ll live[11];
int main()
{
	ll T=read();
	while(T--)
	{
		ll x=read(),y=read(),p=read(),k=read();
		if(x>=1000)
		{
			puts("0");
			return 0;
		}
		ll n=x/10+(x%10?1:0),m=y/10+(y%10?1:0);
        for(ll i=1;i<=k;++i)live[i]=read();
        ll div2=get_inv(2,p),ans=0;
        for(ll i=m;i<m+n;++i)
			(ans+=Lucas(i-1,m-1,p)*qpow(div2,i,p))%=p;
		write(ans);
		putchar('\n');
    }
    return 0;
}

