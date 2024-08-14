#include<bits/stdc++.h>
using namespace std;
int mp[6][6],tg[6][6]={{},{0,1,1,1,1,1},{0,0,1,1,1,1},{0,0,0,-1,1,1},{0,0,0,0,0,1},{0,0,0,0,0,0}};
const int dx[8]={-2,-2,-1,1,-1,1,2,2},dy[8]={-1,1,2, 2,-2,-2,-1,1};
int maxd;
int dfs(int step,int x,int y,int sum,int last)
{
    if(step+sum>maxd)return 0;
    if(!sum)return 1;
    bool fg=0;
    for(int i=0;i<8;++i)
    {
        if(i!=(7-last))
        {
            int xx=x+dx[i],yy=y+dy[i],p=sum;
            if(xx<=5&&xx>0&&yy<=5&&yy>0)
            {
                if(mp[xx][yy]==tg[xx][yy]&&mp[xx][yy]!=tg[x][y])++p;
                if(mp[xx][yy]!=tg[xx][yy]&&mp[xx][yy]==tg[x][y])--p;
                if(tg[xx][yy]==-1)--p;
                if(tg[x][y]==-1)++p;
                swap(mp[xx][yy],mp[x][y]);
                fg=dfs(step+1,xx,yy,p,i);
                if(fg)return 1;
                swap(mp[xx][yy],mp[x][y]);
            }
        }
    }
    return 0;
}
int main()
{
	int T;
    scanf("%d",&T);
    while(T--)
    {
        int need=0,x,y;
		char k;
        for(int i=1;i<=5;++i)
	        for(int j=1;j<=5;++j)
	        {
	            cin>>k;
	            if(k=='*')
	            {
	                mp[i][j]=-1;
	                x=i,y=j;
	            }
	            else mp[i][j]=k-'0';
	            if(mp[i][j]!=tg[i][j])++need;
	        }
        bool fg=0;
        for(int i=need;i<=16;++i)
        {
            maxd=i;
            if(dfs(0,x,y,need,-1))
            {
                printf("%d\n",i-1),fg=1;
				break;
            }
        }
        if(!fg)puts("-1");
    }
    return 0;
}
