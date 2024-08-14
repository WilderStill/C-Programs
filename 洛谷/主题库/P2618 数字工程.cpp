#include<bits/stdc++.h>
#define maxn 114514
using namespace std;
int sth,f[maxn][23],num[maxn],dp[maxn];
bool vis[maxn];
int main()
{
	for(int i=2;i<=maxn;i++)
		if(!vis[i])
			for(int j=i;j<=maxn;j+=i)
				vis[j]=1,f[j][++num[j]]=i;
	for(int i=2;i<=maxn;i++)
	{
		dp[i]=dp[i-1]+1;
		for(int j=1;j<=num[i];j++)
			dp[i]=min(dp[i],dp[i/f[i][j]]+1);
	}
	while(~scanf("%d",&sth)) printf("%d\n",dp[sth]);
	return 0;
}
