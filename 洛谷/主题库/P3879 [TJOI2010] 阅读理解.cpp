#include<bits/stdc++.h>
#define M 114514
using namespace std;
int n,m,vis[M];
string s;
map<string,vector<int>>mp;
int main()
{	
	scanf("%d",&n);
	for(int i=1,l;i<=n;++i)
	{
		scanf("%d",&l);
		for(int j=1;j<=l;++j)
			cin>>s,mp[s].emplace_back(i);
	}
	scanf("%d",&m);
	for(int i=1;i<=m;++i)
	{
		cin>>s;
		memset(vis,0,sizeof(vis));
		for(auto j:mp[s])
			if(!vis[j])
			{
				printf("%d ",j);vis[j]=1;
			}
		puts("");
	}
	return 0;
}
