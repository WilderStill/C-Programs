#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define N 100010
using namespace std;
const ll M=1,F=-1;
ll n,m,sum,tot,cnt[N],suf[N],maxsuf[N];
char q[N<<1];
int main()
{
//	freopen("toilet.in","r",stdin);
//	freopen("toilet.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=m;++i)
	{
		scanf("%s%lld",q+1,&cnt[i]);
		for(ll j=strlen(q+1);j;--j)
		{
			if(q[j]=='M')suf[i]+=M;
			else suf[i]+=F;
			maxsuf[i]=max(suf[i],maxsuf[i]);
		}
		sum+=suf[i]*cnt[i];
	}
	if(sum>0)
	{
		puts("-1");
		return 0;
	}
	ll ans=1;
	for(ll i=m;i;--i)
	{
		if(suf[i]>0)ans=max(ans,tot+(cnt[i]-1)*suf[i]+maxsuf[i]);
		else ans=max(ans,tot+maxsuf[i]);
		tot+=suf[i]*cnt[i];
	}
	printf("%lld",ans-1);
	return 0;
}
