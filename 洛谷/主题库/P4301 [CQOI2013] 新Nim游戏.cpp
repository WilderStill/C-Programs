#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,num[114514],d[114514],ans,sum;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&num[i]),sum+=num[i];
	sort(num+1,num+n+1);
	for(int i=n;i>=1;--i)
	{
		ll t=num[i];
		for(int j=30;j>=0;--j)
			if(num[i]&(1<<j))
			{
				if(d[j])num[i]^=num[d[j]];
				else
				{
					d[j]=i;
					break;
				}
			}
		if(num[i])ans+=t;
	}
	printf("%lld",sum-ans);
	return 0;
}
