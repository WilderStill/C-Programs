#include<bits/stdc++.h>
#define M 500010
#define INF 0x3f3f3f3f
#define ll long long
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
unordered_map<int,bool>vis;
unordered_map<int,ll>dis;
int n,m,l[M],c[M];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
void dijkstra()
{
    q.push({0,0});
    dis[0]=0;
    while(!q.empty())
	{
        auto top=q.top();
        int u=top.second;
        q.pop();
        if(u==1)break;
        if(vis.find(u)!=vis.end())continue;
        vis[u]=1;
        for(int i=1;i<=n;++i)
		{
            int v=__gcd(u,l[i]);
            if(dis.find(v)==dis.end())dis[v]=INF;
            if(dis[v]>dis[u]+c[i])
			{
                dis[v]=dis[u]+c[i];
                q.push({dis[v],v});
            }
        }
    }
}
int main()
{
    n=read();
    for(int i=1;i<=n;++i)l[i]=read();
    for(int i=1;i<=n;++i)c[i]=read();
    dijkstra();
    if(dis.find(1)==dis.end())puts("-1");
    else write(dis[1]);
    return 0;
}
