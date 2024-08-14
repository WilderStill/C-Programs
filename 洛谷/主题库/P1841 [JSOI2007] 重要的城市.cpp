#include<bits/stdc++.h>
#define M 1145
using namespace std; 
bool b[M];
int ans[M][M],dis[M][M];
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	memset(dis,0x3f,sizeof(dis));
	for(int i=1;i<=m;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
		dis[x][y]=dis[y][x]=min(dis[y][x],z);
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) continue; 
				if(dis[i][j]>dis[i][k]+dis[k][j])
				{
					ans[i][j]=k;
					dis[i][j]=dis[i][k]+dis[k][j];
				}
				else if(dis[i][j]==dis[i][k]+dis[k][j]) ans[i][j]=-1;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j||dis[i][j]==0x3f3f3f3f) continue;
			if(ans[i][j]!=-1) b[ans[i][j]]=1;
		}
	}
	bool flag=0;
	for(int i=1;i<=n;i++)
	{
		if(b[i])
		{
			printf("%d ",i);
			flag=1;
		}
	}
	if(!flag)
		printf("No important cities.");
	return 0;
}
