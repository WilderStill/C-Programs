#include<bits/stdc++.h>
#define M 851411
#define Maxn 800000
#define Minn 400000 
using namespace std;
int n,s[M],f[M],dp[M],ans;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",&s[i],&f[i]);
    memset(dp,-0x3f,sizeof dp);
	dp[Minn]=0;
	for(int i=1;i<=n;i++)
	{
		if(s[i]>=0)
			for(int j=Maxn;j>=s[i];j--)
				dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
		else
			for(int j=0;j<=Maxn+s[i];j++)
				dp[j]=max(dp[j],dp[j-s[i]]+f[i]);
	}
	for(int i=Minn;i<=Maxn;i++)
		if(dp[i]>0)
			ans=max(ans,i+dp[i]-Minn);
	printf("%d",ans);
}
