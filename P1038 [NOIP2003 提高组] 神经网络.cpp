#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int> >edge[4151];
vector<int> vis[4154]; 
int n,p,c[114514],u[114514],w;
int main()
{
	scanf("%d%d",&n,&p);
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&u[i]);
	}
	for(int i=1,x,y;i<=p;i++)
	{
		scanf("%d%d%d",&x,&y,&w);
		edge[y].push_back({x,w});
		vis[x].push_back(y);
	}
	for(int i=1;i<=n;i++)
	{
		if(edge[i].size())
		{
			for(int j=0;j<edge[i].size();j++)
			{
				c[i]+=c[edge[i][j].first]*edge[i][j].second;
			}
			c[i]-=u[i];
			if(c[i]<=0)c[i]=0;
		}
	}
	bool fg=0;
	for(int i=1;i<=n;i++)
	{
		if(vis[i].empty())
		{
			if(c[i]>0)printf("%d %d\n",i,c[i]),fg=1;
		}
	}
	if(fg==0)printf("NULL");
	return 0;
}
