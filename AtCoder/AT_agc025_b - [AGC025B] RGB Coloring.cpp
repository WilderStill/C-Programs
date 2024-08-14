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
ll mod;
ll qpow(ll x,ll y)
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
inline ll getinv(ll k)
{
	return qpow(k%mod,mod-2)%mod;
}
ll n,a,b,k,ansm,frac[3000001];
ll C(ll a,ll b)
{
	if(a<0||a>n||b-a<0)return 0;
	return ((frac[b]*getinv(frac[b-a]))%mod*getinv(frac[a]))%mod;
}
void init(ll n)
{
	frac[0]=1;
	for(ll i=1;i<=n;++i)frac[i]=frac[i-1]*i%mod;
}
int main()
{
//	freopen("A.in","r",stdin);
//	freopen("A.out","w",stdout);
	n=read(),a=read(),b=read(),k=read(),mod=998244353;
	init(n);
	for(ll i=0;i<=n;++i)
	{
		ll ans=k-i*a;
		if(ans<0)break;
		if(ans%b)continue;
		ll gb=ans/b;
		ansm=(ansm%mod+C(i,n)%mod*C(gb,n)%mod+mod)%mod;
	}
	write(ansm%mod);
	return 0;
}
