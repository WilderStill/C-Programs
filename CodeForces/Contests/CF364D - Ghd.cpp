#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,tot;
ll ans,a[1000100],pm[1000100],dg[1000100];
int main()
{
	//freopen("choice.in","r",stdin);
	//freopen("choice.out","w",stdout);
	mt19937 rnd(time(NULL));
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%lld",&a[i]);
	for(int t=1;t<=10;++t)
	{
		memset(dg,0,sizeof dg);
		ll x=a[rnd()%n+1];
		tot=0;
	    for(ll i=1;i*i<=x;++i)
		{
			if(x%i==0)
			{
				pm[++tot]=i;
				if(x/i!=i)pm[++tot]=x/i;
			}
		}
	    sort(pm+1,pm+tot+1);
		for(int i=1;i<=n;++i)
		{
			int p=lower_bound(pm+1,pm+tot+1,__gcd(x,a[i]))-pm;
			++dg[p];
		}
		for(int i=1;i<=tot;++i)
			for(int j=i+1;j<=tot;++j)
				if(pm[j]%pm[i]==0)
					dg[i]+=dg[j];
		for(int i=tot;i>=1;--i)
			if(2*dg[i]>=n)
			{
				ans=max(ans,pm[i]);
				break;
			}
	}
	printf("%lld",ans);
	return 0;
}
