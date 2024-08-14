#include<bits/stdc++.h>
#define ll long long
#define M 1145141
using namespace std;
ll n,num[M],sum[M],ave,ans;
int main()
{
	while(scanf("%lld",&n)!=EOF)
	{
		ans=ave=0;
		memset(sum,0,sizeof sum);	
		for(int i=1;i<=n;i++)scanf("%lld",&num[i]),ave+=num[i];
		ave/=n;
	    for(int i=2;i<=n;i++)sum[i]=num[i]+sum[i-1]-ave;
	    sort(sum+1,sum+n+1);
	    for(int i=1;i<=n;i++)ans+=abs(sum[n/2+1]-sum[i]);
	    printf("%lld\n",ans);
	}
    return 0;
}
