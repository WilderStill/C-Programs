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
const ll mod=1000000007;
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
ll n,ansm,frac[3000001],inv[3000001],power[3000001];
ll C(ll a,ll b)
{
	return ((frac[b]*inv[b-a])%mod*inv[a])%mod;
}
void init(ll n)
{
	frac[0]=power[0]=1;
	for(ll i=1;i<=n;++i)frac[i]=frac[i-1]*i%mod,power[i]=power[i-1]*2%mod;
	inv[n]=qpow(frac[n],mod-2);
	for(ll i=n;i>=1;--i)inv[i-1]=inv[i]*i%mod;
}
int main()
{
	ll T=read();
	init(1145141);
	while(T--)
	{
		ll x=read(),y=read();
		ll ans=power[y-1];
		for(ll i=2;i*i<=x;++i)
		{
			if(!(x%i))
			{
				ll dg=0;
				while(!(x%i))x/=i,++dg;
				cout<<dg<<" "<<C(dg,dg+y-1)<<endl;
				ans=ans*C(dg,dg+y-1)%mod;
			}
		}
		if(x>1)ans=ans*C(1,y)%mod;
		write(ans);
		puts("");
	}
	return 0;
}

