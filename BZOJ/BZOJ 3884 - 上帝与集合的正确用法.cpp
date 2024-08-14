#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll q;
ll Eulerphi(ll m)
{
	ll tmp=m,ans=1;
	for(ll i=2;i*i<=tmp;i++)
	{
		if(tmp%i)continue;
		ans*=i-1;
		tmp/=i;
		while(!(tmp%i))ans*=i,tmp/=i;
	}
	if(tmp>1)ans*=(tmp-1);
	return ans;
}
ll qpow(ll x,ll y,ll m)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%m;
		y>>=1;
		x=x*x%m;
	}
	return res;
}
ll f(ll x)
{
	if(x==1)return 0;
	ll phi=Eulerphi(x);
	return qpow(2ll,f(phi)+phi,x);
}
int main()
{
	scanf("%lld",&q);
	for(ll i=1,tm;i<=q;i++)
	{
		scanf("%lld",&tm);
		printf("%lld\n",f(tm));
	}
	return 0;
}
