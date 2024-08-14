#include<bits/stdc++.h>
#define ll long long
#define M 114514
using namespace std;
ll n,num[M],sum[M],dwc[M],ave,ans;
int main()
{
    scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&num[i]),ave+=num[i];
	ave/=n;
    for(ll i=1;i<=n;i++)dwc[i]=sum[i]=num[i]+sum[i-1]-ave;
    sort(sum+1,sum+n+1);
    for(ll i=1;i<=n;i++)
	{
		ans+=abs(sum[(n+1)/2]-sum[i]);
	}
    printf("%lld\n",ans);
    for(int i=1;i<n;i++)printf("%lld %lld\n",sum[(n+1)/2]-dwc[i-1],dwc[i]-sum[(n+1)/2]);
    printf("%lld %lld",sum[(n+1)/2]-dwc[n-1],-sum[(n+1)/2]);
    return 0;
}
