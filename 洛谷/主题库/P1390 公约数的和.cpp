#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll Primetot,Prime[11451411],sum[11451411],phi[11451411];
bool isPrime[11451411];
void Eulerphi(ll n)
{
	for(ll i=2;i<=n;i++)
	{
		if(!isPrime[i])Prime[++Primetot]=i,phi[i]=i-1;
		for(ll j=1;j<=Primetot&&i*Prime[j]<=n;j++)
		{
			isPrime[Prime[j]*i]=1;
			if(i%Prime[j]==0){phi[i*Prime[j]]=phi[i]*Prime[j];break;}
			phi[i*Prime[j]]=phi[i]*(Prime[j]-1);
		}
	}
	for(ll i=1;i<=n;i++)sum[i]=sum[i-1]+phi[i];
}
int main()
{
	ll n,ans=0;
	scanf("%lld",&n);
	isPrime[1]=1;Prime[1]=1;
	Eulerphi(n);
	for(ll i=1;i<=n;i++)
	{
		if(n/i==1)break;
		ans+=sum[n/i]*i;
	}
	printf("%lld",ans);
	return 0;
}
