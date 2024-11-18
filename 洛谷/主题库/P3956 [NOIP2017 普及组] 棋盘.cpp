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
inline void file()
{
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
}
const int INF=0x3f3f3f3f,dx[]={0,1,0,-1,1,1,-1,-1,0,2,0,-2},dy[]={1,0,-1,0,1,-1,1,-1,2,0,-2,0},dw[]={0,0,0,0,2,2,2,2,2,2,2,2};
struct node
{
	int x,y,c,w; 
	bool operator<(const node b)const{return w>b.w;}
};
priority_queue<node>q;
int mp[110][110],dis[110][110];
int main()
{
	int m=read(),n=read();
	for(int i=1;i<=n;++i)
	{
		int s=read(),y=read(),h=read();
		mp[s][y]=h+1;
	}
	memset(dis,0x3f,sizeof dis);
	dis[1][1]=0;
	q.push({1,1,mp[1][1],dis[1][1]});
	while(!q.empty())
	{
		auto top=q.top();
		int x=top.x,y=top.y,c=top.c,w=top.w;
		q.pop();
		if(dis[x][y]<w)continue;
		for(int i=0;i<12;++i)
		{
			int xx=x+dx[i],yy=y+dy[i],cc=mp[xx][yy],ww=w+dw[i];
            if(xx<=0||xx>m||yy<=0||yy>m||!cc)continue;
			if(c^cc)++ww;
			if(dis[xx][yy]>ww)
			{
				dis[xx][yy]=ww;
				q.push({xx,yy,cc,ww});
			}
		}
	}
	int ans=mp[m][m]?dis[m][m]:min(dis[m][m-1],dis[m-1][m])+2;
	write(ans>=INF?-1:ans);
	return 0;
}
