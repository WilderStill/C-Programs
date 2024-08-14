#include<bits/stdc++.h>
#define M 4145
using namespace std;
int vis[M],match[M][3],n,m,e,ans;
vector<int> mp[M];
bool found(int x)
{
	for(auto i:mp[x])
	{
		if(vis[i])continue;
		vis[i]=1;
		if(!match[i][1]||found(match[i][1]))
		{ 
			match[i][1]=x; 
			return 1;
		}
		if(!match[i][2]||found(match[i][2]))
		{ 
			match[i][2]=x; 
			return 1;
		}
	}
	return 0;
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<=n*2;i++)
	{
		scanf("%d%d",&u,&v);
		mp[i].push_back(u);
		mp[i].push_back(v);
	}
	for(int i=1;i<=n*2;i++)
	{
		memset(vis,0,sizeof(vis));
		if(found(i))ans++;
	}
	printf("%d",ans);
	return 0;
}
