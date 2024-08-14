#include<bits/stdc++.h>
#define MAXN 114514
using namespace std;
int hp[MAXN],f[MAXN][2],n,rt;
bool vis[MAXN];
vector<int> s[MAXN];
void dfs(int x)
{
	for(int i=0;i<s[x].size();i++)
	{
		int y=s[x][i];
		dfs(y);
		f[x][1]+=f[y][0];
		f[x][0]+=max(f[y][0],f[y][1]);
	}
	f[x][1]+=hp[x];
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++) scanf("%d",&hp[i]);
	for(int i=1;i<n;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		s[y].push_back(x);
		vis[x]=true;
	}
	for(int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			rt=i;
			break;
		}
	}
	dfs(rt);
	printf("%d",max(f[rt][0],f[rt][1]));
	return 0;
}
