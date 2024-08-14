#include<bits/stdc++.h>
#define ll long long
#define M 16
using namespace std;
ll n,m,cnt,ans,dp[M][1145][415],can[1145],num[1145];
int main()
{
	scanf("%lld%lld",&n,&m);
	for(ll i=0;i<(1<<n);i++)
		if(!(i&(i<<1)))
            can[++cnt]=i,num[cnt]=__builtin_popcount(i),dp[1][cnt][num[cnt]]=1;		
	for(ll i=2;i<=n;i++)
		for(ll j=1;j<=cnt;j++)
			for(ll k=1;k<=cnt;k++)
            {
				if((can[j]&can[k])||(can[j]&(can[k]<<1))||(can[j]&(can[k]>>1)))continue;
				for(ll l=0;l<=m;l++)
					dp[i][j][num[j]+l]+=dp[i-1][k][l];
            }
	for(ll i=1;i<=cnt;i++)ans+=dp[n][i][m];
	printf("%lld",ans);
}
