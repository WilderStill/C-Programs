#include<bits/stdc++.h>
#define mod 666623333
#define ll long long
ll val[51451411],phi[51451411];
signed Prime[51451411],Primetot;
bool isPrime[51451411];
void Eulerphi(signed n)
{
	for(signed i=2;i<=n;i++)
	{
		if(!isPrime[i])Prime[++Primetot]=i;
		for(signed j=1;j<=Primetot&&i*Prime[j]<=n;j++)
		{
			isPrime[i*Prime[j]]=1;
			if(!(i%Prime[j])) break;
		}
	}
}
ll phigros(ll l,ll r)
{
	ll ans=0;
	for(ll i=l;i<=r;++i)phi[i-l]=val[i-l]=i;
	for(signed i=1;i<=Primetot;++i) 
		for(ll j=((l-1)/Prime[i]+1)*Prime[i];j<=r;j+=Prime[i])
		{
			if(val[j-l]%Prime[i])continue;
			phi[j-l]=phi[j-l]/Prime[i]*(Prime[i]-1);
			while(!(val[j-l]%Prime[i]))val[j-l]/=Prime[i];
		}
	for(ll i=l;i<=r;++i)if(val[i-l]!=1)phi[i-l]=phi[i-l]/val[i-l]*(val[i-l]-1);
	for(ll i=l;i<=r;++i)ans=(ans+i-phi[i-l])%mod;
	return ans;
}
int main()
{
	ll l,r;
	scanf("%lld%lld",&l,&r);
	Eulerphi((signed)sqrt(r));
	printf("%lld",phigros(l,r));
	return 0;
}
