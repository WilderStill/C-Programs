#include<bits/stdc++.h>
#define M 11451411
#define ll long long
using namespace std;
ll n,tmp,ans=1,phi[M],num[M];
const ll mod=10007;
ll qpow(ll x,ll y,ll m)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%m+m;
		y>>=1;
		x=x*x%m+m;
	}
	return res;
}
int main()
{
	scanf("%lld",&n);
	phi[1]=mod;
	for(ll i=2;i<=n+114;i++)
	{
		tmp=phi[i-1];
		phi[i]=1;
		for(ll j=2;j*j<=tmp;j++)
		{
			if(tmp%j)continue;
			phi[i]*=j-1;
			tmp/=j;
			while(!(tmp%j))phi[i]*=j,tmp/=j;
		}
		if(tmp>1)phi[i]*=(tmp-1);
	}
	for(ll i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		if(phi[i]<num[i])num[i]=num[i]%phi[i]+phi[i];
	}
    for(ll i=n;i>=1;i--)ans=qpow(num[i],ans,phi[i]);
	printf("%lld",ans%mod);
	return 0;
}
