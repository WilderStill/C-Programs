#include<bits/stdc++.h>
#define M 11451411
#define ll long long
using namespace std;
ll a,b,c,ans=1;
const ll mod=1000000007;
ll qpow(ll x,ll y,ll m)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=res*x%m;
		y>>=1;
		x=x*x%m;
	}
	return res;
}
int main()
{
	while(1)
	{
		ans=1;
		scanf("%lld%lld%lld",&a,&b,&c);
		if(a==0)
		{
			puts(b==0&&c!=0?"1":"0");
			continue;
		}
		if(a==-1&&b==-1&&c==-1)break;
		printf("%lld\n",qpow(a,qpow(b,c,mod-1)+mod-1,mod));
	}
	return 0;
}
