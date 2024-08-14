#include<bits/stdc++.h>
using namespace std;
const long long mod=998244353;
long long T,n,m;
long long f(long long a,long long b)
{
	long long ans=1;
	a%=mod;
	while (b!=0)
	{
		if(b%2==1)ans=(ans*a)%mod;
		a=(a*a)%mod;
		b/=2;
	}
	return ans;
} 

int main()
{
	scanf("%lld",&T);
	while(T--)
	{
		scanf("%lld %lld",&n,&m);
		printf("%lld\n",f(2,(n-1)*(m-1)));
	}
	return 0;
}
