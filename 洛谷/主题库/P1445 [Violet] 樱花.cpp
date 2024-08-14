#include<bits/stdc++.h>
#define ll long long
#define M 114514111
#define mod 1000000007
using namespace std;
bool pm[M];
ll prime[M],res[M],tot;
void Checkprime(ll n)
{
	memset(pm,1,sizeof pm);
	for(ll i=2;i<=n;i++)
	{
		if(pm[i]) prime[++tot]=i;
		for(ll j=1;j<=tot&&i*prime[j]<=n;j++)
		{
			pm[i*prime[j]]=0;
			if(!(i%prime[j]))break;
		}
	}
}
int main()
{
	ll n,ans=1;
	scanf("%lld",&n);
	Checkprime(n);
	for(ll i=1;i<=tot;i++)
	{
		ll tmp=prime[i];
		for(ll j=tmp;j<=n;j*=tmp) res[i]=(res[i]+n/j)%mod;
	}
	for(int i=1;i<=tot;i++)
		ans=(ans*(res[i]*2+1))%mod;
	printf("%lld",ans);
	return 0;
}
