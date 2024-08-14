#include<bits/stdc++.h>
#define INF 0x3f3f3f3f
#define ll long long
#define M 514514
using namespace std;
ll n,d,k,f[M],x[M],s[M];
bool check(ll num)
{
    memset(f,-INF,sizeof(f)); 
    ll maxn=max(d-num,1ll),minn=d+num;
    f[0]=0;
    for(ll i=1;i<=n;++i)
    	for(ll j=i-1;j>=0;--j)
		{
			ll del=x[i]-x[j];
    		if(del<maxn)continue;
    		if(del>minn)break;
    		f[i]=max(f[i],f[j]+s[i]);
    		if(f[i]>=k)return 1;
        }
    return 0;
}
int main()
{
	scanf("%lld%lld%lld",&n,&d,&k);
	for(ll i=1;i<=n;++i)scanf("%lld%lld",&x[i],&s[i]);
	ll l=0,r=M;
	while(l<r)
	{
		ll mid=(l+r)>>1;
		if(check(mid))r=mid;
		else l=mid+1;
	}
	if(l==M)printf("-1");
	else printf("%lld",l);
	return 0;
}
