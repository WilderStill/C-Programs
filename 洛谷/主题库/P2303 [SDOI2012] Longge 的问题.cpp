#include<bits/stdc++.h>
#define ll long long
ll Primetot,Prime[11451411];
bool isPrime[11451411];
void Eulerphi(ll n)
{
	for(int i=2;i<=n;i++)
	{
		if(!isPrime[i])Prime[++Primetot]=i;
		for(int j=1;j<=Primetot&&i*Prime[j]<=n;j++)
		{
			isPrime[i*Prime[j]]=1;
			if(!(i%Prime[j])) break;
		}
	}
}
ll phi(ll x)
{
	ll ans=x;
	for(int i=1;i<=Primetot&&Prime[i]<=sqrt(x);i++)
	{
		if(x%Prime[i])continue;
		ans=ans/Prime[i]*(Prime[i]-1);
		while(!(x%Prime[i]))x/=Prime[i];
	}
	if(x>1)ans=ans/x*(x-1);
	return ans;
}
int main()
{
	ll n,ans=0;
	scanf("%lld",&n);
	Eulerphi(sqrt(n));
	for(ll i=1;i<=sqrt(n);i++)
	{
		if(!(n%i))
		{
			ans+=i*phi(n/i);
			if(i*i!=n)ans+=n/i*phi(i);
		}
	}
	printf("%lld",ans);
	return 0;
}
