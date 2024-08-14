#include<bits/stdc++.h>
#define mod 1000000007
#define ll long long
using namespace std;
ll n,ans=1,tmp;
int main()
{
	scanf("%lld",&n);
	for(ll i=1,x;i<=n;i++)
	{
		scanf("%lld",&x);
        if(x<(tmp<<1|1))ans*=(tmp+1),ans%=mod;else tmp++;
    }
    for(ll i=tmp;i;i--)ans*=i,ans%=mod;
    printf("%lld",ans);
	return 0;
}
