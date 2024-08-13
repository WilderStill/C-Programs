#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll Eulerphi(ll m)
{
	ll tmp=m,ans=1;
	for(ll i=2;i*i<=tmp;++i)
	{
		if(tmp%i)continue;
		ans*=i-1;
		tmp/=i;
		while(!(tmp%i))ans*=i,tmp/=i;
	}
	if(tmp>1)ans*=(tmp-1);
	return ans;
}
int main()
{
	ll a,m,T;
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld%lld",&a,&m);
		printf("%lld\n",Eulerphi(m/__gcd(a,m)));
	}
	return 0;
}
