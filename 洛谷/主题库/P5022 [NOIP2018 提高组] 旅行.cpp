#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^'0'),ch=getchar();
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
	int from,to,nxt;
}edge[5010];
int x,y,n,m,cnt,tot,hd[5010],ans[5010],tans[5010];
bool vis[5010];
vector<int>mp[5010];
inline void addedge(int u,int v)
{
	edge[++tot].from=u;
	edge[tot].to=v;
	edge[tot].nxt=hd[u];
	hd[u]=tot;
}
void dfs0(int pos,int fa)
{
	if(vis[pos])return;
	vis[pos]=1;
	ans[++cnt]=pos;
	for(auto v:mp[pos])
	{
		if(v==fa)continue;
		dfs0(v,pos);
	}
}
void dfs1(int pos,int fa)
{
	if(vis[pos])return;
	vis[pos]=1;
	tans[++cnt]=pos;
	for(auto v:mp[pos])
	{
		if(v==fa)continue;
		if(max(x,y)==max(pos,v)&&min(x,y)==min(pos,v))continue;
		dfs1(v,pos);
	}
}
int main()
{
	n=read(),m=read();
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		mp[u].emplace_back(v);
		mp[v].emplace_back(u);
		addedge(u,v);
	}
	for(int i=1;i<=n;++i)sort(mp[i].begin(),mp[i].end());
	if(m<n)dfs0(1,0);
	else
	{
		for(int i=1;i<=m;++i)
		{
			cnt=0,x=edge[i].from,y=edge[i].to;
			memset(vis,0,sizeof vis);
			dfs1(1,0);
			bool fg=0;
			for(int i=1;i<=n;++i)
			{
				if(!ans[i]){fg=1;break;}
				if(ans[i]<tans[i]){fg=0;break;}
				else if(ans[i]>tans[i]){fg=1;break;}
			}
			if(fg)swap(ans,tans);
		}
	} 
	for(int i=1;i<=n;++i)
		write(ans[i]),putchar(' ');
	return 0;
}

