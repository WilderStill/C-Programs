#include<bits/stdc++.h>
#define ll long long
#define M 114
using namespace std;
ll n,t,m,f[M][M];
int main()
{
	scanf("%lld%lld%lld",&n,&t,&m);
	for(ll i=1,tmp;i<=n;++i)
	{
		scanf("%lld",&tmp);
		for(ll j=m;j>=1;--j)
			for(ll k=t;k>=tmp;--k)
				f[j][k]=max(f[j][k],max(f[j-1][t]+1,f[j][k-tmp]+1));
	}
	printf("%lld",f[m][t]);
	return 0;
}
