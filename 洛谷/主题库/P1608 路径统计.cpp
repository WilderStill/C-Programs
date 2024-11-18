#include<bits/stdc++.h>
#define int long long
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
int tot,j,k;
struct
{
	int nxt,to,val;
}edge[4000010];
int hd[2010],dis[2010],ans[2010];
bool mp[2010][2010],vis[2010];
priority_queue<pair<int,int>>q;
inline void addedge(int u,int v,int w)
{
	edge[++tot].to=v;
	edge[tot].nxt=hd[u];
	edge[tot].val=w;
	hd[u]=tot;
}
signed main()
{
	int n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
		if(!mp[u][v])
		{
			mp[u][v]=1;
			addedge(u,v,w);
		}
		else
		{
			for(int i=hd[u];i;i=edge[i].nxt)
				if(edge[i].to==v)
				{
					edge[i].val=min(edge[i].val,w);
					break;
				}
		}
	}
	for(int i=2;i<=n;++i)dis[i]=0x3f3f3f3f;
	ans[1]=1;
	q.push({0,1});
	while(!q.empty())
	{
		int tp=q.top().second;
		q.pop();
		if(vis[tp])continue;
		vis[tp]=1;
		for(int i=hd[tp];i;i=edge[i].nxt)
		{
			int to=edge[i].to,val=edge[i].val;
			if(dis[to]>dis[tp]+val)
			{
				dis[to]=dis[tp]+val;
				q.push({-dis[to],to});
				ans[to]=0;
			}
			if(dis[to]==dis[tp]+val)ans[to]+=ans[tp];
		}
	}
	if(dis[n]==0x3f3f3f3f)puts("No answer");
	else write(dis[n]),putchar(' '),write(ans[n]);
	return 0;	
} 
