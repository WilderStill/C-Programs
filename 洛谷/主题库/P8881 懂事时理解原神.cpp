#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
vector<int>mp[1000100];
bool vis[1000100];
void dfs(int x,int fa)
{
	vis[x]=1;
	for(auto v:mp[x])
	{
		if(v==fa)continue;
		if(!vis[v])dfs(v,x);
		else ans=0;
		if(!ans)return;
	}
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&m);
		ans=1;
		for(int i=0;i<=n;++i){mp[i].clear();vis[i]=0;}
		for(int i=1,u,v;i<=m;++i)
		{
			scanf("%d%d",&u,&v);
			mp[u].push_back(v),mp[v].push_back(u);
		}
		dfs(1,0);
		puts(ans?"1.000":"0.000");
	}
	return 0;
}
