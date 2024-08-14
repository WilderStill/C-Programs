#include <bits/stdc++.h>
#define M 1145
#define MAXT 1145141
using namespace std;
int n,m;
priority_queue<int,vector<int>,greater<int> > q; 
int f[M][M];
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=0;i<M;i++)
		for(int j=0;j<M;j++)
			f[i][j]=MAXT;
	for(int i=1,x,y;i<=m;i++)
	{
		scanf("%d%d",&x,&y);
		f[x][y]=1;
		f[y][x]=1;
	}
	for(int k=1;k<=n;k++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int i=1;i<=n;i++)
			{
				if(i==j||i==k||j==k) continue;
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				f[j][i]=min(f[j][i],f[j][k]+f[k][i]);
			}
		}
	}
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		q.push(x);
		q.push(y);
		for(int k=1;k<=n;k++)
		{
			if(k==x||k==y) continue;
			if(f[x][y]==f[x][k]+f[k][y])  
			q.push(k);
		}
		while(!q.empty())
		{
			printf("%d ",q.top());
			q.pop();
		}
		printf("\n");
	}
	return 0;
}  
