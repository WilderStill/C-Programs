#include<bits/stdc++.h>
using namespace std;
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
	{
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
	{
        x=(x<<1)+(x<<3)+(ch^48);
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
{
    if(x<0)
	{
        putchar('-');
        write(-x);
        return;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
struct node
{
	int x,y;
};
char mp[501][501];
int n,m,vis[501][501];
const int dx[4]={1,-1,-1,1},dy[4]={1,1,-1,-1},ix[4]={0,-1,-1,0},iy[4]={0,0,-1,-1};
const char st[5]="\\/\\/";
void bfs()
{
	memset(vis,0x3f3f3f,sizeof vis);
	deque<node>q;
	q.push_back({0,0});
	vis[0][0]=0;
	while(!q.empty())
	{
		node tmp=q.front();
		q.pop_front();
		int x=tmp.x,y=tmp.y;
		for(int i=0;i<4;++i)
		{
			int xx=x+dx[i],yy=y+dy[i];
			if(xx>=0&&xx<=n&&yy>=0&&yy<=m)
			{
				if(st[i]!=mp[x+ix[i]][y+iy[i]])
				{
					int t=vis[x][y]+1;
					if(t<vis[xx][yy])
					{
						q.push_back({xx,yy});
						vis[xx][yy]=t;
					}
				}
				else
				{
					int t=vis[x][y];
					if(t<vis[xx][yy])
					{
						q.push_front({xx,yy});
						vis[xx][yy]=t;
					}
				}
			}
		}
	}
	write(vis[n][m]);
}
int main()
{
	n=read(),m=read();
	for(int i=0;i<n;++i)scanf("%s",mp[i]);
	if((m+n)&1)puts("NO SOLUTION");
	else bfs();
	return 0;
}
