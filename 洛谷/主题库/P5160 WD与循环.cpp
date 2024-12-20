#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod=19491001;
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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
inline ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return res;
}
ll frac[mod+10],inv[mod+10];
inline void init()
{
    frac[0]=inv[0]=1;
    for(ll i=1;i<mod;++i)frac[i]=frac[i-1]*i%mod;
    inv[mod-1]=qpow(frac[mod-1],mod-2);
    for(ll i=mod-1;i>1;--i)inv[i-1]=inv[i]*i%mod;
}
inline ll Lucas_C(ll n,ll m)
{
	if(n<0||m<0||n<m)return 0;
	return frac[n]*inv[n-m]%mod*inv[m]%mod;
}
inline ll Lucas(ll n,ll m)
{
	if(n<mod&&m<mod)return Lucas_C(n,m);
	if(!m)return 1;
	return Lucas(n/mod,m/mod)*Lucas_C(n%mod,m%mod)%mod;
}
int main()
{
	ll T=read();
	init();
	while(T--)
	{
		ll n=read(),m=read();
		write(Lucas(n+m,n));
		puts("");
	}
	return 0;
}

