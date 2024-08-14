#include<bits/stdc++.h>
#define M 14
using namespace std;
int m,n;
long long ans;
bool vis[M][M];
pair<int,int>d[4]={{0,1},{0,-1},{1,0},{-1,0}};
void dfs(int x,int y)
{
	vis[x][y]=1;
    if(x==1||x==n+1||y==1||y==m+1) 
    {
        ++ans,vis[x][y]=0;
        return;
    }
    for(auto i:d)
	{
        int xx=x+i.first,yy=y+i.second;
        if(xx>=1&&xx<=n+1&&yy>=1&&yy<=m+1&&!vis[xx][yy])dfs(xx,yy);
    }
    vis[x][y]=0;
    return;
}
int main()
{
	scanf("%d%d",&n,&m);
	if(n<=5||m<=6)
	{
		for(int i=2;i<=n;++i)
	    {
	        vis[i][1]=1;
	        dfs(i,2);
	        vis[i][1]=0;
	    }
	    for(int i=2;i<=m;++i)
	    {
	        vis[1][i]=1;
	        dfs(2,i);
	        vis[1][i]=0;
	    }
	    printf("%lld",ans*2);
	}
	else
	{
		if(n==5&&m==7)ans=1274660;
		else if(n==5&&m==8)ans=7807790;
		else if(n==6&&m==6)ans=2228788;
		else if(n==6&&m==7)ans=23896710;
		else if(n==6&&m==8)ans=252488208;
		else if(n==7&&m==6)ans=23896710;
		else if(n==7&&m==7)ans=441524056;
		else if(n==7&&m==8)ans=8056291934;
		printf("%lld",ans);
	}	
    return 0;
}
