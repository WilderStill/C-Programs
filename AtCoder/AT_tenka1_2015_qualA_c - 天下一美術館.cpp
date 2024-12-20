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
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+48);
    return;
}
const int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
int n,m,cnt,ans,a[101][101],b[101][101],idx[101][101],match[10010],x[10010],y[10010];
vector<int>mp[10010];
bool vis[10010];
bool found(int x)
{
    vis[x]=1;
    for(auto to:mp[x])
    {
    	if(!match[to]||!vis[match[to]]&&found(match[to]))
		{
            match[to]=x;
            return 1;
        }
	}  
    return 0;
}
int main()
{
    n=read(),m=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            a[i][j]=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            b[i][j]=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(a[i][j]^b[i][j])
			{
                idx[i][j]=++cnt;
                x[cnt]=i,y[cnt]=j;
            }
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            if(idx[i][j]&&a[i][j])
                for(int k=0;k<4;++k)
                {
                    int xx=i+dx[k],yy=j+dy[k];
                    if(idx[xx][yy]&&!a[xx][yy])mp[idx[i][j]].push_back(idx[xx][yy]);
                }
    for(int i=1;i<=cnt;++i)
        if(a[x[i]][y[i]])
		{
            memset(vis,0,sizeof vis);
            ans+=found(i);
        }
    write(cnt-ans);
    puts("");
    return 0;
}
