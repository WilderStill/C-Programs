#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,op,ans=1,mod;
int main()
{
	scanf("%lld%lld%lld%lld",&op,&n,&m,&mod);
	for(ll i=n-m+1;i>=n-2*m+2;--i)(ans*=i)%=mod;
	printf("%lld",ans);
	return 0;
}
