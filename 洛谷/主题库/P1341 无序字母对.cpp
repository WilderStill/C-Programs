#include<bits/stdc++.h>
#define M 1145
using namespace std;
int g[M][M],dep[M],n,cnt,h,fa[M];
char a[M],as[M*M]; 
void dfs(int x)
{
	for(int i=0;i<M;i++)
		if(g[x][i])
		{
			g[x][i]=0;
			g[i][x]=0;
			dfs(i);
		}
	as[n--]=x;
}
int find(int x)
{
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
int main()
{
	scanf("%d",&n);
	for(int i=0;i<M;i++)fa[i]=i;
	for(int i=1,fx,fy;i<=n;i++)
	{
		scanf("%s",a);
		g[a[0]][a[1]]=1;
		g[a[1]][a[0]]=1;
		fx=find(a[0]);
		fy=find(a[1]);
		fa[fx]=fy;
        dep[a[0]]++;
        dep[a[1]]++;
	}
	int ans=0;
	for(int i=0;i<M;i++)
		if(fa[i]==i&&dep[i])
			ans++;
	if(ans!=1)
	{
		printf("No Solution");
		return 0;
	}
	for(int i=0;i<M;i++)
		if(dep[i]&1)
		{
		    cnt++;
			if(!h)h=i;
		}
	if(!h)
	    for(int i=0;i<M;i++)
		    if(dep[i])
			{
				h=i;
				break;
			}
	if(cnt&&cnt!=2)
	{
		printf("No Solution");
		return 0;
	}
	dfs(h);
	printf("%s",as);
	return 0;
}
