#include<bits/stdc++.h>
#define M 11451
using namespace std;
int match[M],n,m,ans;
bool vis[M];
vector<int> mp[M];
bool found(int x)
{
	for(auto i:mp[x])
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
	scanf("%d%d",&n,&m);
	int x,y;
	while(scanf("%d%d",&x,&y)&&x!=-1&&y!=-1)
	{
		mp[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(found(i))ans++;
	}
	printf("%d\n",ans);
	for(int i=1;i<=m;i++) 
		if(match[i])
			printf("%d %d\n",i,match[i]);
	return 0;
}
