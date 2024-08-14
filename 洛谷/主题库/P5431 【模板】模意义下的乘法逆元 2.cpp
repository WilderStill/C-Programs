#include<bits/stdc++.h>
#define ll long long
#define M 11451411
using namespace std;
inline ll read()
{
	register char ch=getchar();
	register ll x=0,f=1;
	while(!isdigit(ch)){ch=getchar();if(ch=='-')f=-1;}
	while(isdigit(ch)){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	return x*f;
}
ll n,mod,k,ans,sum,inv[M],frac[M],num[M];
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
int main()
{
	n=read(),mod=read(),k=read();
	for(register ll i=1;i<=n;++i)num[i]=read();
	frac[0]=1;
	for(ll i=1;i<=n;i++)frac[i]=num[i]*frac[i-1]%mod;
	inv[n+1]=qpow(frac[n],mod-2);
	for(ll i=n;i>=1;i--)inv[i]=inv[i+1]*num[i]%mod;
	sum=k;
	for(register ll i=1;i<=n;++i)
	{
		ans=(ans+sum*frac[i-1]%mod*inv[i+1])%mod;
		sum=sum*k%mod;
	}
	printf("%lld",ans);
	return 0;
}
