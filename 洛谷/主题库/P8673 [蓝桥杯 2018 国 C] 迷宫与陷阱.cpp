#include<bits/stdc++.h>
using namespace std;
int n,k,vis[4000][4000]; 
char mp[4000][4000]; 
struct node
{
	int x,y,stp,nb;
};
int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int main()
{
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;++i)scanf("%s",mp[i]+1);
	memset(vis,-1,sizeof vis);
	queue<node>q;
	vis[1][1]=0;
	q.push({1,1,0,0});
	while(!q.empty())
	{
		auto top=q.front();
		q.pop();
		if(top.x==n&&top.y==n)
		{
			printf("%d",top.stp);
			return 0;
		}
		for(int i=0;i<4;++i)
		{
			int xx=top.x+dx[i],yy=top.y+dy[i];
			if (mp[xx][yy]=='X'&&!top.nb)continue;
			int tmp=max(0,top.nb-1);
			if(mp[xx][yy]=='%')tmp=k;
			if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&vis[xx][yy]<tmp&&mp[xx][yy]!='#')
			{
				vis[xx][yy]=tmp;
				q.push({xx,yy,top.stp+1,tmp});
			}
		}
	}
	puts("-1");
	return 0;
}
