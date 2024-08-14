#include<bits/stdc++.h>
#define M 2145
using namespace std;
int mp[M][M],vis[M],match[M],n,m,ans;
bool sex[M];
bool found(int x,int t)
{
	if(vis[x]==t)return 0;
	vis[x]=t;
	for(int i=1;i<=n;i++)
		if(mp[x][i])
		{
			if(!match[i]||found(match[i],t))
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
	for(int i=1,u,v;i<=m;i++)
	{
		scanf("%d%d",&u,&v);
		mp[v+1][u+1]=1;
	}
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(found(i,i))ans++;
	}
	printf("%d",n-ans);	
	return 0;
}
