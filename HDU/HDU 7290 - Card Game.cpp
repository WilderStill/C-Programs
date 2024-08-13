#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll mod=998244353;
ll T,n;
ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
} 
int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld",&n);
		printf("%lld\n",qpow(2,n-1)-1);
	}
	return 0;
}

