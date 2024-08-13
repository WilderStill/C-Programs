#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
#define M 1145
using namespace std;
const ll mod=998244353;
ll qpow(ll x,ll y)
{
	ll res=1;
	while(y)
	{
		if(y&1)res=(res*x)%mod;
		x=(x*x)%mod;
		y>>=1;
	}
	return res;
} 
ll n,k,ans,f[M][M],C[M][M];
int main()
{
	scanf("%lld%lld",&n,&k);
	for(ll i=0;i<=503;++i)
        for(ll j=0;j<=i;++j)
            if(!j)C[i][j]=1;
            else C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	f[n][0]=1;
	for(ll i=n;i>=2;--i)
		for(ll j=0;j<=k;++j)
		{
			if(!f[i][j])continue;
			for(ll l=i;l>=0;--l)
				f[l][min(i+j-1,k)]=(f[l][min(i+j-1,k)]+f[i][j]*C[i][l]%mod*qpow(min(i+j-1,k)-j,i-l)%mod)%mod; 
		}
	for(ll i=0;i<=k;++i)ans=(ans+f[0][i])%mod;
	printf("%lld",ans);
	return 0;
}
