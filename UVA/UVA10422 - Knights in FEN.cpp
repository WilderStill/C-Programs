#include<bits/stdc++.h>
using namespace std;
int mp[6][6],tg[6][6]={{},{0,1,1,1,1,1},{0,0,1,1,1,1},{0,0,0,-1,1,1},{0,0,0,0,0,1},{0,0,0,0,0,0}};
const int dx[8]={-2,-2,-1,1,-1,1,2,2},dy[8]={-1,1,2,2,-2,-2,-1,1};
int maxd;
bool fg=0;
int calc()
{
	int res=0;
	for(int i=1;i<=5;++i)
		for(int j=1;j<=5;++j)
			res+=mp[i][j]!=tg[i][j];
	return res;
}
void dfs(int step,int x,int y)
{
	if(step>maxd)return;
	if(!calc())
	{
		fg=1;
		return;
	}
	for(int i=0;i<8;i++)
	{
		int xx=x+dx[i],yy=y+dy[i];
		if(xx>0&&yy>0&&xx<=5&&yy<=5)
		{
			swap(mp[x][y],mp[xx][yy]);
			if(step+calc()<=maxd)dfs(step+1,xx,yy);
			swap(mp[x][y],mp[xx][yy]);
		}
	}
}
int main()
{
	int T;
    cin>>T,getchar();
    while(T--)
    {
        int x,y;
        string s;
        for(int i=1;i<=5;++i)
        {
        	getline(cin,s);
			for(int j=1;j<=5;++j)
			{
				if(s[j-1]==' ')
				{
					mp[i][j]=-1;
	                x=i,y=j;
				}
				else mp[i][j]=s[j-1]-'0';
			}
		}
		fg=0;
        for(int i=0;i<11;++i)
		{
			maxd=i;
			dfs(0,x,y);
			if(fg)
			{
				printf("Solvable in %d move(s).\n",i);
				break;
			}
		}
		if(!fg)puts("Unsolvable in less than 11 move(s).");
    }
    return 0;
}
