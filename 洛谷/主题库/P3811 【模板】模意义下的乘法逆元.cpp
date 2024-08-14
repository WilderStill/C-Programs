#include<bits/stdc++.h>
#define M 11451411
#define ll long long
using namespace std;
ll inv[M],n,m;
int main()
{
	scanf("%lld%lld",&n,&m);
	inv[1]=1;
	for(ll i=2;i<=n;++i)inv[i]=m-(m/i)*inv[m%i]%m;
	for(ll i=1;i<=n;++i)printf("%d\n",inv[i]);
	return 0;
}
