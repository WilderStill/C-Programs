#include<bits/stdc++.h>
#define M 1145
using namespace std;
int t,fa[M],e[M][M];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		int m,k;
		bool fg=0;
		scanf("%d%d",&m,&k);
		for(int i=1;i<=2*(m+1);i++)fa[i]=i;
		memset(e,0,sizeof(e));
		for(int i=1,x,y;i<=k;i++)
		{
			scanf("%d%d",&x,&y);
			x++;y++;
			e[x][y]=1;
			fa[find(x+m+1)]=find(y);
		}
		for(int i=1;i<=m;i++)
			for(int j=1;j<=m;j++)
				if(!e[i][j]&&find(i+m+1)==find(j))
					fg=1;
		if(fg) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
