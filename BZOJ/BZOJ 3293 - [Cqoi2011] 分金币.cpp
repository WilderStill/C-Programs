#include<bits/stdc++.h>
#define ll long long
#define M 114514
using namespace std;
ll n,num[M],sum[M],ave,ans;
int main()
{
    scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld",&num[i]),ave+=num[i];
    ave/=n;
    for(ll i=1;i<=n;i++)sum[i]=num[i]+sum[i-1]-ave;
    sort(sum+1,sum+n+1);
    for(ll i=1;i<=n;i++)ans+=abs(sum[(n+1)/2]-sum[i]);
    printf("%lld",ans);
    return 0;
}
