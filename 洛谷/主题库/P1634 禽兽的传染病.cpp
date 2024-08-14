#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1) res*=x;
		x*=x;
		y>>=1;
	}
	return res;
}
int main()
{
	ll n,p;
	scanf("%lld%lld",&n,&p);
	printf("%lld",qpow(n+1,p));
	return 0;
}
