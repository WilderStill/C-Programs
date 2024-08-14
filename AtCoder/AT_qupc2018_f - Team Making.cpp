#include<bits/stdc++.h>
#define ll long long 
#define M 21
using namespace std;
ll n,m,num[M],f[1<<M];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=0;i<n;++i)scanf("%lld",&num[i]);
	f[0]=1;
	for(ll i=1;i<1<<n;++i)
	{
	    ll maxn=-1;
	    for(ll j=0;j<n;++j)if(i&(1<<j))maxn=j;
	    f[i]+=f[i-(1<<maxn)];
	    for(ll j=0;j<maxn;++j)
			if(i&(1<<j))
				if(num[j]+num[maxn]<=2*m)
					f[i]+=f[i-(1<<maxn)-(1<<j)];
	    for(ll j=0;j<maxn;++j)
			for(ll k=0;k<j;++k)
				if(i&(1<<j)&&i&(1<<k))
					if(num[j]+num[k]+num[maxn]<=3*m)
						f[i]+=f[i-(1<<maxn)-(1<<j)-(1<<k)];
	}
	printf("%lld",f[(1<<n)-1]);
	return 0;
}
