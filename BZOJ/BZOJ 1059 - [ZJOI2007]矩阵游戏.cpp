#include<bits/stdc++.h>
#define M 1145
using namespace std;
int mp[M][M],vis[M],match[M],n,m,t,ans;
bool found(int x)
{
	for(int i=1;i<=n;i++)
		if(mp[x][i])
		{
			if(vis[i])continue;
			vis[i]=1;
			if(!match[i]||found(match[i]))
			{ 
				match[i]=x; 
				return 1;
			}
		} 
	return 0;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		memset(match,0,sizeof match);
		ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				scanf("%d",&mp[i][j]);
		for(int i=1;i<=n;i++)
		{
			memset(vis,0,sizeof(vis));
			if(found(i))ans++;
		}
		printf("%s\n",ans==n?"Yes":"No");
	}
	return 0;
}
