#include<bits/stdc++.h>
#define ll long long
#define M 114514
using namespace std;
ll n,num[M][2],sum[M],ans;
int main()
{
    scanf("%lld",&n);
	for(ll i=1;i<=n;i++)scanf("%lld%lld",&num[i][0],&num[i][1]),sum[i]=num[i][1]-num[i][0]+sum[i-1];
    sort(sum+1,sum+n+1);
    for(ll i=1;i<=n;i++)ans+=abs(sum[(n+1)/2]-sum[i]);
    printf("%lld",ans);
    return 0;
}
