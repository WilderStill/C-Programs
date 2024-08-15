#include<bits/stdc++.h>
#define M 11451
using namespace std;
int n,m,sq[M],ans,hctam[M],match[M];
bool vis[M];
vector<int>mp[M];
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int found(int x)
{
	if(vis[x])return 0;
	vis[x]=1;
	for(int i=0;i<mp[x].size();i++)
	{
		if(!match[mp[x][i]]||found(match[mp[x][i]]))
		{
			hctam[x]=mp[x][i],match[mp[x][i]]=x;
			return 1;
		}
	}
	return 0;
}
int main()
{
	n=read();
	for(int i=1;i<=n;i++)sq[i]=read();
	for(int i=1;i<=n;i++)
	{
		if(i+sq[i]<=n)mp[i].push_back(i+sq[i]);
		if(i-sq[i]>=1)mp[i].push_back(i-sq[i]);
		if(i+n-sq[i]<=n)mp[i].push_back(i+n-sq[i]);
		if(i-n+sq[i]>=1)mp[i].push_back(i-n+sq[i]);
		if(mp[i].size())sort(mp[i].begin(),mp[i].end());
	}
	for(int i=n;i;i--)
	{
		memset(vis,0,sizeof(vis));
		ans+=found(i);
	}
	if(ans<n)puts("No Answer");
	else for(int i=1;i<=n;i++)printf("%d ",hctam[i]-1);
	return 0;
}
