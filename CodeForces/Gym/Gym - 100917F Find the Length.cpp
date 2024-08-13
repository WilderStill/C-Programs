#include<bits/stdc++.h>
#define ll long long
#define INF 0x3f3f3f3f
using namespace std;
inline ll read()
{
    ll x=0,f=1;
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
inline void write(ll x)
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
int n,dis[1040],vis[1040],ans[1040],fa[1040],edge[1040][1040];
int findfa(int x)
{
	return fa[x]==x?fa[x]:fa[x]=findfa(fa[x]);
}
void dijkstra(int s)
{
    for(int i=1;i<=n;++i)dis[i]=INF,vis[i]=0,fa[i]=i;
    priority_queue<pair<ll,ll>>q;
    q.push({0,s});
    dis[s]=0;
    while(!q.empty())
	{
        auto top=q.top();
        q.pop();
        if(vis[top.second])continue;
        vis[top.second]=1;
        for(int i=1;i<=n;++i)
		{
            if(edge[top.second][i]>0&&edge[top.second][i]-top.first<dis[i])
			{
                dis[i]=edge[top.second][i]-top.first;
                if(top.second!=s)fa[i]=top.second;
                q.push({-dis[i],i});
            }
        }
    }
    for(int i=1;i<=n;++i)
        if(fa[i]!=i&&edge[s][i]>0)ans[s]=min(ans[s],dis[i]+edge[s][i]);
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
            if(i!=s&&j!=s&&edge[i][j]>0&&findfa(i)!=findfa(j))
				ans[s]=min(ans[s],dis[i]+dis[j]+edge[i][j]);
}
int main()
{
	memset(ans,0x3f,sizeof ans);
    n=read();
    for(int i=1;i<=n;++i)
        for(int j=1;j<=n;++j)
			edge[i][j]=read();
    for(int i=1;i<=n;++i)dijkstra(i);
    for(int i=1;i<=n;++i)
	{
        if(ans[i]>=INF)puts("-1");
		else write(ans[i]),puts("");
    }
    return 0;
}
