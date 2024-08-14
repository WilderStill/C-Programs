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
int m,n,b[3010][3010],a[3010][3010],tim[3010];long long dis[3010];
bool vis[3010];
vector<pair<int,int>>edge[6010];
bool dijkstra(int s)
{
	deque<int>q;
	memset(tim,0,sizeof(tim));
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f3f3f3f,sizeof(dis));
	dis[1]=0;
	q.push_back(1);
	while(!q.empty())
	{
		int top=q.front();
		q.pop_front();
		++tim[top];
		vis[top]=0;
		if(tim[top]>n+m)return 1;
		for(int i=0;i<edge[top].size();++i)
		{
			int v=edge[top][i].first,size=edge[top][i].second;
			if(dis[v]>dis[top]+size)
			{
				dis[v]=dis[top]+size;
				if(!vis[v])
				{
					if(!q.empty()&&dis[v]<dis[q.front()])q.push_front(v);
					else q.push_back(v);
					vis[v]=1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	int T=read();
	while(T--)
	{
		n=read(),m=read();
		for(int i=1;i<n;++i)
			for(int j=1;j<m;++j)
				b[i][j]=read();
		for(int i=1;i<=n;++i)a[i][m]=0;
		for(int i=1;i<=m;++i)a[n][i]=0;
		for(int i=n-1;i;--i)
			for(int j=m-1;j;--j)
				a[i][j]=b[i][j]-a[i+1][j]-a[i][j+1]-a[i+1][j+1];
		for(int i=1;i<=n+m;++i)edge[i].clear();
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				int maxn=1000000-a[i][j],minn=a[i][j];
				if((i+j)&1)edge[j+n].push_back({i,minn}),edge[i].push_back({j+n,maxn});
				else edge[j+n].push_back({i,maxn}),edge[i].push_back({j+n,minn});
			}
		if(dijkstra(1))
		{
			puts("NO");
			continue;
		}
		for(int i=1;i<=n;++i)
			for(int j=1;j<=m;++j)
			{
				if((i+j)&1)a[i][j]+=(dis[j+n]-dis[i]);
				else a[i][j]-=(dis[j+n]-dis[i]);
			}
		puts("YES");
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=m;++j)
				write(a[i][j]),putchar(' ');
			puts("");
		}
	}
	return 0;
}

