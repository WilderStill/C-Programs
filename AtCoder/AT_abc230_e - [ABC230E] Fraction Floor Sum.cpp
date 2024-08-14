#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n;
ll f(ll n)
{
	ll m=sqrt(n),ans=0;
	for(ll i=1;i<=m;i++)ans+=n/i;
	return ans*2-m*m;
}
int main()
{
	scanf("%lld",&n);
	printf("%lld",f(n));
	return 0;
}
