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
int dis[200010],vis[200010];
vector<pair<int,int>>mp[200002];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>q;
int main()
{
    int n=read(),m=read();
    for(int i=1;i<=m;++i)
	{
		int u=read(),v=read(),w=read();
        mp[u].push_back({v-u+1-w,v+1});
    }
    for(int i=0;i<=n;++i)
	{
        mp[i+1].push_back({0,i});
        mp[i].push_back({1,i+1});
    }
    memset(dis,0x3f,sizeof dis);
    dis[0]=0;
    q.push({0,0});
    while(!q.empty())
	{
        int top=q.top().second;
        q.pop();
        if(vis[top])continue;
        vis[top]=1;
        for(auto i:mp[top])
            if(dis[i.second]>dis[top]+i.first)
			{
                dis[i.second]=dis[top]+i.first;
                q.push({dis[i.second],i.second});
            }
    }
    for(int i=1;i<=n;++i)
	{
		write(!(dis[i+1]-dis[i]));
		putchar(' ');
	}
	return 0;
}
