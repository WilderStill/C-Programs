#include<bits/stdc++.h>
#define INF 1e18
#define ll long long
using namespace std;
ll ans,n,a[11451411],f[11151411];
int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++)f[i]=-INF;
	for(ll i=1;i<=n;i++)scanf("%lld",&a[i]);
	for(ll i=1;i<=n;i++)
		for(ll j=i;j>0;j--)
			f[j]=max(f[j],f[j-1]+j*a[i]);
	for(ll i=1;i<=n;i++)
		ans=max(ans,f[i]);
	printf("%lld",ans);
	return 0;
}
