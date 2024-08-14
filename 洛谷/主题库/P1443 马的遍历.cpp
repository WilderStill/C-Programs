#include<bits/stdc++.h>
using namespace std;
pair<int,int> dd[8]={{-1,2},{-2,1},{-2,-1},{-1,-2},{1,2},{2,1},{2,-1},{1,-2}};
queue<pair<int,int> > q;
int mp[500][500],n,m,x,y;
bool vis[500][500];
int main()
{
	memset(mp,0x7fffffff,sizeof(mp));
	memset(vis,0,sizeof(vis));
	cin>>n>>m>>x>>y;
	mp[x][y]=0;
	vis[x][y]=1;
	q.push(make_pair(x,y));
	while(!q.empty())
	{
		int xx=q.front().first,yy=q.front().second;
		q.pop();
		for(int i=0;i<8;i++)
		{
			int tx=xx+dd[i].first,ty=yy+dd[i].second;
			if(tx<1||tx>n||ty<1||ty>m||vis[tx][ty])continue;
		    vis[tx][ty]=1;
			q.push(make_pair(tx,ty));
			mp[tx][ty]=mp[xx][yy]+1;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)printf("%-5d",mp[i][j]);
		printf("\n");
	}
	return 0;
}
