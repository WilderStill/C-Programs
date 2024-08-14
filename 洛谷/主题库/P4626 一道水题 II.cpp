#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=100000007;
int Primetot,n,Prime[5800001],Ind[5800001];
ll ans=1;
bitset<100000000>isPrime;
int main()
{
	scanf("%d",&n);
	isPrime[1]=Prime[1]=1;
	for(register int i=2;i<=n;++i)
	{
		if(!isPrime[i])
		{
			Prime[++Primetot]=i;
			ans=ans*i;
			Ind[Primetot]=i;
			if(ans>mod)ans=ans%mod;
		}
		for(register int j=1;j<=Primetot&&i*Prime[j]<=n;++j)
		{
			isPrime[Prime[j]*i]=1;
			if(!(i%Prime[j]))
			{
				if(i==Ind[j])
				{
					Ind[j]=Ind[j]*Prime[j],ans=ans*Prime[j];
					if(ans>mod)ans=ans%mod;
				}
				break;
			}
		}
	}
	printf("%lld",ans);
	return 0;
}
