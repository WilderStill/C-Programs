#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,p,q,r,sum,ans,a[114514];
int main()
{
	scanf("%lld%lld%lld%lld",&n,&p,&q,&r);
	for(ll i=1;i<=n;++i)scanf("%lld",&a[i]),sum+=a[i];
	sort(a+1,a+n+1);
	if(sum<0)
	{
	    for(ll i=1;i<n;++i)
		{
	        if(a[i]>=0)break;
	        ans+=min(-p*max(a[i],sum),q);
	        sum-=a[i];
	        if(sum>=0)break;
	    }
	    if(sum<0)ans+=p*abs(sum);  
	}
	printf("%lld",ans);
	return 0;
}
