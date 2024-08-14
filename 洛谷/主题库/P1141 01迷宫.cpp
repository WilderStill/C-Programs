#include <bits/stdc++.h>
using namespace std;
int n,m,t,sx,sy,tx,ty,ans,ret,s=0,ii,jj,cnt=0,sum[1000005];
char mp[1005][1005];
int v[1005][1005];
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
void dfs(int x,int y)
{
	s++;
	v[x][y]=cnt;
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx>=1&&nx<=n&&ny>=1&&ny<=n&&mp[nx][ny]!=mp[x][y]&&v[nx][ny]==0)
			dfs(nx,ny);
	}
}
int main()
{
	int max=0;
	scanf("%d %d",&n,&m);
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				cin>>mp[i][j];
		for(int i=0;i<m;i++)
		{
			scanf("%d %d",&ii,&jj);
			if(v[ii][jj])
			{
				int k=v[ii][jj];
				printf("%d\n",sum[k]);
			}
			else
			{
				cnt++;
				s=0;
				dfs(ii,jj);
				printf("%d\n",s);
				sum[cnt]=s;
			}
		}
	}
	return 0;
}
