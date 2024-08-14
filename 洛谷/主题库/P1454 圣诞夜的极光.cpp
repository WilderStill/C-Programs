#include <bits/stdc++.h>
using namespace std;
int ans,n,k,b,a=0,dx[12]={1,0,-1,0,1,1,-1,-1,2,-2,0,0},dy[12]={0,1,0,-1,1,-1,1,-1,0,0,2,-2},s[102][102];
char t[102][102];
int dfs(int x,int y)
{
    for(int i=0;i<12;i++)
    {
        int xx=x+dx[i];
        int yy=y+dy[i];
        if(t[xx][yy]=='#'&&s[xx][yy]==0&&xx>=1&&xx<=n&&yy>=1&&yy<=k)
        {
        	s[xx][yy]=1;
        	dfs(xx,yy);
		}
    }
}
int main()
{
    scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			cin>>t[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=k;j++)
			if(t[i][j]=='#'&&s[i][j]==0)
			{
				a++;
				dfs(i,j);
			}
    cout<<a;
    return 0;
}
