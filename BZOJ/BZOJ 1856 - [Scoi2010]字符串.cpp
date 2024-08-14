#include<bits/stdc++.h>
#define Mx 11451411
#define M 2000000
#define ll long long
#define mod 20100403
using namespace std;
ll inv[Mx],frac[Mx],n,m;
ll qpow(ll x,ll y)
{
	ll ans=1;
	while(y)
	{
		if(y&1)ans=ans*x%mod;
		x=x*x%mod;
		y>>=1;
	}
	return ans;
}
void init()
{
	frac[1]=1;
	for(ll i=2;i<=M;++i)frac[i]=frac[i-1]*i%mod;
	inv[M]=qpow(frac[M],mod-2);
	for(ll i=M;i>=1;--i)inv[i-1]=inv[i]*i%mod;
}
ll C(ll a,ll b){return frac[b]*inv[b-a]%mod*inv[a]%mod;}
int main()
{
	init();
	scanf("%lld%lld",&n,&m);
	printf("%lld",((C(m,n+m)-C(m-1,n+m))%mod+mod)%mod);
	return 0;
}
