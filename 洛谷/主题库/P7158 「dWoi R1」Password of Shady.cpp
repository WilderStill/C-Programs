#include<bits/stdc++.h>
#define mod 998244353
#define ll long long
#define M 114514
using namespace std;
ll T,n,k,f[M],g[M];
int main()
{
    scanf("%lld",&T);
    f[1]=8,g[1]=1;
    for(ll i=2;i<=M;++i)
	{
        f[i]=(f[i-1]*9+g[i-1])%mod;
		g[i]=(g[i-1]*9+f[i-1])%mod;
    }
    while(T--)
	{
        scanf("%lld%lld",&n,&k);
        if(n==1){puts("9");continue;}
        printf("%lld\n",f[n]);
    }
    return 0;
}
