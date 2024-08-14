#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,c[1145141],m,p,s,k,sum,ans;
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
		scanf("%lld",&c[i]);
	scanf("%lld%lld%lld%lld",&m,&p,&s,&k);
	for(int i=1;i<=n;i++)
		sum+=c[i]*(m-i);
	sum+=s*(m-p);
	ans=m+round(sum*1.0/k);
	ans=(ans>n?n:(ans<1?1:ans));
	printf("%lld",ans);
	return 0;
}
