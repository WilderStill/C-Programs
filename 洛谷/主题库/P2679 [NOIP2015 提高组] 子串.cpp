#include<bits/stdc++.h>
#define M 1145
#define mod 1000000007
#define ll long long
using namespace std;
ll n,m,k,f[2][M][M][2];
char a[M],b[M];
int main()
{
	scanf("%lld%lld%lld%s%s",&n,&m,&k,a+1,b+1);
	f[1][0][0][0]=f[0][0][0][0]=1;
	for(ll i=1;i<=n;++i)
		for(ll j=1;j<=k;++j)
			for(ll l=1;l<=m;++l)
			{
				ll v=i&1;
				f[v][j][l][0]=(f[v^1][j][l][0]+f[v^1][j][l][1])%mod;
				f[v][j][l][1]=(a[i]==b[l])?(f[v^1][j-1][l-1][0]+f[v^1][j][l-1][1]+f[v^1][j-1][l-1][1])%mod:0;
			}
	printf("%lld",(f[n&1][k][m][0]+f[n&1][k][m][1])%mod);
	return 0;
}
