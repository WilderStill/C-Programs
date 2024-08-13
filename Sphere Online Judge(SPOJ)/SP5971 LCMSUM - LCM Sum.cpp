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
	for(ll i=1;i<=n;i++)for(ll j=i;j<=n;j+=i)sum[j]+=(i*phi[i]+1)>>1;
}
int main()
{
	ll n,t,ans=0;
    scanf("%lld",&t);
	isPrime[1]=1;phi[1]=1;
	Eulerphi(1145141);
	while(t--)
	{
		scanf("%lld",&n);
		printf("%lld\n",sum[n]*n);
	}
	return 0;
}
