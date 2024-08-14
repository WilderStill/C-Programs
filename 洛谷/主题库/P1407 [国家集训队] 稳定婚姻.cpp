#include<bits/stdc++.h>
#define M 14145
using namespace std;
map<string,int>num;
int vis[M],match[M],n,m,cnt,ans,cman,cwoman;
vector<int> mp[M];
bool found(int x)
{
	for(auto i:mp[x])
	{
		if(vis[i]||(x==cman&&i==cwoman))continue;
		vis[i]=1;
		if(!match[i]||found(match[i]))return 1;
	}
	return 0;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		string u,v;
		cin>>u>>v;
		num[u]=++cnt,num[v]=cnt+n;
		mp[cnt].push_back(cnt+n);
		match[cnt+n]=cnt,match[cnt]=cnt+n;
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		string u,v;
		cin>>u>>v;
		mp[num[u]].push_back(num[v]);
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		cman=i,cwoman=match[i];
		match[cwoman]=0;
		if(found(i))puts("Unsafe");
		else puts("Safe");
		match[cwoman]=i;
	}
	return 0;
}
